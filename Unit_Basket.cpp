//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pnglang.hpp>
#include <System.IniFiles.hpp>
#include "Unit_Basket.h"
#include "Unit_DataModule.h"
#include <vcl.h>
#pragma hdrstop
#include <Vcl.Imaging.jpeg.hpp>
#include <System.IniFiles.hpp>
#include "Unit_Basket.h"
#include <Data.DB.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Basket *Form_Basket;
//---------------------------------------------------------------------------
__fastcall TForm_Basket::TForm_Basket(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_Basket::FormShow(TObject *Sender)
{
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "settings.ini");
    String currentLog = ini->ReadString("Auth", "Login", "Guest");
    delete ini;


	DM->Table_Basket->Filtered = false;
    DM->Table_Basket->Filter = "Логін = " + QuotedStr(currentLog);
    DM->Table_Basket->Filtered = true;


	if (currentLog != "Guest")
    {

		if (DM->Table_Clients->Locate("Логін", currentLog, TLocateOptions()))
        {
			Edit_Name->Text = DM->Table_Clients->FieldByName("ПІБ_Клієнта")->AsString;
			Edit_Phone->Text = DM->Table_Clients->FieldByName("Телефон")->AsString;
			Edit_Address->Text = DM->Table_Clients->FieldByName("Адреса_доставки")->AsString;

		}
    }
    else
    {

        Edit_Name->Text = "";
		Edit_Phone->Text = "";
        Edit_Address->Text = "";
	}
	UpdateTotal();
}
//---------------------------------------------------------------------------
void TForm_Basket::UpdateTotal()
{
    double total = 0;


    DM->Table_Basket->DisableControls();


    TBookmark savePos = DM->Table_Basket->GetBookmark();

    try {
        DM->Table_Basket->First();
		while (!DM->Table_Basket->Eof) {

			total += DM->Table_Basket->FieldByName("Ціна")->AsFloat * DM->Table_Basket->FieldByName("Кількість")->AsInteger;
			DM->Table_Basket->Next();
		}
	} __finally {

		DM->Table_Basket->GotoBookmark(savePos);
		DM->Table_Basket->FreeBookmark(savePos);
		DM->Table_Basket->EnableControls();
	}


	Label_TotalSum->Caption = FloatToStrF(total, ffNumber, 10, 2) + " грн";
}
void __fastcall TForm_Basket::DBCtrlGridPaintPanel(TDBCtrlGrid *DBCtrlGrid, int Index)

