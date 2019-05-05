object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 316
  ClientWidth = 718
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object VirtualStringTree1: TVirtualStringTree
    Left = 8
    Top = 32
    Width = 481
    Height = 249
    Header.AutoSizeIndex = 0
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 0
    OnGetText = VirtualStringTree1GetText
    OnNodeClick = VirtualStringTree1NodeClick
    Columns = <
      item
        Position = 0
        Text = 'id'
        Width = 124
      end
      item
        Position = 1
        Text = 'url'
        Width = 324
      end>
  end
  object Button1: TButton
    Left = 536
    Top = 40
    Width = 161
    Height = 49
    Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1080#1089#1090#1086#1088#1080#1102
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 536
    Top = 128
    Width = 161
    Height = 41
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1079#1072#1087#1080#1089#1100' '#1087#1086#1089#1077#1097#1077#1085#1080#1103
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 536
    Top = 208
    Width = 161
    Height = 49
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1080#1089#1090#1086#1088#1080#1102' '#1087#1086#1089#1077#1097#1077#1085#1080#1081
    TabOrder = 3
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 56
    Top = 287
    Width = 225
    Height = 21
    TabOrder = 4
    Visible = False
  end
end
