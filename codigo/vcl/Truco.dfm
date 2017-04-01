object FormTruco: TFormTruco
  Left = 239
  Top = 195
  BorderStyle = bsDialog
  Caption = 'Truco!!'
  ClientHeight = 114
  ClientWidth = 170
  Color = clGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 0
    Width = 170
    Height = 21
    Caption = '¿Cuántas vidas quieres?'
    Font.Charset = ANSI_CHARSET
    Font.Color = clYellow
    Font.Height = -15
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object UpDown1: TUpDown
    Left = 48
    Top = 40
    Width = 17
    Height = 25
    Min = 0
    Position = 0
    TabOrder = 0
    Wrap = False
    OnClick = UpDown1Click
  end
  object Button1: TButton
    Left = 48
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Aceptar'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object ENumero: TEdit
    Left = 72
    Top = 40
    Width = 49
    Height = 24
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    Text = '3'
  end
end
