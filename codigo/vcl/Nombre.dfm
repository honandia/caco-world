object FormNombre: TFormNombre
  Left = 605
  Top = 195
  BorderStyle = bsDialog
  Caption = 'Nombre'
  ClientHeight = 130
  ClientWidth = 182
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
    Width = 182
    Height = 23
    Align = alTop
    Alignment = taCenter
    Caption = 'Introduce tu nombre:'
    Font.Charset = ANSI_CHARSET
    Font.Color = clYellow
    Font.Height = -16
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object AreaTexto: TEdit
    Left = 26
    Top = 40
    Width = 129
    Height = 24
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    Text = 'JUGADOR1'
  end
  object BotonCancelar: TButton
    Left = 95
    Top = 96
    Width = 75
    Height = 25
    Cursor = crHandPoint
    Caption = 'Cancelar'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = BotonCancelarClick
    OnMouseMove = BotonCancelarMouseMove
  end
  object BotonAceptar: TButton
    Left = 12
    Top = 96
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
    TabOrder = 2
    OnClick = BotonAceptarClick
    OnMouseMove = BotonAceptarMouseMove
  end
end
