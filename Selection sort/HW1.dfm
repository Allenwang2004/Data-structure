object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 450
  ClientWidth = 1290
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1290
    Height = 450
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 1284
    ExplicitHeight = 441
    object TabSheet1: TTabSheet
      Caption = 'Line'
      object Label2: TLabel
        Left = 200
        Top = 70
        Width = 36
        Height = 13
        Caption = 'range='
      end
      object Label3: TLabel
        Left = 680
        Top = 107
        Width = 40
        Height = 13
        Caption = 'Target='
      end
      object Label4: TLabel
        Left = 64
        Top = 107
        Width = 60
        Height = 13
        Caption = 'repeatition='
      end
      object Label5: TLabel
        Left = 272
        Top = 107
        Width = 29
        Height = 13
        Caption = 'step='
      end
      object Label1: TLabel
        Left = 64
        Top = 70
        Width = 14
        Height = 13
        Caption = 'n='
      end
      object Edit2: TEdit
        Left = 242
        Top = 67
        Width = 73
        Height = 21
        TabOrder = 0
        Text = '1000'
      end
      object Button1: TButton
        Left = 64
        Top = 152
        Width = 161
        Height = 25
        Caption = 'Generate Random Numbers'
        TabOrder = 1
        OnClick = Button1Click
      end
      object Memo1: TMemo
        Left = 64
        Top = 200
        Width = 161
        Height = 201
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssVertical
        TabOrder = 2
      end
      object Button2: TButton
        Left = 272
        Top = 152
        Width = 161
        Height = 25
        Caption = 'Selction Sort'
        TabOrder = 3
        OnClick = Button2Click
      end
      object Memo2: TMemo
        Left = 272
        Top = 200
        Width = 161
        Height = 201
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssVertical
        TabOrder = 4
      end
      object CheckBox1: TCheckBox
        Left = 352
        Top = 68
        Width = 105
        Height = 19
        Caption = 'Echo print'
        Ctl3D = True
        ParentCtl3D = False
        TabOrder = 5
        WordWrap = True
      end
      object CheckBox2: TCheckBox
        Left = 480
        Top = 69
        Width = 161
        Height = 17
        Caption = 'Self Check'
        Checked = True
        State = cbChecked
        TabOrder = 6
      end
      object Memo3: TMemo
        Left = 480
        Top = 200
        Width = 161
        Height = 201
        Lines.Strings = (
          'Memo3')
        ScrollBars = ssVertical
        TabOrder = 7
      end
      object Memo4: TMemo
        Left = 680
        Top = 200
        Width = 161
        Height = 201
        Lines.Strings = (
          'Memo4')
        ScrollBars = ssVertical
        TabOrder = 8
      end
      object Memo5: TMemo
        Left = 872
        Top = 200
        Width = 161
        Height = 201
        Lines.Strings = (
          'Memo5')
        ScrollBars = ssVertical
        TabOrder = 9
      end
      object Edit3: TEdit
        Left = 726
        Top = 104
        Width = 106
        Height = 21
        TabOrder = 10
        Text = '200'
      end
      object Button3: TButton
        Left = 480
        Top = 152
        Width = 161
        Height = 25
        Caption = 'Bubble sort'
        TabOrder = 11
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 680
        Top = 152
        Width = 161
        Height = 25
        Caption = 'Binary search'
        TabOrder = 12
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 872
        Top = 152
        Width = 161
        Height = 25
        Caption = 'Merge sort'
        TabOrder = 13
        OnClick = Button5Click
      end
      object Edit4: TEdit
        Left = 130
        Top = 104
        Width = 95
        Height = 21
        TabOrder = 14
        Text = '5'
      end
      object Edit5: TEdit
        Left = 307
        Top = 104
        Width = 121
        Height = 21
        TabOrder = 15
        Text = '1000'
      end
      object Edit1: TEdit
        Left = 84
        Top = 67
        Width = 69
        Height = 21
        TabOrder = 16
        Text = '10'
      end
      object Button6: TButton
        Left = 1064
        Top = 152
        Width = 161
        Height = 25
        Caption = 'Quick sort'
        TabOrder = 17
        OnClick = Button6Click
      end
      object Memo6: TMemo
        Left = 1064
        Top = 200
        Width = 161
        Height = 201
        Lines.Strings = (
          'Memo6')
        ScrollBars = ssVertical
        TabOrder = 18
      end
      object Button7: TButton
        Left = 480
        Top = 102
        Width = 161
        Height = 25
        Caption = 'Load Chart'
        TabOrder = 19
        OnClick = Button7Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Chart'
      ImageIndex = 1
      object PageControl3: TPageControl
        Left = 0
        Top = 0
        Width = 169
        Height = 422
        Align = alLeft
        TabOrder = 0
      end
      object RadioButton1: TRadioButton
        Left = 37
        Top = 32
        Width = 100
        Height = 30
        Caption = '  Line'
        TabOrder = 1
        OnClick = RadioButton1Click
      end
      object RadioButton2: TRadioButton
        Left = 37
        Top = 96
        Width = 100
        Height = 17
        Caption = '  Bar'
        TabOrder = 2
        OnClick = RadioButton2Click
      end
      object RadioButton3: TRadioButton
        Left = 37
        Top = 152
        Width = 100
        Height = 17
        Caption = 'Area'
        TabOrder = 3
        OnClick = RadioButton3Click
      end
      object RadioButton4: TRadioButton
        Left = 37
        Top = 216
        Width = 100
        Height = 17
        Caption = 'Point'
        TabOrder = 4
        OnClick = RadioButton4Click
      end
      object RadioButton5: TRadioButton
        Left = 37
        Top = 280
        Width = 100
        Height = 17
        Caption = 'Pie'
        TabOrder = 6
        OnClick = RadioButton5Click
      end
      object Button8: TButton
        Left = 37
        Top = 336
        Width = 100
        Height = 25
        Caption = 'Clear'
        TabOrder = 5
        OnClick = Button8Click
      end
    end
  end
end