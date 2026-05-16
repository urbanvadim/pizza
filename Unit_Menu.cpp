//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Registry.hpp>
#include <IniFiles.hpp>
#include "Unit_DataModule.h"
#include "Unit_Menu.h"
#include "Unit_login.h"
#include "Unit_Basket.h"
#include "Unit_Constructor.h"
#include "Unit_History.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Menu *Form_Menu;
//---------------------------------------------------------------------------
__fastcall TForm_Menu::TForm_Menu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_Menu::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::Edit_SearchChange(TObject *Sender)
{
	if (Edit_Search->Text == "")
    {
        DM->Table_Pizzas->Filtered = false;
    }
    else
	{
        DM->Table_Pizzas->Filter = "Назва LIKE '" + Edit_Search->Text + "*'";
        DM->Table_Pizzas->Filtered = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::Btn_AddClick(TObject *Sender)
{
    String pizzaName = DM->Table_Pizzas->FieldByName("Назва_Піци")->AsString;
	ShowMessage("Додано: " + pizzaName);
}
//---------------------------------------------------------------------------
void __fastcall TForm_Menu::DBCtrlGrid1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    DM->Table_Pizzas->Next();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::DBCtrlGrid1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	DM->Table_Pizzas->Prior();
}
//---------------------------------------------------------------------------
void __fastcall TForm_Menu::FormShow(TObject *Sender)
{
	ActiveControl = NULL;
}
//--------------------------------------------------------------------------

void __fastcall TForm_Menu::FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled)
{
    if (WheelDelta < 0) {
        DM->Table_Pizzas->Next();
    } else {
        DM->Table_Pizzas->Prior();
	}
    Handled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm_Menu::AccountPopupClick(TObject *Sender)
{
	Label_Hamburger->Visible = false;
	Panel_Account->Parent = this;     // Прив'язуємо жорстко до самої форми
	Panel_Account->BringToFront();    // Витягуємо поверх усього
	Panel_Account->Visible = true;
	Button_Basket->Visible = false;

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "settings.ini");
	String currentLogin = ini->ReadString("Auth", "Login", "Guest"); // Ось тут вона народжується!

	delete ini;
	if (currentLogin == "Guest" || currentLogin == "")
    {
        // ==========================================
        // РЕЖИМ ГОСТЯ
        // ==========================================

        // Ховаємо твої особисті дані (заміни назви Label на свої)
        Label_AccName->Visible = false;
        Label_AccPhone->Visible = false;
        Label_AccAddress->Visible = false;
        Label_AccLogin->Visible = false;

        // Ховаємо кнопку "Вийти" і показуємо "Увійти/Зареєструватись"
        Button_Logout->Visible = false;
        Button_GoToLogin->Visible = true;

        // Можеш додати окремий Label, щоб було красиво:
        // Label_Title->Caption = "Ви увійшли як Гість";
    }
    else
    {
        // ==========================================
        // РЕЖИМ АВТОРИЗОВАНОГО КОРИСТУВАЧА
        // ==========================================

        Button_GoToLogin->Visible = false;
        Button_Logout->Visible = true;

        // Шукаємо тебе в таблиці клієнтів
        if (DM->Table_Clients->Locate("Логін", currentLogin, TLocateOptions()))
        {
            // Виводимо дані з бази в Label
			Label_AccName->Caption = "ПІБ: " + DM->Table_Clients->FieldByName("ПІБ_Клієнта")->AsString;
			Label_AccPhone->Caption = "Тел: " + DM->Table_Clients->FieldByName("Телефон")->AsString;
			Label_AccAddress->Caption = "Адреса: " + DM->Table_Clients->FieldByName("Адреса_Доставки")->AsString;
			Label_AccLogin->Caption = "Логін: " + currentLogin;

            // Якщо в тебе є поле Адреса в базі:
            // Label_AccAddress->Caption = "Адреса: " + DM->Table_Clients->FieldByName("Адреса")->AsString;

            // Робимо всі ці написи видимими
            Label_AccName->Visible = true;
            Label_AccPhone->Visible = true;
            Label_AccAddress->Visible = true;
            Label_AccLogin->Visible = true;

            // Label_Title->Caption = "Мій профіль";
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::Button_LogoutClick(TObject *Sender)
{
	DeleteFile(ExtractFilePath(Application->ExeName) + "settings.ini");
	Panel_Account->Visible = false;
	this->Hide();
	Form_Login->Show();
	Label_Hamburger->Visible = true;
    Button_Basket->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm_Menu::Label_HamburgerClick(TObject *Sender)
{
	TPoint p;
	p.x = Label_Hamburger->Width;
	p.y = Label_Hamburger->Height;
	p = Label_Hamburger->ClientToScreen(p);

	PopupMenu_Account->Alignment = paRight;
	PopupMenu_Account->Popup(p.x, p.y);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::Label_ClosePanelClick(TObject *Sender)
{
	Panel_Account->Visible = false;
	Button_Basket->Visible = true;
	Label_Hamburger->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::BtnAddClick(TObject *Sender)
{
// Захист від помилок
if (!DM->Table_Pizzas->Active) return;

TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "settings.ini");
String actualLogin = ini->ReadString("Auth", "Login", "");
delete ini;

if (actualLogin == "") {
    ShowMessage("Будь ласка, спочатку увійдіть в акаунт!");
    return;
}

String pName = DM->Table_Pizzas->FieldByName("Назва_піци")->AsString;

    // 2. ПЕРЕВІРКА: Якщо це конструктор — відкриваємо форму і ВИХОДИМО
    if (pName == "Власна піца")
    {
        // Показуємо форму конструктора (заміни Form_Constructor на свою назву)
        Form_Constructor->ShowModal();

        // КРИТИЧНО: виходимо з функції, щоб код нижче не додав "порожню" піцу в кошик
        return;
	}
// Отримуємо ВСІ дані про піцу з меню
String pizzaName = DM->Table_Pizzas->FieldByName("Назва_піци")->AsString;
float pizzaPrice = DM->Table_Pizzas->FieldByName("Ціна")->AsFloat;
String pizzaComposition = DM->Table_Pizzas->FieldByName("Склад")->AsString;
String pizzaPhoto = DM->Table_Pizzas->FieldByName("Фото")->AsString; // БЕРЕМО НАЗВУ ФАЙЛУ!

// Шукаємо в кошику для актуального логіна
Variant locvalues[2];
locvalues[0] = pizzaName;
locvalues[1] = actualLogin;

if (DM->Table_Basket->Locate("Назва_піци;Логін", VarArrayOf(locvalues, 1), TLocateOptions()))
{
    DM->Table_Basket->Edit();
    int currentQty = DM->Table_Basket->FieldByName("Кількість")->AsInteger;
    DM->Table_Basket->FieldByName("Кількість")->AsInteger = currentQty + 1;
    DM->Table_Basket->Post();
    ShowMessage("Кількість піци '" + pizzaName + "' збільшено!");
}
else
{
    DM->Table_Basket->Append();
	DM->Table_Basket->FieldByName("Назва_піци")->AsString = pizzaName;
    DM->Table_Basket->FieldByName("Ціна")->AsFloat = pizzaPrice;
    DM->Table_Basket->FieldByName("Кількість")->AsInteger = 1;
    DM->Table_Basket->FieldByName("Логін")->AsString = actualLogin;
    DM->Table_Basket->FieldByName("Склад")->AsString = pizzaComposition;

    // ОСЬ ТУТ МАГІЯ: Записуємо назву фото прямо в таблицю кошика
    // Переконайся, що в Access поле називається саме Фото_Файл
    DM->Table_Basket->FieldByName("Фото_Файл")->AsString = pizzaPhoto;

    DM->Table_Basket->Post();
    ShowMessage("Піцу '" + pizzaName + "' додано в кошик!");
}
}
void __fastcall TForm_Menu::Button_BasketClick(TObject *Sender)
{
	Form_Basket->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::DBCtrlGrid1PaintPanel(TDBCtrlGrid *DBCtrlGrid, int Index)

{
   // Захист від закритої бази
    if (!DM->Table_Pizzas->Active) return;

    String imgName = DM->Table_Pizzas->FieldByName("Фото")->AsString;

    // Перевіряємо, чи є вже ця картинка в нашому кеші
    if (ImageCache.find(imgName) == ImageCache.end())
    {
        TPicture *pic = new TPicture();
		String fullPath = ExtractFilePath(Application->ExeName) + "Img\\" + imgName;

        // ЗАХИСНИЙ БЛОК: пробуємо завантажити фото
        try {
            if (FileExists(fullPath)) {
                pic->LoadFromFile(fullPath);
			} else {
                pic->LoadFromFile(ExtractFilePath(Application->ExeName) + "Img\\no_photo.jpg");
            }
        }
		catch (...) {
			// Якщо сталася будь-яка помилка (зокрема твій JPEG error #42),
            // ми перехоплюємо її і мовчки вантажимо картинку-заглушку.
            // Жодних червоних вікон юзер не побачить.
            try {
				pic->LoadFromFile(ExtractFilePath(Application->ExeName) + "Img\\no_photo.jpg");
            } catch (...) {
                // Якщо навіть no_photo.jpg немає, залишаємо пусте місце
            }
        }

        // Зберігаємо в кеш
        ImageCache[imgName] = pic;
    }

    // Малюємо з кешу
	Image_Pizza->Picture->Assign(ImageCache[imgName]);
}
//---------------------------------------------------------------------------


void __fastcall TForm_Menu::FormDestroy(TObject *Sender)
{
	for(auto const& [key, val] : ImageCache)
    {
        delete val;
    }
	ImageCache.clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::Btn_OpenConstructorClick(TObject *Sender)
{
	Form_Constructor->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::Button_GoToLoginClick(TObject *Sender)
{
	this->Hide();
	Form_Login->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::MenuItem_SettingsClickClick(TObject *Sender)
{
TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "settings.ini");
    String currentLogin = ini->ReadString("Auth", "Login", "Guest");
    delete ini;

    if (currentLogin == "Guest" || currentLogin == "")
    {
        ShowMessage("Налаштування доступні лише для авторизованих користувачів! Зареєструйтесь.");
        return;
    }

    // Ховаємо акаунт і кошик
    Panel_Account->Visible = false;
	Button_Basket->Visible = false;
	Label_Hamburger->Visible = false;

	// Витягуємо панель налаштувань
    Panel_Settings->Parent = this;
    Panel_Settings->BringToFront();
    Panel_Settings->Visible = true;

    // Завантажуємо поточні дані з бази в поля вводу
    if (DM->Table_Clients->Locate("Логін", currentLogin, TLocateOptions()))
    {
		Edit_EditName->Text = DM->Table_Clients->FieldByName("ПІБ_Клієнта")->AsString;
        Edit_EditPhone->Text = DM->Table_Clients->FieldByName("Телефон")->AsString;
		Edit_EditAddress->Text = DM->Table_Clients->FieldByName("Адреса_доставки")->AsString;

        // Пароль виводимо, але він прихований зірочками (PasswordChar = '*')
		Edit_NewPassword->Text = DM->Table_Clients->FieldByName("Пароль")->AsString;
        Edit_NewPassword->PasswordChar = '*';
		SpeedButton_ShowPass->Caption = "Показати";
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::Button_SaveSettingsClick(TObject *Sender)
{
    if (Edit_EditName->Text == "" || Edit_EditPhone->Text == "" || Edit_EditAddress->Text == "" || Edit_NewPassword->Text == "") {
        ShowMessage("Жодне поле не може бути порожнім!");
        return;
    }

    TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "settings.ini");
    String currentLogin = ini->ReadString("Auth", "Login", "");
    delete ini;

    if (DM->Table_Clients->Locate("Логін", currentLogin, TLocateOptions()))
    {
        DM->Table_Clients->Edit();
		DM->Table_Clients->FieldByName("ПІБ_Клієнта")->AsString = Edit_EditName->Text;
        DM->Table_Clients->FieldByName("Телефон")->AsString = Edit_EditPhone->Text;
        DM->Table_Clients->FieldByName("Адреса_доставки")->AsString = Edit_EditAddress->Text;
        DM->Table_Clients->FieldByName("Пароль")->AsString = Edit_NewPassword->Text;
        DM->Table_Clients->Post();

        ShowMessage("Дані успішно оновлено!");

        Panel_Settings->Visible = false;
        Button_Basket->Visible = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::SpeedButton_ShowPassClick(TObject *Sender)
{
if (Edit_NewPassword->PasswordChar == '*')
	{
        Edit_NewPassword->PasswordChar = 0;
        SpeedButton_ShowPass->Caption = "Сховати";
    }
    else
    {
        Edit_NewPassword->PasswordChar = '*';
        SpeedButton_ShowPass->Caption = "Показати";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::Label_CloseSettingsClick(TObject *Sender)
{
    Panel_Settings->Visible = false;
	Button_Basket->Visible = true;
	Label_Hamburger->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Menu::MenuItem_HistoryClick(TObject *Sender)
{
    // 1. Читаємо логін з файлу
    TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "settings.ini");
    String currentLogin = ini->ReadString("Auth", "Login", "Guest");
    delete ini;

    // 2. Якщо це Гість - видаємо повідомлення і зупиняємо код
    if (currentLogin == "Guest" || currentLogin == "")
    {
        ShowMessage("Історія замовлень доступна лише для авторизованих клієнтів! Будь ласка, увійдіть в акаунт.");
        return;
    }

    // 3. Знаходимо твій ID у базі клієнтів
	if (DM->Table_Clients->Locate("Логін", currentLogin, TLocateOptions()))
    {
        int myID = DM->Table_Clients->FieldByName("ID")->AsInteger;

        // 4. ЖОРСТКА ФІЛЬТРАЦІЯ: залишаємо в таблиці замовлень тільки твої чеки
        DM->Table_Orders->Filtered = false;
        DM->Table_Orders->Filter = "ID_Клієнта = " + IntToStr(myID);
        DM->Table_Orders->Filtered = true;

        // 5. Відкриваємо форму історії
        Form_History->ShowModal();
    }
    else
    {
        ShowMessage("Помилка: Клієнта не знайдено в базі!");
	}
}
//---------------------------------------------------------------------------

