object Form_Menu: TForm_Menu
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'Form_Menu'
  ClientHeight = 561
  ClientWidth = 584
  Color = 3223891
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -21
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesktopCenter
  OnClose = FormClose
  OnDestroy = FormDestroy
  OnMouseWheel = FormMouseWheel
  OnShow = FormShow
  DesignSize = (
    584
    561)
  TextHeight = 30
  object Label_Hamburger: TLabel
    Left = 552
    Top = 8
    Width = 24
    Height = 37
    Anchors = [akTop, akRight]
    Caption = #9776
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHighlightText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    OnClick = Label_HamburgerClick
  end
  object Label5: TLabel
    Left = 112
    Top = 320
    Width = 60
    Height = 30
    Caption = 'Label5'
  end
  object Edit_Search: TEdit
    Left = 180
    Top = 16
    Width = 201
    Height = 29
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    TextHint = #1055#1086#1096#1091#1082'...'
    OnChange = Edit_SearchChange
  end
  object DBCtrlGrid1: TDBCtrlGrid
    Left = 8
    Top = 58
    Width = 545
    Height = 503
    DataSource = DM.Source_Pizzas
    PanelBorder = gbNone
    PanelHeight = 167
    PanelWidth = 528
    TabOrder = 0
    ShowFocus = False
    OnMouseDown = DBCtrlGrid1MouseDown
    OnMouseUp = DBCtrlGrid1MouseUp
    OnPaintPanel = DBCtrlGrid1PaintPanel
    object Image_Pizza: TImage
      Tag = 1
      Left = 0
      Top = 2
      Width = 526
      Height = 168
      Stretch = True
    end
    object DBText5: TDBText
      Left = 240
      Top = 0
      Width = 241
      Height = 42
      DataField = #1053#1072#1079#1074#1072'_'#1087#1110#1094#1080
      DataSource = DM.Source_Pizzas
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clHighlightText
      Font.Height = -29
      Font.Name = 'Segoe UI Semibold'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText6: TDBText
      Left = 299
      Top = 48
      Width = 206
      Height = 75
      DataField = #1057#1082#1083#1072#1076
      DataSource = DM.Source_Pizzas
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clSilver
      Font.Height = -19
      Font.Name = 'Segoe UI Semibold'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object DBText1: TDBText
      Left = 291
      Top = 129
      Width = 73
      Height = 25
      DataField = #1042#1072#1075#1072
      DataSource = DM.Source_Pizzas
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -17
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object DBText2: TDBText
      Left = 399
      Top = 129
      Width = 36
      Height = 21
      DataField = #1062#1110#1085#1072
      DataSource = DM.Source_Pizzas
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clHighlightText
      Font.Height = -17
      Font.Name = 'Segoe UI bold'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 434
      Top = 129
      Width = 28
      Height = 23
      Caption = #1075#1088#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -17
      Font.Name = 'Segoe UI Bold'
      Font.Style = []
      ParentFont = False
    end
    object TShape
      Left = 487
      Top = 119
      Width = 34
      Height = 40
      Brush.Color = 2829141
      Pen.Style = psClear
      Pen.Width = 0
      Shape = stRoundRect
    end
    object Label3: TLabel
      Left = 487
      Top = 119
      Width = 23
      Height = 32
      Caption = ' +'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -24
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      OnClick = BtnAddClick
    end
    object Shape1: TShape
      Left = 487
      Top = 10
      Width = 33
      Height = 40
      Brush.Color = 2829141
      Pen.Style = psClear
      Pen.Width = 0
      Shape = stRoundRect
    end
  end
  object Button_Basket: TButton
    Left = 536
    Top = 510
    Width = 48
    Height = 49
    Caption = #55357#57042
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button_BasketClick
  end
  object Btn_OpenConstructor: TButton
    Left = 400
    Top = 17
    Width = 118
    Height = 28
    Caption = #1042#1083#1072#1089#1085#1072' '#1087#1110#1094#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Btn_OpenConstructorClick
  end
  object Panel_Account: TPanel
    Left = 261
    Top = -11
    Width = 323
    Height = 579
    Color = 3552858
    ParentBackground = False
    TabOrder = 2
    Visible = False
    object Label4: TLabel
      Left = 102
      Top = 17
      Width = 131
      Height = 32
      AutoSize = False
      Caption = #1052#1110#1081' '#1072#1082#1072#1091#1085#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -24
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label_ClosePanel: TLabel
      Left = 17
      Top = 15
      Width = 29
      Height = 30
      Caption = #10006
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      OnClick = Label_ClosePanelClick
    end
    object Label_AccName: TLabel
      Left = 17
      Top = 241
      Width = 133
      Height = 25
      Caption = 'Label_AccName'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label_AccPhone: TLabel
      Left = 17
      Top = 297
      Width = 137
      Height = 25
      Caption = 'Label_AccPhone'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label_AccAddress: TLabel
      Left = 17
      Top = 344
      Width = 280
      Height = 97
      AutoSize = False
      Caption = 'Label_AccAddress'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object Label_AccLogin: TLabel
      Left = 17
      Top = 192
      Width = 130
      Height = 25
      Caption = 'Label_AccLogin'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Button_Logout: TButton
      Left = 17
      Top = 519
      Width = 120
      Height = 33
      Caption = #1042#1080#1081#1090#1080' '#1079' '#1072#1082#1072#1091#1085#1090#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button_LogoutClick
    end
    object Button_GoToLogin: TButton
      Left = 80
      Top = 116
      Width = 177
      Height = 54
      Caption = #1059#1074#1110#1081#1090#1080' / '#1047#1072#1088#1077#1108#1089#1090#1088#1091#1074#1072#1090#1080#1089#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      WordWrap = True
      OnClick = Button_GoToLoginClick
    end
  end
  object Panel_Settings: TPanel
    Left = 261
    Top = -11
    Width = 323
    Height = 579
    Color = 3223891
    ParentBackground = False
    TabOrder = 5
    Visible = False
    object Label_CloseSettings: TLabel
      Left = 17
      Top = 15
      Width = 29
      Height = 30
      Caption = #10006
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      OnClick = Label_CloseSettingsClick
    end
    object SpeedButton_ShowPass: TSpeedButton
      Left = 46
      Top = 419
      Width = 121
      Height = 22
      Caption = #1055#1086#1082#1072#1079#1072#1090#1080' '#1087#1072#1088#1086#1083#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      OnClick = SpeedButton_ShowPassClick
    end
    object Label1: TLabel
      Left = 38
      Top = 99
      Width = 106
      Height = 25
      Caption = #1047#1084#1110#1085#1080#1090#1080' '#1110#1084#39#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 38
      Top = 179
      Width = 217
      Height = 25
      Caption = #1047#1084#1110#1085#1080#1090#1080' '#1085#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1091
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 38
      Top = 259
      Width = 133
      Height = 25
      Caption = #1047#1084#1110#1085#1080#1090#1080' '#1072#1076#1088#1077#1089#1091
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 96
      Top = 15
      Width = 141
      Height = 30
      Caption = #1053#1072#1083#1072#1096#1090#1091#1074#1072#1085#1085#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 38
      Top = 344
      Width = 124
      Height = 25
      Caption = #1053#1086#1074#1080#1081' '#1087#1072#1088#1086#1083#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHighlightText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Edit_EditName: TEdit
      Left = 38
      Top = 130
      Width = 267
      Height = 38
      TabOrder = 0
      TextHint = #1047#1084#1110#1085#1080#1090#1080' '#1110#1084#39#1103'...'
    end
    object Edit_EditPhone: TEdit
      Left = 38
      Top = 210
      Width = 267
      Height = 38
      TabOrder = 1
      TextHint = #1047#1084#1110#1085#1080#1090#1080' '#1085#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1091'...'
    end
    object Button_SaveSettings: TButton
      Left = 104
      Top = 472
      Width = 105
      Height = 41
      Caption = #1047#1073#1077#1088#1077#1075#1090#1080
      TabOrder = 2
      OnClick = Button_SaveSettingsClick
    end
    object Edit_EditAddress: TEdit
      Left = 38
      Top = 290
      Width = 267
      Height = 38
      TabOrder = 3
      TextHint = #1047#1084#1110#1085#1080#1090#1080' '#1072#1076#1088#1077#1089#1091'...'
    end
    object Edit_NewPassword: TEdit
      Left = 38
      Top = 375
      Width = 155
      Height = 38
      PasswordChar = '*'
      TabOrder = 4
      Text = 'Edit_NewPassword'
    end
  end
  object PopupMenu_Account: TPopupMenu
    Left = 520
    Top = 16
    object MenuItem_SettingsClick: TMenuItem
      Caption = #1053#1072#1083#1072#1096#1090#1091#1074#1072#1085#1085#1103
      OnClick = MenuItem_SettingsClickClick
    end
    object AccountPopup: TMenuItem
      Caption = #1040#1082#1082#1072#1091#1085#1090
      OnClick = AccountPopupClick
    end
    object MenuItem_History: TMenuItem
      Caption = #1030#1089#1090#1086#1088#1110#1103' '#1079#1072#1084#1086#1074#1083#1077#1085#1100
      OnClick = MenuItem_HistoryClick
    end
  end
end
