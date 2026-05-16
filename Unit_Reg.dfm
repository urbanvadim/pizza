object Form_Reg: TForm_Reg
  Left = 0
  Top = 0
  Caption = 'Form_Reg'
  ClientHeight = 561
  ClientWidth = 584
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesktopCenter
  TextHeight = 15
  object Label1: TLabel
    Left = 185
    Top = 72
    Width = 146
    Height = 15
    Caption = #1055#1088#1110#1079#1074#1080#1097#1077' '#1030#1084#39#1103' '#1055#1086' '#1073#1072#1090#1100#1082#1086#1074#1110
  end
  object Label2: TLabel
    Left = 185
    Top = 130
    Width = 39
    Height = 15
    Caption = #1040#1076#1088#1077#1089#1072
  end
  object Label3: TLabel
    Left = 185
    Top = 188
    Width = 94
    Height = 15
    Caption = #1053#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1091
  end
  object Label4: TLabel
    Left = 185
    Top = 247
    Width = 100
    Height = 15
    Caption = #1055#1088#1080#1076#1091#1084#1072#1081#1090#1077' '#1083#1086#1075#1110#1085
  end
  object Label5: TLabel
    Left = 185
    Top = 303
    Width = 42
    Height = 15
    Caption = #1055#1072#1088#1086#1083#1100
  end
  object Edit_RegName: TEdit
    Left = 185
    Top = 93
    Width = 217
    Height = 23
    TabOrder = 0
    OnKeyPress = Edit_RegNameKeyPress
  end
  object Edit_RegPhone: TEdit
    Left = 185
    Top = 209
    Width = 121
    Height = 23
    TabOrder = 1
    OnKeyPress = Edit_RegPhoneKeyPress
  end
  object Edit_RegAddress: TEdit
    Left = 185
    Top = 152
    Width = 217
    Height = 23
    TabOrder = 2
  end
  object Edit_RegLogin: TEdit
    Left = 185
    Top = 266
    Width = 137
    Height = 23
    TabOrder = 3
  end
  object Edit_RegPass: TEdit
    Left = 185
    Top = 330
    Width = 137
    Height = 23
    PasswordChar = '*'
    TabOrder = 4
  end
  object Btn_SaveReg: TButton
    Left = 232
    Top = 392
    Width = 113
    Height = 33
    Caption = #1047#1072#1088#1077#1108#1089#1090#1088#1091#1074#1072#1090#1080#1089#1100
    TabOrder = 5
    OnClick = Btn_SaveRegClick
  end
end
