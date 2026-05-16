//---------------------------------------------------------------------------

#ifndef Unit_RegH
#define Unit_RegH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm_Reg : public TForm
{
__published:
	TEdit *Edit_RegName;
	TEdit *Edit_RegPhone;
	TEdit *Edit_RegAddress;
	TEdit *Edit_RegLogin;
	TEdit *Edit_RegPass;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TButton *Btn_SaveReg;
	void __fastcall Btn_SaveRegClick(TObject *Sender);
	void __fastcall Edit_RegNameKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit_RegPhoneKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TForm_Reg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Reg *Form_Reg;
//---------------------------------------------------------------------------
#endif
