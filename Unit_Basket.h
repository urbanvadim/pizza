//---------------------------------------------------------------------------
#ifndef Unit_BasketH
#define Unit_BasketH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.DBCGrids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Unit_DataModule.h>
#include <map>
//---------------------------------------------------------------------------
class TForm_Basket : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit_Name;
	TEdit *Edit_Phone;
	TEdit *Edit_Address;
	TLabel *Label_TotalSum;
	TLabel *Label1;
	TDBCtrlGrid *DBCtrlGrid;
	TImage *Image_Basket;
	TDBText *DBText1;
	TDBText *DBText2;
	TDBText *DBText4;
	TLabel *Label2;
	TShape *Shape1;
	TLabel *Label3;
	TShape *Shape3;
	TLabel *Label_Order;
	TShape *Shape2;
	TLabel *Label5;
	TDBText *DBText3;
	TShape *Shape4;
	TShape *Shape5;
	TLabel *Button_Plus;
	TLabel *Button_Minus;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DBCtrlGridPaintPanel(TDBCtrlGrid *DBCtrlGrid, int Index);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled);
	void __fastcall Label3Click(TObject *Sender);
	void __fastcall Label5Click(TObject *Sender);
	void __fastcall Label_OrderClick(TObject *Sender);
	void __fastcall Button_PlusClick(TObject *Sender);
	void __fastcall Button_MinusClick(TObject *Sender);
private:
	std::map<String, TPicture*> ImageCache;	// User declarations
public:		// User declarations
	__fastcall TForm_Basket(TComponent* Owner);
	void UpdateTotal();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Basket *Form_Basket;
//---------------------------------------------------------------------------
#endif
