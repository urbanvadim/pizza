//---------------------------------------------------------------------------

#ifndef Unit_HistoryH
#define Unit_HistoryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.DBCGrids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm_History : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape1;
	TLabel *Button_CloseHistory;
	TDBCtrlGrid *DBCtrlGrid1;
	TImage *Image1;
	TDBText *DBText1;
	TDBText *DBText4;
	TLabel *Label_Date;
	TLabel *Label_Time;
	TLabel *Label1;
	TShape *Shape2;
	TLabel *Button_Details;
	TPanel *Panel_OrderDetails;
	TShape *Shape3;
	TLabel *Panel_close;
	TDBCtrlGrid *DBCtrlGrid_Details;
	TImage *Image_PizzaDetail;
	TDBText *DBText2;
	TDBText *DBText3;
	TDBText *DBText5;
	TDBText *DBText6;
	TLabel *Label2;
	TLabel *Label3;
	void __fastcall Button_CloseHistoryClick(TObject *Sender);
	void __fastcall DBCtrlGrid1PaintPanel(TDBCtrlGrid *DBCtrlGrid, int Index);
	void __fastcall Panel_closeClick(TObject *Sender);
	void __fastcall Button_DetailsClick(TObject *Sender);
	void __fastcall DBCtrlGrid_DetailsPaintPanel(TDBCtrlGrid *DBCtrlGrid, int Index);
	void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
		  bool &Handled);
	void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
private:	// User declarations
public:		// User declarations
	__fastcall TForm_History(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_History *Form_History;
//---------------------------------------------------------------------------
#endif
