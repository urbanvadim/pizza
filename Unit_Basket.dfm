object Form_Basket: TForm_Basket
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'Form_Basket'
  ClientHeight = 561
  ClientWidth = 584
  Color = 3223891
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poOwnerFormCenter
  OnDestroy = FormDestroy
  OnMouseWheel = FormMouseWheel
  OnShow = FormShow
  TextHeight = 21
  object Label_TotalSum: TLabel
    Left = 308
    Top = 514
    Width = 77
    Height = 30
    Caption = '0.00'#1075#1088#1085
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHighlightText
    Font.Height = -21
    Font.Name = 'Segoe UI Bold'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 245
    Top = 519
    Width = 57
    Height = 24
    Caption = #1057#1091#1084#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHighlightText
    Font.Height = -21
    Font.Name = 'Segoe UI '
    Font.Style = []
    ParentFont = False
  end
  object Shape3: TShape
    Left = 460
    Top = 517
    Width = 107
    Height = 30
    Brush.Color = 4737386
    Pen.Style = psClear
    Pen.Width = 0
    Shape = stRoundRect
  end
  object Label_Order: TLabel
    Left = 466
    Top = 514
    Width = 93
    Height = 30
    Caption = #1047#1072#1084#1086#1074#1080#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHighlightText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    OnClick = Label_OrderClick
  end
  object Shape2: TShape
    Left = 483
    Top = 28
    Width = 64
    Height = 30
    Brush.Color = 4737386
    Pen.Style = psClear
    Pen.Width = 0
    Shape = stRoundRect
  end
  object Label5: TLabel
    Left = 489
    Top = 28
    Width = 53
    Height = 25
    Caption = #1052#1077#1085#1102
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHighlightText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    OnClick = Label5Click
  end
  object Edit_Name: TEdit
    Left = 8
    Top = 431
    Width = 231
    Height = 29
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    TextHint = #1042#1074#1077#1076#1110#1090#1100' '#1087#1088#1110#1079#1074#1080#1097#1077' '#1110' '#1110#1084#39#1103'...'
  end
  object Edit_Phone: TEdit
    Left = 8
    Top = 479
    Width = 231
    Height = 29
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    TextHint = #1042#1074#1077#1076#1110#1090#1100' '#1085#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1091'...'
  end
  object Edit_Address: TEdit
    Left = 8
    Top = 522
    Width = 231
    Height = 29
    Hint = #1042#1074#1077#1076#1110#1090#1100' '#1072#1076#1088#1077#1089#1091'...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    TextHint = #1042#1074#1077#1076#1110#1090#1100' '#1072#1076#1088#1077#1089#1091'...'
  end
  object DBCtrlGrid: TDBCtrlGrid
    Left = 8
    Top = 0
    Width = 433
    Height = 425
    DataSource = DM.Source_Basket
    PanelHeight = 141
    PanelWidth = 416
    TabOrder = 0
    OnPaintPanel = DBCtrlGridPaintPanel
    object Image_Basket: TImage
      Left = 0
      Top = 0
      Width = 417
      Height = 145
      Proportional = True
    end
    object DBText1: TDBText
      Left = 221
      Top = 0
      Width = 204
      Height = 33
      DataField = #1053#1072#1079#1074#1072'_'#1087#1110#1094#1080
      DataSource = DM.Source_Basket
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -21
      Font.Name = 'Segoe UI bold'
      Font.Style = []
      ParentFont = False
    end
    object DBText2: TDBText
      Left = 253
      Top = 31
      Width = 169
      Height = 58
      DataField = #1057#1082#1083#1072#1076
      DataSource = DM.Source_Basket
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clSilver
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object DBText4: TDBText
      Left = 237
      Top = 112
      Width = 28
      Height = 17
      DataField = #1062#1110#1085#1072
      DataSource = DM.Source_Basket
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -16
      Font.Name = 'Segoe UI Bold'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 267
      Top = 112
      Width = 27
      Height = 21
      Caption = #1075#1088#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -16
      Font.Name = 'Segoe UI Bold'
      Font.Style = []
      ParentFont = False
    end
    object Shape1: TShape
      Left = 376
      Top = 103
      Width = 33
      Height = 34
      Brush.Color = 4737386
      Pen.Style = psClear
      Pen.Width = 0
      Shape = stRoundRect
    end
    object Label3: TLabel
      Left = 376
      Top = 103
      Width = 33
      Height = 32
      Caption = #10006
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -24
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      OnClick = Label3Click
    end
    object DBText3: TDBText
      Left = 334
      Top = 112
      Width = 15
      Height = 17
      DataField = #1050#1110#1083#1100#1082#1110#1089#1090#1100
      DataSource = DM.Source_Basket
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Shape4: TShape
      Left = 313
      Top = 116
      Width = 15
      Height = 17
      Brush.Color = 4737386
      Pen.Style = psClear
      Pen.Width = 0
      Shape = stRoundRect
    end
    object Shape5: TShape
      Left = 355
      Top = 116
      Width = 15
      Height = 17
      Brush.Color = 4737386
      Pen.Style = psClear
      Pen.Width = 0
      Shape = stRoundRect
    end
    object Button_Plus: TLabel
      Left = 314
      Top = 112
      Width = 11
      Height = 21
      Caption = '+'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      OnClick = Button_PlusClick
    end
    object Button_Minus: TLabel
      Left = 359
      Top = 112
      Width = 6
      Height = 21
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      OnClick = Button_MinusClick
    end
  end
end
