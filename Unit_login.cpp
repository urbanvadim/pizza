//---------------------------------------------------------------------------
#include "Unit_DataModule.h"
#include <Registry.hpp>
#include <IniFiles.hpp>
#include "Unit_Reg.h"
#include "Unit_login.h"
#include "Unit_Menu.h"
#include <vcl.h>
#pragma hdrstop

#include "Unit_login.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Login *Form_Login;
//---------------------------------------------------------------------------
__fastcall TForm_Login::TForm_Login(TComponent* Owner)
	: TForm(Owner)
{
	isFirstShow = true;
	randomize();
}
//---------------------------------------------------------------------------
void __fastcall TForm_Login::Btn_RegClick(TObject *Sender)
{
	Form_Reg->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm_Login::Btn_LoginClick(TObject *Sender)
{
	DM->Query_Execute->Close();
	DM->Query_Execute->SQL->Clear();

	DM->Query_Execute->SQL->Add("SELECT * FROM Клієнти WHERE Логін = '" + Edit_Login->Text + "' AND Пароль = '" + Edit_Pass->Text + "'");

	try {
		DM->Query_Execute->Open();
	} catch (Exception &e) {
		ShowMessage("Помилка підключення: " + e.Message);
		return;
	}


	if (!DM->Query_Execute->Eof) {

		DM->CurrentClientID = DM->Query_Execute->FieldByName("ID")->AsInteger;
		DM->CurrentClientName = DM->Query_Execute->FieldByName("ПІБ_Клієнта")->AsString;
		DM->CurrentClientPhone = DM->Query_Execute->FieldByName("Телефон")->AsString;
		DM->CurrentClientAddress = DM->Query_Execute->FieldByName("Адреса_доставки")->AsString;
		DM->CurrentClientBonuses = DM->Query_Execute->FieldByName("Бонуси")->AsInteger;
		if (Check_Remember->Checked) {

    TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "settings.ini");
    ini->WriteString("Auth", "Login", Edit_Login->Text);
    ini->WriteString("Auth", "Password", Edit_Pass->Text);
    ini->WriteBool("Auth", "Remember", true);
	delete ini;
} else {

    if (FileExists(ExtractFilePath(Application->ExeName) + "settings.ini")) {
        DeleteFile(ExtractFilePath(Application->ExeName) + "settings.ini");
    }
}
		this->Hide();
		Form_Menu->Show();
	} else {
		ShowMessage("Невірний логін або пароль!");
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm_Login::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------



void __fastcall TForm_Login::FormActivate(TObject *Sender)
{
    if (isFirstShow) {
        isFirstShow = false;

        String path = ExtractFilePath(Application->ExeName) + "settings.ini";
        if (FileExists(path)) {
			TIniFile *ini = new TIniFile(path);
			String savedLogin = ini->ReadString("Auth", "Login", "");
			String savedPass = ini->ReadString("Auth", "Password", "");
            bool remember = ini->ReadBool("Auth", "Remember", false);
            delete ini;

            if (remember && savedLogin != "" && savedPass != "") {
                Edit_Login->Text = savedLogin;
                Edit_Pass->Text = savedPass;
				Check_Remember->Checked = true;

                PostMessage(Btn_Login->Handle, WM_LBUTTONDOWN, 0, 0);
                PostMessage(Btn_Login->Handle, WM_LBUTTONUP, 0, 0);
            }
        }
	}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm_Login::SpeedButton1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
   Edit_Pass->PasswordChar = '*';
}
//---------------------------------------------------------------------------

void __fastcall TForm_Login::SpeedButton1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	Edit_Pass->PasswordChar = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Login::BtnGuestClick(TObject *Sender)
{
	String filePath = ExtractFilePath(Application->ExeName) + "settings.ini";
	TIniFile *ini = new TIniFile(filePath);
	try
	{
		ini->WriteString("Auth", "Login", "Guest");
		ini->WriteString("Auth", "Password", "");
		ini->WriteBool("Auth", "Remember", false);
	}
	__finally
	{
		delete ini;
	}
	Form_Menu->Show();
	this->Hide();
}
//---------------------------------------------------------------------------

