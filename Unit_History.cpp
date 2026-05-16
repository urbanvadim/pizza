//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit_History.h"
#include "Unit_DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_History *Form_History;
//---------------------------------------------------------------------------
__fastcall TForm_History::TForm_History(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_History::Button_CloseHistoryClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_History::DBCtrlGrid1PaintPanel(TDBCtrlGrid *DBCtrlGrid, int Index)

{
    TDateTime fullDateTime = DM->Table_Orders->FieldByName("Час")->AsDateTime;

    // Форматуємо дату (наприклад: 16.05.2026) і записуємо в перший Label
    Label_Date->Caption = FormatDateTime("dd.mm.yyyy", fullDateTime);

    // Форматуємо час (наприклад: 14:25) і записуємо в другий Label
    Label_Time->Caption = FormatDateTime("hh:nn", fullDateTime);
}
//---------------------------------------------------------------------------

void __fastcall TForm_History::Panel_closeClick(TObject *Sender)
{
    Panel_OrderDetails->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm_History::Button_DetailsClick(TObject *Sender)
{
	int currentOrderID = DM->Table_Orders->FieldByName("ID")->AsInteger;

    // 2. Фільтруємо базу деталей, щоб дістати піци тільки для цього чека
    DM->Table_OrderDetails->Filtered = false;
    DM->Table_OrderDetails->Filter = "ID_Замовлення = " + IntToStr(currentOrderID);
    DM->Table_OrderDetails->Filtered = true;

    // 3. Викликаємо нашу приховану панель поверх усього!
    Panel_OrderDetails->BringToFront();
    Panel_OrderDetails->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm_History::DBCtrlGrid_DetailsPaintPanel(TDBCtrlGrid *DBCtrlGrid,
		  int Index)
{
	TDataSet *ds = DBCtrlGrid->DataSource->DataSet;
    if (!ds || ds->IsEmpty()) return;

    // 1. Зчитуємо назву файлу
    String fName = ds->FieldByName("Фото")->AsString;

    // 2. Беремо координати рамки
    TRect drawRect = Image_PizzaDetail->BoundsRect;

    // 3. Якщо назва файлу є в базі (не порожня)
    if (fName.Trim() != "")
    {
        String path = ExtractFilePath(Application->ExeName) + "Img\\" + fName;

        // Якщо реальний файл піци існує на диску - вантажимо його
        if (FileExists(path))
        {
            TPicture *pic = new TPicture();
            try {
                pic->LoadFromFile(path);
                DBCtrlGrid->Canvas->StretchDraw(drawRect, pic->Graphic);
                delete pic;
                return; // Все успішно намалювали, виходимо з функції!
            } catch (...) {
                delete pic;
                // Якщо реальна фотка піци вибила помилку, код не впаде, а піде далі малювати заглушку
            }
        }
    }

    // 4. ЗАГЛУШКА БЕЗ ФАЙЛІВ: Якщо фото немає, або воно бите - просто малюємо графіку кодом!
    // Малюємо красивий сірий квадрат
    DBCtrlGrid->Canvas->Brush->Color = clSilver;
    DBCtrlGrid->Canvas->FillRect(drawRect);

    // Малюємо акуратну рамку навколо нього
    DBCtrlGrid->Canvas->Pen->Color = clGray;
    DBCtrlGrid->Canvas->Rectangle(drawRect.Left, drawRect.Top, drawRect.Right, drawRect.Bottom);

	// Пишемо текст по центру
    DBCtrlGrid->Canvas->Font->Size = 10;
	DBCtrlGrid->Canvas->TextOut(drawRect.Left + 15, drawRect.Top + (drawRect.Height()/2) - 10, "Немає фото");

}
//---------------------------------------------------------------------------

void __fastcall TForm_History::FormMouseWheelUp(TObject *Sender, TShiftState Shift,
		  TPoint &MousePos, bool &Handled)
		  {if (!DM->Table_Orders->Bof) {
		  DM->Table_Orders->Prior();
		  }
Handled = true;
}
//--------------------------------------------------------------------------

void __fastcall TForm_History::FormMouseWheelDown(TObject *Sender, TShiftState Shift,
		  TPoint &MousePos, bool &Handled) {
              // Рухаємо базу замовлень вперед (наступний чек)
	if (!DM->Table_Orders->Eof) {
		DM->Table_Orders->Next();
	}
	Handled = true; // Кажемо Windows, що ми самі обробили скрол
          }

