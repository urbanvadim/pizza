//---------------------------------------------------------------------------

#ifndef Unit_MenuH
#define Unit_MenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCGrids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Buttons.hpp>
#include <map>
//---------------------------------------------------------------------------
class TForm_Menu : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit_Search;
	TDBCtrlGrid *DBCtrlGrid1;
	TPopupMenu *PopupMenu_Account;
	TMenuItem *MenuItem_SettingsClick;
	TPanel *Panel_Account;
	TLabel *Label4;
	TLabel *Label_ClosePanel;
	TButton *Button_Logout;
	TLabel *Label_Hamburger;
	TButton *Button_Basket;
	TImage *Image_Pizza;
	TDBText *DBText5;
	TDBText *DBText6;
	TDBText *DBText1;
	TDBText *DBText2;
	TLabel *Label2;
	TLabel *Label3;
	TShape *Shape1;
	TLabel *Label5;
	TButton *Btn_OpenConstructor;
	TMenuItem *AccountPopup;
	TLabel *Label_AccName;
	TLabel *Label_AccPhone;
	TLabel *Label_AccAddress;
	TLabel *Label_AccLogin;
	TButton *Button_GoToLogin;
	TPanel *Panel_Settings;
	TLabel *Label_CloseSettings;
	TEdit *Edit_EditName;
	TEdit *Edit_EditPhone;
	TButton *Button_SaveSettings;
	TEdit *Edit_EditAddress;
	TEdit *Edit_NewPassword;
	TSpeedButton *SpeedButton_ShowPass;
	TLabel *Label1;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TMenuItem *MenuItem_History;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Edit_SearchChange(TObject *Sender);
	void __fastcall Btn_AddClick(TObject *Sender);
	void __fastcall DBCtrlGrid1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall DBCtrlGrid1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
		  TPoint &MousePos, bool &Handled);
	void __fastcall AccountPopupClick(TObject *Sender);
	void __fastcall Button_LogoutClick(TObject *Sender);
	void __fastcall Label_HamburgerClick(TObject *Sender);
	void __fastcall Label_ClosePanelClick(TObject *Sender);
	void __fastcall BtnAddClick(TObject *Sender);
	void __fastcall Button_BasketClick(TObject *Sender);
	void __fastcall DBCtrlGrid1PaintPanel(TDBCtrlGrid *DBCtrlGrid, int Index);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Btn_OpenConstructorClick(TObject *Sender);
	void __fastcall Button_GoToLoginClick(TObject *Sender);
	void __fastcall MenuItem_SettingsClickClick(TObject *Sender);
	void __fastcall Button_SaveSettingsClick(TObject *Sender);
	void __fastcall SpeedButton_ShowPassClick(TObject *Sender);
	void __fastcall Label_CloseSettingsClick(TObject *Sender);
	void __fastcall MenuItem_HistoryClick(TObject *Sender);
private:
	std::map<String, TPicture*> ImageCache;
public:

	__fastcall TForm_Menu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Menu *Form_Menu;
//---------------------------------------------------------------------------
#endif
