//---------------------------------------------------------------------------

#ifndef Unit_SplashH
#define Unit_SplashH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm_Splash : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TProgressBar *ProgressBar1;
	TTimer *Timer1;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm_Splash(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Splash *Form_Splash;
//---------------------------------------------------------------------------
#endif
