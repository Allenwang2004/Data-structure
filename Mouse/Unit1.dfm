object Form1: TForm1
  Left = 603
  Top = -62
  Caption = 'Form1'
  ClientHeight = 541
  ClientWidth = 670
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 24
    Width = 185
    Height = 105
    Caption = 'Size'
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 32
      Width = 38
      Height = 13
      Caption = 'Height: '
    end
    object Label2: TLabel
      Left = 24
      Top = 64
      Width = 41
      Height = 13
      Caption = 'Weight: '
    end
    object Edit1: TEdit
      Left = 80
      Top = 29
      Width = 84
      Height = 21
      TabOrder = 0
      Text = '19'
    end
    object Edit2: TEdit
      Left = 80
      Top = 62
      Width = 84
      Height = 21
      TabOrder = 1
      Text = '19'
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 300
    Width = 185
    Height = 142
    Caption = 'Auto'
    TabOrder = 1
    object Label4: TLabel
      Left = 16
      Top = 88
      Width = 40
      Height = 13
      Caption = 'Speed : '
    end
    object Label3: TLabel
      Left = 80
      Top = 119
      Width = 21
      Height = 13
      Caption = 'Fast'
    end
    object Label5: TLabel
      Left = 133
      Top = 119
      Width = 22
      Height = 13
      Caption = 'Slow'
    end
    object Button5: TButton
      Left = 16
      Top = 24
      Width = 65
      Height = 41
      Caption = 'Find a tour'
      TabOrder = 0
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 87
      Top = 24
      Width = 85
      Height = 41
      Caption = 'Find a tour new'
      TabOrder = 1
      OnClick = Button6Click
    end
    object TrackBar1: TTrackBar
      Left = 62
      Top = 81
      Width = 110
      Height = 32
      TabOrder = 2
    end
  end
  object Button2: TButton
    Left = 8
    Top = 144
    Width = 185
    Height = 25
    Caption = 'Generate Maze'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 175
    Width = 185
    Height = 26
    Caption = 'Save Maze'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 207
    Width = 185
    Height = 27
    Caption = 'Load Maze'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Button7: TButton
    Left = 8
    Top = 240
    Width = 185
    Height = 25
    Caption = 'Clear memo'
    TabOrder = 5
    OnClick = Button7Click
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 457
    Width = 185
    Height = 69
    Caption = 'Ways'
    TabOrder = 6
  end
  object RadioButton1: TRadioButton
    Left = 25
    Top = 488
    Width = 65
    Height = 17
    Caption = '4 Ways'
    TabOrder = 7
  end
  object RadioButton2: TRadioButton
    Left = 104
    Top = 488
    Width = 76
    Height = 17
    Caption = '8 Ways'
    TabOrder = 8
  end
  object PageControl1: TPageControl
    Left = 208
    Top = 0
    Width = 462
    Height = 541
    ActivePage = TabSheet3
    Align = alRight
    TabOrder = 9
    object TabSheet1: TTabSheet
      Caption = 'Memo'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 454
        Height = 513
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'StringGird'
      ImageIndex = 1
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 454
        Height = 513
        Align = alClient
        DefaultColWidth = 15
        DefaultColAlignment = taRightJustify
        DefaultRowHeight = 15
        TabOrder = 0
        OnDrawCell = StringGrid1DrawCell
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Mouse in Maze'
      ImageIndex = 2
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 454
        Height = 513
        Align = alClient
        DefaultColWidth = 15
        DefaultRowHeight = 15
        TabOrder = 0
        OnDrawCell = StringGrid2DrawCell
      end
    end
    object TabSheet4: TTabSheet
      Caption = ' Mouse in Maze (Random color)'
      ImageIndex = 3
      object StringGrid3: TStringGrid
        Left = 0
        Top = 0
        Width = 454
        Height = 513
        Align = alClient
        DefaultColWidth = 15
        DefaultRowHeight = 15
        TabOrder = 0
        OnDrawCell = StringGrid3DrawCell
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'MovingGIrd'
      ImageIndex = 4
      OnContextPopup = TabSheet5ContextPopup
      object StringGrid4: TStringGrid
        Left = 0
        Top = 0
        Width = 454
        Height = 513
        Align = alClient
        DefaultColWidth = 15
        DefaultRowHeight = 15
        TabOrder = 0
        OnDrawCell = StringGrid4DrawCell
        OnKeyDown = StringGrid4KeyDown
      end
    end
  end
  object Button1: TButton
    Left = 8
    Top = 271
    Width = 185
    Height = 25
    Caption = 'Play'
    TabOrder = 10
    OnClick = Button1Click
  end
  object OpenDialog1: TOpenDialog
    Left = 252
    Top = 400
  end
  object SaveDialog1: TSaveDialog
    Left = 324
    Top = 400
  end
end
