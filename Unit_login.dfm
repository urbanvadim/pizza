object Form_Login: TForm_Login
  Left = 0
  Top = 0
  Hint = #1042#1074#1077#1076#1110#1090#1100' '#1087#1072#1088#1086#1083#1100'...'
  Caption = 'Form_Login'
  ClientHeight = 561
  ClientWidth = 584
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesktopCenter
  OnActivate = FormActivate
  OnClose = FormClose
  TextHeight = 15
  object Label1: TLabel
    Left = 208
    Top = 107
    Width = 47
    Height = 25
    Caption = #1051#1086#1075#1110#1085
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 208
    Top = 177
    Width = 66
    Height = 25
    Caption = #1055#1072#1088#1086#1083#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object SpeedButton1: TSpeedButton
    Left = 216
    Top = 261
    Width = 145
    Height = 38
    Caption = #1055#1086#1082#1072#1079#1072#1090#1080' '#1087#1072#1088#1086#1083#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    OnMouseDown = SpeedButton1MouseDown
    OnMouseUp = SpeedButton1MouseUp
  end
  object BtnGuest: TLabel
    Left = 248
    Top = 444
    Width = 78
    Height = 15
    Caption = #1059#1074#1110#1081#1090#1080' '#1103#1082' '#1075#1110#1089#1090#1100
    Color = clSkyBlue
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHighlight
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    OnClick = BtnGuestClick
  end
  object Edit_Login: TEdit
    Left = 208
    Top = 136
    Width = 169
    Height = 29
    Hint = #1042#1074#1077#1076#1110#1090#1100' '#1083#1086#1075#1110#1085'...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    MaxLength = 20
    ParentFont = False
    TabOrder = 0
    TextHint = #1042#1074#1077#1076#1110#1090#1100' '#1083#1086#1075#1110#1085'...'
  end
  object Edit_Pass: TEdit
    Left = 208
    Top = 208
    Width = 169
    Height = 29
    Hint = #1042#1074#1077#1076#1110#1090#1100' '#1087#1072#1088#1086#1083#1100'...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    MaxLength = 30
    ParentFont = False
    PasswordChar = '*'
    TabOrder = 1
    TextHint = #1042#1074#1077#1076#1110#1090#1100' '#1087#1072#1088#1086#1083#1100'...'
  end
  object Btn_Login: TButton
    Left = 248
    Top = 350
    Width = 89
    Height = 33
    Caption = #1059#1074#1110#1081#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Btn_LoginClick
  end
  object Btn_Reg: TButton
    Left = 232
    Top = 397
    Width = 129
    Height = 28
    Caption = #1047#1072#1088#1077#1108#1089#1090#1088#1091#1074#1072#1090#1080#1089#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Btn_RegClick
  end
  object Check_Remember: TCheckBox
    Left = 216
    Top = 313
    Width = 161
    Height = 17
    Caption = #1047#1072#1087#1072#1084#39#1103#1090#1072#1090#1080' '#1084#1077#1085#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHotLight
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
end
