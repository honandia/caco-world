object FormScores: TFormScores
  Left = 605
  Top = 194
  BorderStyle = bsDialog
  Caption = 'Hi Scores'
  ClientHeight = 313
  ClientWidth = 209
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
  object Label1: TLabel
    Left = 0
    Top = 0
    Width = 209
    Height = 23
    Align = alTop
    Alignment = taCenter
    Caption = 'Mejores Puntuaciones'
    Font.Charset = ANSI_CHARSET
    Font.Color = clYellow
    Font.Height = -16
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object BotonAceptar: TButton
    Left = 64
    Top = 280
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
    TabOrder = 0
    OnClick = BotonAceptarClick
    OnMouseMove = BotonAceptarMouseMove
  end
  object TextoPuntos: TMemo
    Left = 16
    Top = 40
    Width = 177
    Height = 225
    Alignment = taCenter
    BorderStyle = bsNone
    Color = clGreen
    Font.Charset = ANSI_CHARSET
    Font.Color = clYellow
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    Lines.Strings = (
      '')
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
  end
end
