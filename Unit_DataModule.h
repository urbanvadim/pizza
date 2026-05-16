//---------------------------------------------------------------------------

#ifndef Unit_DataModuleH
#define Unit_DataModuleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TADOTable *Table_Pizzas;
	TADOTable *Table_Clients;
	TADOTable *Table_Ingredients;
	TADOTable *Table_PizzaIngredients;
	TADOTable *Table_Orders;
	TADOTable *Table_OrderDetails;
	TADOTable *Table_Employees;
	TADOTable *Pizza_constructor;
	TADOQuery *Query_Execute;
	TDataSource *Source_Pizzas;
	TADOTable *Table_Basket;
	TDataSource *Source_Basket;
	TIntegerField *Table_PizzasID;
	TWideStringField *Table_PizzasÑêëàä;
	TBCDField *Table_PizzasÖ³íà;
	TWideStringField *Table_PizzasÊàòåãîğ³ÿ;
	TWideStringField *Table_PizzasÂàãà;
	TADOQuery *Query_Ingredients;
	TAutoIncField *Table_OrderDetailsID;
	TIntegerField *Table_OrderDetailsID_çàìîâëåííÿ;
	TWideStringField *Table_OrderDetailsÍàçâà_ï³öè;
	TWideStringField *Table_OrderDetailsÖ³íà_çà_øòóêó;
	TWideStringField *Table_OrderDetailsÑêëàä;
	TWideStringField *Table_OrderDetailsÊ³ëüê³ñòü;
	TAutoIncField *Table_OrdersID;
	TIntegerField *Table_OrdersID_Êë³ºíòà;
	TBCDField *Table_OrdersÑóìà;
	TDateTimeField *Table_Orders×àñ_çàìîâëåííÿ;
	TIntegerField *Table_Orders²D_ïğàö³âíèêà;
	TBCDField *Table_OrdersÑóìà_äî_îïëàòè;
	TAutoIncField *Table_ClientsID;
	TWideStringField *Table_ClientsÏ²Á_Êë³ºíòà;
	TWideStringField *Table_ClientsÒåëåôîí;
	TWideStringField *Table_ClientsÀäğåñà_äîñòàâêè;
	TWideStringField *Table_ClientsËîã³í;
	TWideStringField *Table_ClientsÏàğîëü;
	TIntegerField *Table_ClientsÁîíóñè;
	TDataSource *Source_Orders;
	TDataSource *Source_Details;
	TWideStringField *Table_PizzasÍàçâà_ï³öè;
	TWideStringField *Table_PizzasÔîòî;
	TWideStringField *Table_OrderDetailsÔîòî;
	TAutoIncField *Table_BasketID;
	TWideStringField *Table_BasketÍàçâà_ï³öè;
	TWideStringField *Table_BasketÑêëàä;
	TBCDField *Table_BasketÖ³íà;
	TWideStringField *Table_BasketËîã³í;
	TIntegerField *Table_BasketÊ³ëüê³ñòü;
	TWideStringField *Table_BasketÔîòî_Ôàéë;
private:	// User declarations
public:
	int CurrentClientID;
	String CurrentClientName;
	String CurrentClientPhone;
	String CurrentClientAddress;
	int CurrentClientBonuses;
	float TotalSum;
	__fastcall TDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
