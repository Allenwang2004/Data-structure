object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 503
  ClientWidth = 838
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 20
    Top = 53
    Width = 21
    Height = 15
    Caption = 'n = '
  end
  object Label2: TLabel
    Left = 20
    Top = 96
    Width = 87
    Height = 15
    Caption = 'Starting position'
  end
  object Label3: TLabel
    Left = 19
    Top = 133
    Width = 60
    Height = 15
    Caption = '(  X  , Y  ) = '
  end
  object Label4: TLabel
    Left = 84
    Top = 133
    Width = 80
    Height = 15
    Caption = '(           ,            )'
  end
  object Label5: TLabel
    Left = 20
    Top = 256
    Width = 21
    Height = 15
    Caption = 'X = '
  end
  object Label6: TLabel
    Left = 20
    Top = 285
    Width = 21
    Height = 15
    Caption = 'Y = '
  end
  object Label7: TLabel
    Left = 19
    Top = 18
    Width = 119
    Height = 15
    Caption = 'Size of the checkboard'
  end
  object Label8: TLabel
    Left = 20
    Top = 424
    Width = 43
    Height = 15
    Caption = 'If n > 12'
  end
  object PageControl1: TPageControl
    AlignWithMargins = True
    Left = 179
    Top = 3
    Width = 656
    Height = 497
    ActivePage = TabSheet1
    Align = alRight
    TabOrder = 0
    ExplicitLeft = 184
    ExplicitHeight = 413
    object TabSheet1: TTabSheet
      Caption = 'Tour in Memo'
      object Memo1: TMemo
        Left = -4
        Top = 0
        Width = 649
        Height = 580
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
  object Edit1: TEdit
    Left = 59
    Top = 50
    Width = 94
    Height = 23
    TabOrder = 1
  end
  object Edit2: TEdit
    Left = 91
    Top = 130
    Width = 29
    Height = 23
    TabOrder = 2
  end
  object Edit3: TEdit
    Left = 126
    Top = 130
    Width = 33
    Height = 23
    TabOrder = 3
  end
  object Button1: TButton
    Left = 20
    Top = 376
    Width = 145
    Height = 25
    Caption = 'Knight  Tour Step by Step'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 20
    Top = 216
    Width = 145
    Height = 25
    Caption = 'Random Position'
    TabOrder = 5
    OnClick = Button2Click
  end
  object Edit4: TEdit
    Left = 59
    Top = 253
    Width = 94
    Height = 23
    TabOrder = 6
  end
  object Edit5: TEdit
    Left = 59
    Top = 282
    Width = 94
    Height = 23
    TabOrder = 7
  end
  object CheckBox1: TCheckBox
    Left = 20
    Top = 176
    Width = 97
    Height = 17
    Caption = 'Random Position'
    TabOrder = 8
  end
  object Button3: TButton
    Left = 20
    Top = 328
    Width = 145
    Height = 25
    Caption = 'Knight Tour'
    TabOrder = 9
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 20
    Top = 456
    Width = 144
    Height = 25
    Caption = 'Find solution'
    TabOrder = 10
    OnClick = Button4Click
  end
end
