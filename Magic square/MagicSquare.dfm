﻿object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 422
  ClientWidth = 687
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 687
    Height = 422
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 681
    ExplicitHeight = 413
    object TabSheet1: TTabSheet
      Caption = #22855#25976#38542#23652
      object Label1: TLabel
        Left = 30
        Top = 32
        Width = 84
        Height = 13
        Caption = #36664#20837#26041#38499#30340#22823#23567
        Color = clBtnFace
        ParentColor = False
      end
      object Label2: TLabel
        Left = 30
        Top = 64
        Width = 20
        Height = 13
        Caption = 'n = '
      end
      object Label3: TLabel
        Left = 30
        Top = 96
        Width = 116
        Height = 13
        Caption = '(n'#28858'3'#21040'19'#20043#38291#30340#22855#25976')'
        Color = clBtnFace
        ParentColor = False
      end
      object Label4: TLabel
        Left = 232
        Top = 32
        Width = 48
        Height = 13
        Caption = #36215#40670#20301#32622
      end
      object Label5: TLabel
        Left = 384
        Top = 32
        Width = 48
        Height = 13
        Caption = #31227#21205#20301#32622
      end
      object PageControl2: TPageControl
        Left = 0
        Top = 168
        Width = 679
        Height = 226
        ActivePage = TabSheet4
        Align = alBottom
        TabOrder = 0
        object TabSheet4: TTabSheet
          Caption = #28961#23565#40778#26041#38499
          object Memo1: TMemo
            Left = 0
            Top = 0
            Width = 671
            Height = 198
            Align = alClient
            Lines.Strings = (
              'Memo1')
            ScrollBars = ssVertical
            TabOrder = 0
          end
        end
        object TabSheet5: TTabSheet
          Caption = #23565#40778#26041#38499
          ImageIndex = 1
          object Memo2: TMemo
            Left = 0
            Top = 0
            Width = 671
            Height = 198
            Align = alClient
            Lines.Strings = (
              'Memo2')
            ScrollBars = ssVertical
            TabOrder = 0
          end
        end
        object TabSheet6: TTabSheet
          Caption = #23565#40778#26041#38499'+'#27298#28204
          ImageIndex = 2
          object Memo3: TMemo
            Left = 0
            Top = 0
            Width = 671
            Height = 198
            Align = alClient
            Lines.Strings = (
              'Memo3')
            ScrollBars = ssVertical
            TabOrder = 0
          end
        end
        object 分格方陣: TTabSheet
          Caption = #20998#26684#26041#38499
          ImageIndex = 3
          object Memo4: TMemo
            Left = 0
            Top = 0
            Width = 671
            Height = 198
            Align = alClient
            Lines.Strings = (
              'Memo4')
            ScrollBars = ssVertical
            TabOrder = 0
          end
          object StringGrid1: TStringGrid
            Left = 0
            Top = 0
            Width = 671
            Height = 198
            Align = alClient
            TabOrder = 1
          end
        end
      end
      object Edit1: TEdit
        Left = 56
        Top = 61
        Width = 58
        Height = 21
        TabOrder = 1
        Text = '3'
      end
      object RadioButton1: TRadioButton
        Left = 248
        Top = 64
        Width = 32
        Height = 17
        Caption = #19978
        DoubleBuffered = False
        ParentDoubleBuffered = False
        TabOrder = 2
        OnClick = RadioButton1Click
      end
      object RadioButton2: TRadioButton
        Left = 248
        Top = 110
        Width = 32
        Height = 17
        Caption = #19979
        TabOrder = 3
        OnClick = RadioButton2Click
      end
      object RadioButton3: TRadioButton
        Left = 210
        Top = 87
        Width = 32
        Height = 17
        Caption = #24038
        TabOrder = 4
        OnClick = RadioButton3Click
      end
      object RadioButton4: TRadioButton
        Left = 286
        Top = 87
        Width = 32
        Height = 17
        Caption = #21491
        TabOrder = 5
        OnClick = RadioButton4Click
      end
      object RadioButton5: TRadioButton
        Left = 384
        Top = 73
        Width = 48
        Height = 16
        Caption = #24038#19978
        TabOrder = 6
        OnClick = RadioButton5Click
      end
      object RadioButton6: TRadioButton
        Left = 384
        Top = 95
        Width = 48
        Height = 17
        Caption = #24038#19979
        TabOrder = 7
        OnClick = RadioButton6Click
      end
      object RadioButton7: TRadioButton
        Left = 448
        Top = 72
        Width = 48
        Height = 17
        Caption = #21491#19978
        DoubleBuffered = False
        ParentDoubleBuffered = False
        TabOrder = 8
        OnClick = RadioButton7Click
      end
      object RadioButton8: TRadioButton
        Left = 448
        Top = 95
        Width = 48
        Height = 17
        Caption = #21491#19979
        TabOrder = 9
        OnClick = RadioButton8Click
      end
      object Button1: TButton
        Left = 536
        Top = 42
        Width = 121
        Height = 60
        Caption = #29986#29983#39764#34899#26041#38499
        TabOrder = 10
        OnClick = Button1Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = #20598#25976#38542#23652'(4'#30340#20493#25976')'
      ImageIndex = 1
      object Label6: TLabel
        Left = 38
        Top = 32
        Width = 84
        Height = 13
        Caption = #36664#20837#26041#38499#30340#22823#23567
        Color = clBtnFace
        ParentColor = False
      end
      object Label7: TLabel
        Left = 38
        Top = 68
        Width = 20
        Height = 13
        Caption = 'n = '
      end
      object Label8: TLabel
        Left = 38
        Top = 104
        Width = 86
        Height = 13
        Caption = '('#35531#36664#20837'4'#30340#20493#25976')'
      end
      object PageControl3: TPageControl
        Left = 208
        Top = 0
        Width = 471
        Height = 394
        ActivePage = TabSheet8
        Align = alRight
        TabOrder = 0
        ExplicitLeft = 202
        ExplicitHeight = 385
        object TabSheet8: TTabSheet
          Caption = #28961#23565#40778#26041#38499
          object Memo5: TMemo
            Left = 0
            Top = 0
            Width = 463
            Height = 366
            Align = alClient
            Lines.Strings = (
              'Memo5')
            TabOrder = 0
            ExplicitHeight = 357
          end
        end
        object TabSheet9: TTabSheet
          Caption = #23565#40778#26041#38499
          ImageIndex = 1
          object Memo6: TMemo
            Left = 0
            Top = 0
            Width = 463
            Height = 366
            Align = alClient
            Lines.Strings = (
              'Memo6')
            TabOrder = 0
          end
        end
        object TabSheet10: TTabSheet
          Caption = #23565#40778#26041#38499'+'#27298#39511
          ImageIndex = 2
          object Memo7: TMemo
            Left = 0
            Top = 0
            Width = 463
            Height = 366
            Align = alClient
            Lines.Strings = (
              'Memo7')
            TabOrder = 0
          end
        end
        object TabSheet11: TTabSheet
          Caption = #20998#38548#26041#38499
          ImageIndex = 3
          object Memo8: TMemo
            Left = 0
            Top = 0
            Width = 463
            Height = 366
            Align = alClient
            Lines.Strings = (
              'Memo8')
            TabOrder = 0
          end
          object StringGrid2: TStringGrid
            Left = 0
            Top = 0
            Width = 463
            Height = 366
            Align = alClient
            TabOrder = 1
          end
        end
      end
      object Edit2: TEdit
        Left = 64
        Top = 65
        Width = 58
        Height = 21
        TabOrder = 1
        Text = '4'
      end
      object Button2: TButton
        Left = 38
        Top = 142
        Width = 86
        Height = 59
        Caption = #29986#29983#39764#34899#26041#38499
        TabOrder = 2
        OnClick = Button2Click
      end
    end
  end
end