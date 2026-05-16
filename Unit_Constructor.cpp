//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit_Constructor.h"
#include "Unit_Menu.h"
#include <System.IniFiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Constructor *Form_Constructor;
//---------------------------------------------------------------------------
__fastcall TForm_Constructor::TForm_Constructor(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_Constructor::FormShow(TObject *Sender)
{
    RadioGroup_Dough->Items->Clear();
    RadioGroup_Sauce->Items->Clear();
    CheckListBox_Ingredients->Items->Clear();
    Prices_Dough.clear();
    Prices_Sauce.clear();
    Prices_Ingredients.clear();


	DM->Query_Ingredients->Close();
	DM->Query_Ingredients->SQL->Text = "SELECT * FROM Інградієнти_Конструктор ORDER BY Категорія, Ціна";
    DM->Query_Ingredients->Open();

    while(!DM->Query_Ingredients->Eof)
    {
        String name = DM->Query_Ingredients->FieldByName("Назва")->AsString;
        double price = DM->Query_Ingredients->FieldByName("Ціна")->AsFloat;
        String category = DM->Query_Ingredients->FieldByName("Категорія")->AsString;


		String displayText = name + " (" + FloatToStr(price) + " грн)";


        if (category == "Основа") {
            RadioGroup_Dough->Items->Add(displayText);
			Prices_Dough.push_back(price);
		}
        else if (category == "Соуси") {
            RadioGroup_Sauce->Items->Add(displayText);
            Prices_Sauce.push_back(price);
        }
        else {
			CheckListBox_Ingredients->Items->Add(displayText);
			Prices_Ingredients.push_back(price);
        }

        DM->Query_Ingredients->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Constructor::Btn_menuClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Constructor::Button_AddToCartClick(TObject *Sender)
{
    if (RadioGroup_Dough->ItemIndex == -1 || RadioGroup_Sauce->ItemIndex == -1) {
        ShowMessage("Помилка: Виберіть основу та соус!");
        return;
    }


    String fullComp = "";
    fullComp += RadioGroup_Dough->Items->Strings[RadioGroup_Dough->ItemIndex];
    fullComp += ", " + RadioGroup_Sauce->Items->Strings[RadioGroup_Sauce->ItemIndex];

    for (int i = 0; i < CheckListBox_Ingredients->Count; i++) {
        if (CheckListBox_Ingredients->Checked[i]) {
            fullComp += ", " + CheckListBox_Ingredients->Items->Strings[i];
        }
    }


    double finalPrice = 0;
    finalPrice += Prices_Dough[RadioGroup_Dough->ItemIndex];
    finalPrice += Prices_Sauce[RadioGroup_Sauce->ItemIndex];
    for (int i = 0; i < CheckListBox_Ingredients->Count; i++) {
        if (CheckListBox_Ingredients->Checked[i]) finalPrice += Prices_Ingredients[i];
    }


	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "settings.ini");
    String user = ini->ReadString("Auth", "Login", "Guest");
    delete ini;


	try {
        DM->Table_Basket->Append();
        DM->Table_Basket->FieldByName("Назва_піци")->AsString = "Піца з конструктора";
        DM->Table_Basket->FieldByName("Ціна")->AsFloat = finalPrice;
        DM->Table_Basket->FieldByName("Кількість")->AsInteger = 1;
        DM->Table_Basket->FieldByName("Логін")->AsString = user;
		DM->Table_Basket->FieldByName("Склад")->AsString = fullComp;
        DM->Table_Basket->FieldByName("Фото_Файл")->AsString = "custom_pizza.jpg";
        DM->Table_Basket->Post();

        ShowMessage("Кастомну піцу успішно додано до кошика!");
		this->Close();
    }
    catch (Exception &e) {
        ShowMessage("Помилка при збереженні в базу: " + e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm_Constructor::UpdateTotal()
{
    double currentTotal = 0;

    if (RadioGroup_Dough->ItemIndex != -1)
        currentTotal += Prices_Dough[RadioGroup_Dough->ItemIndex];

    if (RadioGroup_Sauce->ItemIndex != -1)
        currentTotal += Prices_Sauce[RadioGroup_Sauce->ItemIndex];

    for (int i = 0; i < CheckListBox_Ingredients->Count; i++) {
        if (CheckListBox_Ingredients->Checked[i])
            currentTotal += Prices_Ingredients[i];
    }

    Label_TotalPrice->Caption = FloatToStrF(currentTotal, ffFixed, 8, 2) + " грн";
}
void __fastcall TForm_Constructor::RadioGroup_DoughClick(TObject *Sender)
{
    UpdateTotal();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Constructor::RadioGroup_SauceClick(TObject *Sender)
{
    UpdateTotal();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Constructor::CheckListBox_IngredientsClick(TObject *Sender)

{
	UpdateTotal();
}
//---------------------------------------------------------------------------

