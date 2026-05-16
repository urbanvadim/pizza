//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit_login.h"
#include "Unit_Splash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Splash *Form_Splash;
//---------------------------------------------------------------------------
__fastcall TForm_Splash::TForm_Splash(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_Splash::Timer1Timer(TObject *Sender)
{
ProgressBar1->Position += 2;

	if (ProgressBar1->Position >= 100) {
		Timer1->Enabled = false;
		this->Hide();
		Form_Login->Show();
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm_Splash::FormShow(TObject *Sender)
{
	String logoPath = ExtractFilePath(Application->ExeName) + "Img\\logo.png";

    // Перевіряємо, чи ти не провтикав закинути файл у папку
    if (FileExists(logoPath)) {
        // УВАГА: Якщо твій TImage називається інакше (напр. Image_Logo), зміни назву тут!
        Image1->Picture->LoadFromFile(logoPath);
    } else {
        // Робимо захист від дурня: якщо файлу нема, програма хоча б скаже де вона його шукала
        ShowMessage("Логотип не знайдено за шляхом:\n" + logoPath);
	}
}
//---------------------------------------------------------------------------

