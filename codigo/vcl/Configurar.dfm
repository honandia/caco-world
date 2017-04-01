object FormConfigurar: TFormConfigurar
  Left = 605
  Top = 194
  BorderStyle = bsDialog
  Caption = 'Configurar'
  ClientHeight = 199
  ClientWidth = 189
  Color = clGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnMouseMove = FormMouseMove
  PixelsPerInch = 96
  TextHeight = 13
  object RadioGroup1: TRadioGroup
    Left = 10
    Top = 16
    Width = 169
    Height = 73
    Caption = 'Video'
    Font.Charset = ANSI_CHARSET
    Font.Color = clYellow
    Font.Height = -16
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
  end
  object RBPantalla: TRadioButton
    Left = 34
    Top = 64
    Width = 113
    Height = 17
    Cursor = crHandPoint
    Caption = 'Pantalla completa'
    Font.Charset = ANSI_CHARSET
    Font.Color = clYellow
    Font.Height = -11
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
  object RBVentana: TRadioButton
    Left = 34
    Top = 40
    Width = 113
    Height = 17
    Cursor = crHandPoint
    Caption = 'Modo Ventana'
    Checked = True
    Font.Charset = ANSI_CHARSET
    Font.Color = clYellow
    Font.Height = -11
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    TabStop = True
  end
  object Button2: TButton
    Left = 57
    Top = 168
    Width = 75
    Height = 25
    Cursor = crHandPoint
    Caption = 'Aceptar'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -12
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
    OnMouseMove = Button2MouseMove
  end
  object GBMusica: TGroupBox
    Left = 10
    Top = 104
    Width = 169
    Height = 49
    Caption = 'Sonido'
    Font.Charset = ANSI_CHARSET
    Font.Color = clYellow
    Font.Height = -16
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    object CBMusica: TCheckBox
      Left = 24
      Top = 24
      Width = 97
      Height = 17
      Cursor = crHandPoint
      Caption = 'Música'
      Checked = True
      Font.Charset = ANSI_CHARSET
      Font.Color = clYellow
      Font.Height = -11
      Font.Name = 'Comic Sans MS'
      Font.Style = [fsBold]
      ParentFont = False
      State = cbChecked
      TabOrder = 0
    end
  end
end
