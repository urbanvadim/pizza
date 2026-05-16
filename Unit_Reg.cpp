//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit_Reg.h"
#include "Unit_DataModule.h"
#include "Unit_login.h"
#include <System.Character.hpp>

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Reg *Form_Reg;
//---------------------------------------------------------------------------
__fastcall TForm_Reg::TForm_Reg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_Reg::Btn_SaveRegClick(TObject *Sender)
{
	if (Edit_RegLogin->Text == "" || Edit_RegPass->Text == "" || Edit_RegPhone->Text == "" || Edit_RegName->Text == "" || Edit_RegAddress->Text=="") {
		ShowMessage("Будь ласка, заповніть всі дані!");
		return;
    }

	try {
		DM->Query_Execute->Close();
        DM->Query_Execute->SQL->Clear();
        DM->Query_Execute->SQL->Add("SELECT * FROM Клієнти WHERE Логін = '" + Edit_RegLogin->Text + "'");
        DM->Query_Execute->Open();

		if (!DM->Query_Execute->Eof) {
            String login = Edit_RegLogin->Text;
			int randomNum = random(999) + 10;
            String suggestion = login + String(randomNum);

            if (MessageDlg("Логін '" + login + "' вже зайнятий. Використати '" + suggestion + "'?",
                mtConfirmation, mbYesNo, 0) == mrYes)
            {
                Edit_RegLogin->Text = suggestion;
				return;
            } else {
				return;
			}
		}

        DM->Table_Clients->Append();

        DM->Table_Clients->FieldByName("Логін")->AsString = Edit_RegLogin->Text;
        DM->Table_Clients->FieldByName("Пароль")->AsString = Edit_RegPass->Text;
        DM->Table_Clients->FieldByName("ПІБ_Клієнта")->AsString = Edit_RegName->Text;
        DM->Table_Clients->FieldByName("Телефон")->AsString = Edit_RegPhone->Text;
        DM->Table_Clients->FieldByName("Адреса_доставки")->AsString = Edit_RegAddress->Text;
		DM->Table_Clients->FieldByName("Бонуси")->AsInteger = 0;

        DM->Table_Clients->Post();

	ShowMessage("Реєстрація успішна! Тепер увійдіть у свій акаунт.");

		Form_Login->Edit_Login->Text = "";
		Form_Login->Edit_Pass->Text = "";

		this->Close();
    }
    catch (Exception &e) {
		ShowMessage("Помилка: " + e.Message);
		DM->Table_Clients->Cancel();
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm_Reg::Edit_RegNameKeyPress(TObject *Sender, System::WideChar &Key)

{
	if (!IsLetter(Key) && Key != ' ' && Key != '\b' && Key != '-')
    {
		Key = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Reg::Edit_RegPhoneKeyPress(TObject *Sender, System::WideChar &Key)

{
    if (!TCharacter::IsDigit(Key) && Key != '+' && Key != '\b')
	{
		Key = 0;
	}
}
//---------------------------------------------------------------------------

