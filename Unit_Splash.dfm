object Form_Splash: TForm_Splash
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'Form_Splash'
  ClientHeight = 400
  ClientWidth = 496
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesktopCenter
  OnShow = FormShow
  TextHeight = 15
  object Image1: TImage
    Left = -42
    Top = -2
    Width = 539
    Height = 403
    Stretch = True
  end
  object ProgressBar1: TProgressBar
    Left = 128
    Top = 288
    Width = 257
    Height = 17
    TabOrder = 0
  end
  object Timer1: TTimer
    Interval = 50
    OnTimer = Timer1Timer
    Left = 16
    Top = 328
  end
end
