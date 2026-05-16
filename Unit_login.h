//---------------------------------------------------------------------------

#ifndef Unit_loginH
#define Unit_loginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm_Login : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit_Login;
	TEdit *Edit_Pass;
	TButton *Btn_Login;
	TButton *Btn_Reg;
	TLabel *Label1;
	TLabel *Label2;
	TCheckBox *Check_Remember;
	TSpeedButton *SpeedButton1;
	TLabel *BtnGuest;
	void __fastcall Btn_RegClick(TObject *Sender);
	void __fastcall Btn_LoginClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall SpeedButton1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall SpeedButton1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall BtnGuestClick(TObject *Sender);

private:
	bool isFirstShow;
public:

	__fastcall TForm_Login(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Login *Form_Login;
//---------------------------------------------------------------------------
#endif
