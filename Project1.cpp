//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Unit_login.cpp", Form_Login);
USEFORM("Unit_Menu.cpp", Form_Menu);
USEFORM("Unit_Reg.cpp", Form_Reg);
USEFORM("Unit_Splash.cpp", Form_Splash);
USEFORM("Unit_DataModule.cpp", DM); /* TDataModule: File Type */
USEFORM("Unit_Basket.cpp", Form_Basket);
USEFORM("Unit_Constructor.cpp", Form_Constructor);
USEFORM("Unit_History.cpp", Form_History);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TDM), &DM);
		Application->CreateForm(__classid(TForm_Splash), &Form_Splash);
		Application->CreateForm(__classid(TForm_Login), &Form_Login);
		Application->CreateForm(__classid(TForm_Reg), &Form_Reg);
		Application->CreateForm(__classid(TForm_Menu), &Form_Menu);
		Application->CreateForm(__classid(TForm_Basket), &Form_Basket);
		Application->CreateForm(__classid(TForm_Constructor), &Form_Constructor);
		Application->CreateForm(__classid(TForm_History), &Form_History);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