{
TDataSet *ds = DBCtrlGrid->DataSource->DataSet;
	if (!ds || ds->IsEmpty()) return;

	String fName = ds->FieldByName("Фото_Файл")->AsString;
	if (fName.Trim() == "") fName = "no_photo.jpg";

	String path = ExtractFilePath(Application->ExeName) + "Img\\" + fName;
	if (!FileExists(path)) path = ExtractFilePath(Application->ExeName) + "Img\\no_photo.jpg";

	TRect drawRect = Image_Basket->BoundsRect;

	if (FileExists(path)) {
		TPicture *pic = new TPicture();
		try {
			pic->LoadFromFile(path);

			DBCtrlGrid->Canvas->StretchDraw(drawRect, pic->Graphic);

		} catch (...) {
        }
		delete pic;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Basket::FormDestroy(TObject *Sender)
{
	for(auto const& [key, val] : ImageCache) {
		delete val;
	}
	ImageCache.clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Basket::FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled)
{
	if (WheelDelta > 0) {
		DM->Table_Basket->Prior();
	} else {
		DM->Table_Basket->Next();
	}
	Handled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm_Basket::Label3Click(TObject *Sender)
{
	if (DM->Table_Basket->IsEmpty()) return;

    String pName = DM->Table_Basket->FieldByName("Назва_піци")->AsString;

    // Запитуємо підтвердження, щоб юзер випадково не зніс замовлення
    if (Application->MessageBox(("Ви точно хочете видалити '" + pName + "' з кошика?").c_str(), L"Підтвердження", MB_YESNO | MB_ICONQUESTION) == IDYES)
    {
        DM->Table_Basket->Delete();

        // КРИТИЧНО: Перераховуємо суму після видалення!
        // У тебе вже є ця функція, ми її писали
        UpdateTotal();
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm_Basket::Label5Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm_Basket::Label_OrderClick(TObject *Sender)
{
if (DM->Table_Basket->IsEmpty()) {
        ShowMessage("Кошик порожній!");
        return;
    }

    TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "settings.ini");
    String actualLogin = ini->ReadString("Auth", "Login", "");
    delete ini;

    // 1. Шукаємо реальний ID клієнта (щоб не було помилки "Related record")
    int clientID = 0;
	if (DM->Table_Clients->Locate("Логін", actualLogin, TLocateOptions())) {
        clientID = DM->Table_Clients->FieldByName("ID")->AsInteger;
    } else {
        ShowMessage("Клієнта не знайдено!"); return;
    }

    // 2. Рахуємо суму
    float total = 0;
    DM->Table_Basket->First();
    while (!DM->Table_Basket->Eof) {
        if (DM->Table_Basket->FieldByName("Логін")->AsString == actualLogin) {
            total += (DM->Table_Basket->FieldByName("Ціна")->AsFloat * DM->Table_Basket->FieldByName("Кількість")->AsInteger);
        }
        DM->Table_Basket->Next();
    }

    // 3. Створюємо ЗАМОВЛЕННЯ (Назви полів чітко як на скрині image_1d8f58.png)
    DM->Table_Orders->Append();
    DM->Table_Orders->FieldByName("ID_Клієнта")->AsInteger = clientID;
    DM->Table_Orders->FieldByName("Сума")->AsFloat = total;
	DM->Table_Orders->FieldByName("Час_замовлення")->AsDateTime = Now();
	DM->Table_Orders->FieldByName("Сума_до_оплати")->AsFloat = total;
    DM->Table_Orders->Post();

	int orderID = DM->Table_Orders->FieldByName("ID")->AsInteger;

    // 4. Переносимо ДЕТАЛИ
	DM->Table_Basket->First();
	while (!DM->Table_Basket->Eof) {
		if (DM->Table_Basket->FieldByName("Логін")->AsString == actualLogin) {
			DM->Table_OrderDetails->Append();
			DM->Table_OrderDetails->FieldByName("ID_замовлення")->AsInteger = orderID;
			DM->Table_OrderDetails->FieldByName("Назва_піци")->AsString = DM->Table_Basket->FieldByName("Назва_піци")->AsString;
            DM->Table_OrderDetails->FieldByName("Ціна_за_штуку")->AsFloat = DM->Table_Basket->FieldByName("Ціна")->AsFloat;
            DM->Table_OrderDetails->FieldByName("Склад")->AsString = DM->Table_Basket->FieldByName("Склад")->AsString;
            DM->Table_OrderDetails->FieldByName("Кількість")->AsInteger = DM->Table_Basket->FieldByName("Кількість")->AsInteger;
            DM->Table_OrderDetails->Post();
        }
        DM->Table_Basket->Next();
	}

    DM->Table_Basket->First();

	while (!DM->Table_Basket->Eof)
{
    DM->Table_OrderDetails->Append();
    DM->Table_OrderDetails->FieldByName("ID_Замовлення")->AsInteger = orderID;
	DM->Table_OrderDetails->FieldByName("Назва_піци")->AsString = DM->Table_Basket->FieldByName("Назва_піци")->AsString;
    DM->Table_OrderDetails->FieldByName("Кількість")->AsInteger = DM->Table_Basket->FieldByName("Кількість")->AsInteger;

    // --- ПЕРЕВІР ОЦЕЙ РЯДОК ДУЖЕ УВАЖНО ---
    // Зліва - назва стовпця в таблиці ДЕТАЛЕЙ. Справа - назва стовпця в таблиці КОШИКА.
    DM->Table_OrderDetails->FieldByName("Фото")->AsString = DM->Table_Basket->FieldByName("Фото_Файл")->AsString;

    DM->Table_OrderDetails->Post();

    DM->Table_Basket->Next();
}
    // 5. Чистимо кошик
    DM->Table_Basket->First();
    while (!DM->Table_Basket->Eof) {
        if (DM->Table_Basket->FieldByName("Логін")->AsString == actualLogin) DM->Table_Basket->Delete();
        else DM->Table_Basket->Next();
    }

    ShowMessage("Замовлення №" + IntToStr(orderID) + " прийнято!");
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Basket::Button_PlusClick(TObject *Sender)
{
	if (DM->Table_Basket->IsEmpty()) return;

    DM->Table_Basket->Edit();
    DM->Table_Basket->FieldByName("Кількість")->AsInteger = DM->Table_Basket->FieldByName("Кількість")->AsInteger + 1;
    DM->Table_Basket->Post(); // Зберегли в базу

    // КРИТИЧНО: Викликаєш СВОЮ функцію, яка рахує гроші і міняє текст у Label
    // Заміни UpdateTotal Basket на реальну назву твоєї функції!
	UpdateTotal();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Basket::Button_MinusClick(TObject *Sender)
{
if (DM->Table_Basket->IsEmpty()) return;

    // Читаємо поточну кількість піц у вибраному рядку
    int currentQty = DM->Table_Basket->FieldByName("Кількість")->AsInteger;

    if (currentQty > 1)
    {
        // Якщо піц більше однієї — відкриваємо запис і віднімаємо 1
        DM->Table_Basket->Edit();
        DM->Table_Basket->FieldByName("Кількість")->AsInteger = currentQty - 1;
        DM->Table_Basket->Post(); // Зберігаємо в базу
    }
    else
    {
        // Якщо піца залишилася лише 1 і юзер тисне мінус — просто видаляємо цей запис з бази
        DM->Table_Basket->Delete();
    }

    // КРИТИЧНО: Після віднімання або видалення викликаємо твою функцію перерахунку грошей!
    // (ЗАМІНИ UpdateTotalBasket() НА РЕАЛЬНУ НАЗВУ СВОЄЇ ФУНКЦІЇ)
    UpdateTotal();
}
//---------------------------------------------------------------------------

