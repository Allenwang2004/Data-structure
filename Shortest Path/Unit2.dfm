object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 453
  ClientWidth = 774
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 232
    Top = 0
    Width = 542
    Height = 453
    ActivePage = TabSheet1
    Align = alRight
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Graph in adjacent matrix'
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 534
        Height = 425
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'G'#39's adjacent matrix'
      ImageIndex = 1
    end
    object TabSheet3: TTabSheet
      Caption = 'SSAD tables'
      ImageIndex = 2
    end
    object TabSheet4: TTabSheet
      Caption = 'All pairs'
      ImageIndex = 3
    end
    object TabSheet5: TTabSheet
      Caption = 'All pairs table'
      ImageIndex = 4
    end
    object TabSheet6: TTabSheet
      Caption = 'TransitiveClosure'
      ImageIndex = 5
    end
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 201
    Height = 265
    Caption = 'G=(V,E)'
    TabOrder = 1
    object Label1: TLabel
      Left = 24
      Top = 32
      Width = 20
      Height = 13
      Caption = 'n = '
    end
    object Label2: TLabel
      Left = 24
      Top = 64
      Width = 72
      Height = 13
      Caption = 'range(w(e)) = '
    end
    object Label3: TLabel
      Left = 24
      Top = 96
      Width = 42
      Height = 13
      Caption = 'if w(e) >'
    end
    object Label4: TLabel
      Left = 24
      Top = 128
      Width = 36
      Height = 13
      Caption = 'w(e) = '
    end
    object Label5: TLabel
      Left = 24
      Top = 155
      Width = 62
      Height = 13
      Caption = 'Souce no. = '
    end
    object Button1: TButton
      Left = 24
      Top = 192
      Width = 153
      Height = 25
      Caption = 'Genarate G'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Edit1: TEdit
      Left = 112
      Top = 29
      Width = 78
      Height = 21
      TabOrder = 1
      Text = '5'
    end
    object Edit2: TEdit
      Left = 112
      Top = 61
      Width = 78
      Height = 21
      TabOrder = 2
      Text = '1000'
    end
    object Edit3: TEdit
      Left = 112
      Top = 93
      Width = 78
      Height = 21
      TabOrder = 3
      Text = '1000'
    end
    object Edit4: TEdit
      Left = 112
      Top = 125
      Width = 78
      Height = 21
      TabOrder = 4
      Text = '99999'
    end
    object Edit5: TEdit
      Left = 112
      Top = 152
      Width = 78
      Height = 21
      TabOrder = 5
      Text = '0'
    end
    object CheckBox1: TCheckBox
      Left = 24
      Top = 232
      Width = 97
      Height = 17
      Caption = 'Echo print'
      Checked = True
      State = cbChecked
      TabOrder = 6
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 296
    Width = 201
    Height = 149
    Caption = 'Shortest Path Solver'
    TabOrder = 2
    object CheckBox2: TCheckBox
      Left = 24
      Top = 24
      Width = 97
      Height = 17
      Caption = 'Print results'
      TabOrder = 0
    end
    object Button2: TButton
      Left = 24
      Top = 47
      Width = 153
      Height = 25
      Caption = 'Single Source All Destinations'
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 24
      Top = 78
      Width = 153
      Height = 25
      Caption = 'All Pairs'
      TabOrder = 2
    end
    object Button4: TButton
      Left = 24
      Top = 109
      Width = 153
      Height = 25
      Caption = 'Transitive Closure'
      TabOrder = 3
    end
  end
end