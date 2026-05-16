//---------------------------------------------------------------------------

#ifndef Unit_ConstructorH
#define Unit_ConstructorH
#include <System.Classes.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
#include "Unit_DataModule.h"
#include <vector>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm_Constructor : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *RadioGroup_Dough;
	TRadioGroup *RadioGroup_Sauce;
	TLabel *Label_TotalPrice;
	TButton *Button_AddToCart;
	TLabel *Label1;
	TButton *Btn_menu;
	TCheckListBox *CheckListBox_Ingredients;
	TLabel *Label2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Btn_menuClick(TObject *Sender);
	void __fastcall Button_AddToCartClick(TObject *Sender);
	void __fastcall RadioGroup_DoughClick(TObject *Sender);
	void __fastcall RadioGroup_SauceClick(TObject *Sender);
	void __fastcall CheckListBox_IngredientsClick(TObject *Sender);
private:
	std::vector<double> Prices_Dough;
	std::vector<double> Prices_Sauce;
	std::vector<double> Prices_Ingredients;
	void __fastcall UpdateTotal();	// User declarations
public:		// User declarations
	__fastcall TForm_Constructor(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Constructor *Form_Constructor;
//---------------------------------------------------------------------------
#endif
