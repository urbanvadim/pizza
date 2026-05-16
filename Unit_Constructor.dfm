object Form_Constructor: TForm_Constructor
  Left = 0
  Top = 0
  Caption = 'Form_Constructor'
  ClientHeight = 561
  ClientWidth = 584
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesktopCenter
  OnShow = FormShow
  TextHeight = 21
  object Label_TotalPrice: TLabel
    Left = 67
    Top = 170
    Width = 63
    Height = 25
    Caption = '0.00'#1075#1088#1085
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 8
    Top = 170
    Width = 44
    Height = 25
    Caption = #1062#1110#1085#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Tag = 1
    Left = 208
    Top = 157
    Width = 142
    Height = 21
    Caption = #1054#1073#1077#1088#1110#1090#1100' '#1110#1085#1075#1088#1072#1076#1110#1108#1085#1090#1080
  end
  object RadioGroup_Dough: TRadioGroup
    Left = 0
    Top = 8
    Width = 289
    Height = 113
    Caption = #1054#1073#1077#1088#1110#1090#1100' '#1090#1110#1089#1090#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = RadioGroup_DoughClick
  end
  object RadioGroup_Sauce: TRadioGroup
    Left = 290
    Top = 8
    Width = 295
    Height = 153
    Caption = #1054#1073#1077#1088#1110#1090#1100' '#1073#1072#1079#1086#1074#1080#1081' '#1089#1086#1091#1089
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = RadioGroup_SauceClick
  end
  object Button_AddToCart: TButton
    Left = 8
    Top = 210
    Width = 49
    Height = 42
    Caption = #55357#57042
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button_AddToCartClick
  end
  object Btn_menu: TButton
    Left = 8
    Top = 514
    Width = 97
    Height = 39
    Caption = #1042' '#1084#1077#1085#1102
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Btn_menuClick
  end
  object CheckListBox_Ingredients: TCheckListBox
    Left = 208
    Top = 177
    Width = 377
    Height = 376
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ItemHeight = 21
    ParentFont = False
    TabOrder = 4
    OnClick = CheckListBox_IngredientsClick
  end
end
