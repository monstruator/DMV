object Form1: TForm1
  Left = 202
  Top = 131
  Width = 1143
  Height = 858
  Caption = 'P32 v2.7'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object L_READY: TLabel
    Left = 824
    Top = 88
    Width = 142
    Height = 20
    Caption = #1055#1088#1080#1073#1086#1088' '#1085#1077' '#1075#1086#1090#1086#1074
    Color = clRed
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Label48: TLabel
    Left = 376
    Top = 8
    Width = 76
    Height = 24
    Caption = #1057#1055#1048#1040#1050' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label45: TLabel
    Left = 824
    Top = 120
    Width = 137
    Height = 16
    Caption = #1062#1042#1052'-'#1040'('#1054') '#1085#1077' '#1075#1086#1090#1086#1074
    Color = clRed
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Label49: TLabel
    Left = 824
    Top = 144
    Width = 140
    Height = 16
    Caption = #1062#1042#1052'-'#1040'('#1047')  '#1085#1077' '#1075#1086#1090#1086#1074
    Color = clRed
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Label47: TLabel
    Left = 824
    Top = 168
    Width = 140
    Height = 16
    Caption = #1062#1042#1052'-'#1040'('#1047')  '#1085#1077' '#1075#1086#1090#1086#1074
    Color = clRed
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object PageControl1: TPageControl
    Left = 24
    Top = 32
    Width = 761
    Height = 729
    ActivePage = HF_sheet
    TabIndex = 0
    TabOrder = 0
    OnChange = PageControl1Change
    object HF_sheet: TTabSheet
      Caption = #1057#1042#1063
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      OnEnter = HF_sheetEnter
      object Label2: TLabel
        Left = 4
        Top = 555
        Width = 84
        Height = 20
        Caption = 'CC 1...15'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold, fsItalic]
        ParentFont = False
        Visible = False
      end
      object Label4: TLabel
        Left = 170
        Top = 553
        Width = 86
        Height = 20
        Caption = #1052#1048' 1...15'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold, fsItalic]
        ParentFont = False
        Visible = False
      end
      object HF_points: TGroupBox
        Left = 8
        Top = 96
        Width = 313
        Height = 89
        Caption = #1056#1072#1073#1086#1095#1080#1077' '#1090#1086#1095#1082#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Visible = False
        object Label54: TLabel
          Left = 7
          Top = 63
          Width = 22
          Height = 16
          Caption = '1-7'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label55: TLabel
          Left = 33
          Top = 63
          Width = 22
          Height = 16
          Caption = '2-8'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label56: TLabel
          Left = 65
          Top = 63
          Width = 22
          Height = 16
          Caption = '3-9'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label57: TLabel
          Left = 91
          Top = 63
          Width = 30
          Height = 16
          Caption = '4-10'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label58: TLabel
          Left = 130
          Top = 63
          Width = 30
          Height = 16
          Caption = '5-11'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label59: TLabel
          Left = 163
          Top = 63
          Width = 30
          Height = 16
          Caption = '6-12'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object T1_7: TRadioButton
          Left = 7
          Top = 42
          Width = 20
          Height = 14
          TabOrder = 0
        end
        object T2_8: TRadioButton
          Left = 39
          Top = 42
          Width = 14
          Height = 14
          TabOrder = 1
        end
        object T3_9: TRadioButton
          Left = 65
          Top = 42
          Width = 20
          Height = 14
          TabOrder = 2
        end
        object T4_10: TRadioButton
          Left = 98
          Top = 42
          Width = 20
          Height = 14
          TabOrder = 3
        end
        object T5_11: TRadioButton
          Left = 137
          Top = 42
          Width = 20
          Height = 14
          TabOrder = 4
        end
        object T6_12: TRadioButton
          Left = 169
          Top = 42
          Width = 20
          Height = 14
          TabOrder = 5
        end
        object B_rab_t: TButton
          Left = 219
          Top = 42
          Width = 61
          Height = 20
          Caption = #1042#1042#1054#1044
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 6
          OnClick = B_rab_tClick
        end
      end
      object HF_oslab: TGroupBox
        Left = 12
        Top = 189
        Width = 309
        Height = 60
        Caption = #1054#1089#1083#1072#1073#1083#1077#1085#1080#1077
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Visible = False
        object B_O: TButton
          Left = 219
          Top = 20
          Width = 61
          Height = 20
          Caption = #1042#1042#1054#1044
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = B_OClick
        end
        object E_Os: TCSpinEdit
          Left = 40
          Top = 26
          Width = 45
          Height = 30
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          MaxValue = 25
          ParentFont = False
          TabOrder = 1
          Value = 25
        end
      end
      object HF_data: TGroupBox
        Left = 12
        Top = 263
        Width = 309
        Height = 66
        Caption = #1044#1072#1085#1085#1099#1077
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        Visible = False
        object Label63: TLabel
          Left = 46
          Top = 39
          Width = 32
          Height = 16
          Caption = #1056#1051#1048
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label64: TLabel
          Left = 7
          Top = 39
          Width = 31
          Height = 16
          Caption = 'TK'#1048
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object TKI: TRadioButton
          Left = 7
          Top = 26
          Width = 20
          Height = 14
          TabOrder = 0
        end
        object RLI: TRadioButton
          Left = 52
          Top = 26
          Width = 20
          Height = 14
          TabOrder = 1
        end
        object B_TKI: TButton
          Left = 219
          Top = 26
          Width = 59
          Height = 20
          Caption = #1042#1042#1054#1044
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
          OnClick = B_TKIClick
        end
      end
      object HF_rabota: TGroupBox
        Left = 4
        Top = 336
        Width = 317
        Height = 65
        Caption = #1056#1072#1073#1086#1090#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        Visible = False
        object B_rab: TButton
          Left = 219
          Top = 20
          Width = 61
          Height = 20
          Caption = #1042#1042#1054#1044
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = B_rabClick
        end
      end
      object HF_fk: TGroupBox
        Left = 4
        Top = 408
        Width = 317
        Height = 73
        Caption = #1060#1091#1085#1082#1094#1080#1086#1085#1072#1083#1100#1085#1099#1081' '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        Visible = False
        object Label76: TLabel
          Left = 124
          Top = 39
          Width = 5
          Height = 24
        end
        object B_FK: TButton
          Left = 229
          Top = 42
          Width = 60
          Height = 20
          Caption = #1042#1042#1054#1044
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = B_FKClick
        end
        object E_FUNC: TCSpinEdit
          Left = 48
          Top = 24
          Width = 49
          Height = 34
          MaxValue = 12
          TabOrder = 1
        end
      end
      object HF_m: TGroupBox
        Left = 8
        Top = 480
        Width = 313
        Height = 73
        Caption = #1052'-'#1087#1086#1089#1083#1077#1076#1086#1074#1072#1090#1077#1083#1100#1085#1086#1089#1090#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
        Visible = False
        object Label79: TLabel
          Left = 7
          Top = 49
          Width = 21
          Height = 16
          Caption = #1052'1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label80: TLabel
          Left = 39
          Top = 49
          Width = 21
          Height = 16
          Caption = #1052'2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label81: TLabel
          Left = 72
          Top = 49
          Width = 21
          Height = 16
          Caption = #1052'3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          Visible = False
        end
        object Label82: TLabel
          Left = 111
          Top = 49
          Width = 21
          Height = 16
          Caption = #1052'4'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          Visible = False
        end
        object M1: TRadioButton
          Left = 7
          Top = 28
          Width = 20
          Height = 13
          TabOrder = 0
        end
        object M2: TRadioButton
          Left = 39
          Top = 28
          Width = 14
          Height = 13
          TabOrder = 1
        end
        object B_M: TButton
          Left = 229
          Top = 20
          Width = 60
          Height = 20
          Caption = #1042#1042#1054#1044
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
          OnClick = B_MClick
        end
        object M3: TRadioButton
          Left = 72
          Top = 24
          Width = 17
          Height = 17
          Caption = 'M3'
          TabOrder = 3
          Visible = False
        end
        object M4: TRadioButton
          Left = 112
          Top = 24
          Width = 17
          Height = 17
          Caption = 'M4'
          TabOrder = 4
          Visible = False
        end
      end
      object E_PPR: TEdit
        Left = 10
        Top = 583
        Width = 59
        Height = 24
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        MaxLength = 2
        ParentFont = False
        TabOrder = 6
        Text = '1'
        Visible = False
      end
      object B_PPR: TButton
        Left = 85
        Top = 589
        Width = 61
        Height = 20
        Caption = #1042#1042#1054#1044
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 7
        Visible = False
        OnClick = B_PPRClick
      end
      object E_MI: TEdit
        Left = 170
        Top = 582
        Width = 59
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        MaxLength = 2
        ParentFont = False
        TabOrder = 8
        Text = '1'
        Visible = False
      end
      object B_MI: TButton
        Left = 237
        Top = 592
        Width = 61
        Height = 16
        Caption = #1042#1042#1054#1044
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 9
        Visible = False
        OnClick = B_MIClick
      end
      object HF_prm: TGroupBox
        Left = 12
        Top = 628
        Width = 301
        Height = 53
        Caption = #1055#1077#1088#1077#1082#1083#1102#1095#1077#1085#1080#1077' '#1090#1088#1072#1082#1090#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 10
        Visible = False
        object Label6: TLabel
          Left = 7
          Top = 33
          Width = 34
          Height = 16
          Caption = #1055#1056#1052
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label7: TLabel
          Left = 59
          Top = 33
          Width = 32
          Height = 16
          Caption = #1055#1056#1044
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object PRM: TRadioButton
          Left = 13
          Top = 20
          Width = 20
          Height = 13
          TabOrder = 0
        end
        object PRD: TRadioButton
          Left = 65
          Top = 20
          Width = 14
          Height = 13
          TabOrder = 1
        end
        object B_PRM: TButton
          Left = 227
          Top = 28
          Width = 61
          Height = 20
          Caption = #1042#1042#1054#1044
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
          OnClick = B_PRMClick
        end
      end
      object HW_receive: TGroupBox
        Left = 336
        Top = 88
        Width = 401
        Height = 593
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 11
        Visible = False
        object Label3: TLabel
          Left = 7
          Top = 44
          Width = 45
          Height = 20
          Caption = #1062#1055#1055' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label8: TLabel
          Left = 7
          Top = 78
          Width = 38
          Height = 20
          Caption = #1055#1056#1044
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label11: TLabel
          Left = 7
          Top = 112
          Width = 39
          Height = 20
          Caption = #1055#1056#1052
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label12: TLabel
          Left = 7
          Top = 146
          Width = 75
          Height = 20
          Caption = #1058#1050#1048'/'#1056#1051#1048
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label13: TLabel
          Left = 7
          Top = 188
          Width = 126
          Height = 20
          Caption = #1056#1072#1073#1086#1095#1072#1103' '#1090#1086#1095#1082#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label14: TLabel
          Left = 7
          Top = 222
          Width = 105
          Height = 20
          Caption = #1054#1089#1083#1072#1073#1083#1077#1085#1080#1077
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label16: TLabel
          Left = 7
          Top = 256
          Width = 56
          Height = 20
          Caption = #1056#1077#1078#1080#1084
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label17: TLabel
          Left = 7
          Top = 290
          Width = 28
          Height = 20
          Caption = #1060#1050
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label18: TLabel
          Left = 7
          Top = 324
          Width = 83
          Height = 20
          Caption = #1052'-'#1087#1086#1089#1083#1077#1076
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label19: TLabel
          Left = 7
          Top = 358
          Width = 42
          Height = 20
          Caption = #1055#1055#1088' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label20: TLabel
          Left = 5
          Top = 392
          Width = 32
          Height = 20
          Caption = #1052#1048' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label21: TLabel
          Left = 69
          Top = 423
          Width = 321
          Height = 24
          Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103' '#1082#1086#1084#1072#1085#1076#1099
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object IPadress_HF: TLabel
          Left = 192
          Top = 544
          Width = 6
          Height = 20
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object L_port1_hf_itog: TLabel
          Left = 16
          Top = 456
          Width = 6
          Height = 20
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object L_port2_hf_itog: TLabel
          Left = 16
          Top = 488
          Width = 6
          Height = 20
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object L_port3_hf_itog: TLabel
          Left = 16
          Top = 520
          Width = 6
          Height = 20
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object L_port1_hf: TLabel
          Left = 136
          Top = 16
          Width = 5
          Height = 16
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object L_port2_hf: TLabel
          Left = 208
          Top = 16
          Width = 5
          Height = 16
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object L_port3_hf: TLabel
          Left = 280
          Top = 16
          Width = 5
          Height = 16
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object E_TKI: TEdit
          Left = 207
          Top = 40
          Width = 66
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
        end
        object E_RLI: TEdit
          Left = 207
          Top = 72
          Width = 66
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
        object E_PRM_Z: TEdit
          Left = 207
          Top = 144
          Width = 66
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
        end
        object E_PRD_Z: TEdit
          Left = 207
          Top = 106
          Width = 66
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
        end
        object E_RT: TEdit
          Left = 207
          Top = 180
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 4
        end
        object E_O: TEdit
          Left = 135
          Top = 214
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 5
        end
        object E_RAB: TEdit
          Left = 207
          Top = 248
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 6
        end
        object E_FK: TEdit
          Left = 207
          Top = 282
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 7
        end
        object E_M: TEdit
          Left = 207
          Top = 316
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 8
        end
        object E_PPR_Z: TEdit
          Left = 207
          Top = 350
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 9
        end
        object E_MI_Z: TEdit
          Left = 207
          Top = 384
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 10
        end
        object E_HF_ITOG: TEdit
          Left = 93
          Top = 450
          Width = 293
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 11
        end
        object E_PRM_Z2: TEdit
          Left = 135
          Top = 144
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 12
        end
        object E_RT2: TEdit
          Left = 135
          Top = 180
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 13
        end
        object E_O2: TEdit
          Left = 208
          Top = 214
          Width = 65
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 14
        end
        object E_RAB2: TEdit
          Left = 135
          Top = 248
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 15
        end
        object E_FK2: TEdit
          Left = 135
          Top = 282
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 16
        end
        object E_M2: TEdit
          Left = 135
          Top = 316
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 17
        end
        object E_PPRZ2: TEdit
          Left = 135
          Top = 350
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 18
        end
        object E_MI_Z2: TEdit
          Left = 135
          Top = 384
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 19
        end
        object E_HF_ITOG2: TEdit
          Left = 93
          Top = 482
          Width = 293
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 20
        end
        object E_HF_ITOG3: TEdit
          Left = 93
          Top = 514
          Width = 293
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 21
          Visible = False
        end
        object E_PRM2_Z: TEdit
          Left = 136
          Top = 104
          Width = 65
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 22
        end
        object E_PRD2_Z: TEdit
          Left = 136
          Top = 72
          Width = 65
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 23
        end
        object E_CPP2_Z: TEdit
          Left = 136
          Top = 40
          Width = 65
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 24
        end
        object E_PRD3_Z: TEdit
          Left = 279
          Top = 72
          Width = 66
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 25
          Visible = False
        end
        object E_CPP3_Z: TEdit
          Left = 279
          Top = 40
          Width = 66
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 26
          Visible = False
        end
        object E_PRM3_Z: TEdit
          Left = 280
          Top = 104
          Width = 65
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 27
          Visible = False
        end
        object E_TKI3: TEdit
          Left = 279
          Top = 144
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 28
          Visible = False
        end
        object E_RT3: TEdit
          Left = 279
          Top = 180
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 29
          Visible = False
        end
        object E_O3: TEdit
          Left = 280
          Top = 214
          Width = 65
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 30
          Visible = False
        end
        object E_RAB3: TEdit
          Left = 279
          Top = 248
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 31
          Visible = False
        end
        object E_FK3: TEdit
          Left = 279
          Top = 282
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 32
          Visible = False
        end
        object E_M3: TEdit
          Left = 279
          Top = 316
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 33
          Visible = False
        end
        object E_PPRZ3: TEdit
          Left = 279
          Top = 350
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 34
          Visible = False
        end
        object E_MI_Z3: TEdit
          Left = 279
          Top = 384
          Width = 66
          Height = 28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 35
          Visible = False
        end
      end
      object GroupBox19: TGroupBox
        Left = 345
        Top = 21
        Width = 336
        Height = 60
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 12
        object B_zapros: TButton
          Left = 8
          Top = 23
          Width = 113
          Height = 34
          Caption = #1047#1072#1087#1088#1086#1089
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = B_zaprosClick
        end
      end
      object GroupBox1: TGroupBox
        Left = 8
        Top = 8
        Width = 313
        Height = 73
        Caption = #1042#1099#1073#1086#1088' '#1062#1055#1055
        TabOrder = 13
        object CPP1: TRadioButton
          Left = 16
          Top = 32
          Width = 73
          Height = 17
          Caption = #1062#1055#1055'1'
          Checked = True
          TabOrder = 0
          TabStop = True
        end
        object CPP2: TRadioButton
          Left = 160
          Top = 32
          Width = 81
          Height = 17
          Caption = #1062#1055#1055'2'
          TabOrder = 1
        end
      end
    end
    object DMW_sheet: TTabSheet
      Caption = #1044#1052#1042
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ImageIndex = 1
      ParentFont = False
      object Panel2: TPanel
        Left = 320
        Top = 8
        Width = 425
        Height = 653
        TabOrder = 0
        object GroupBox17: TGroupBox
          Left = 12
          Top = 21
          Width = 381
          Height = 60
          Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          object TLabel
            Left = 8
            Top = 96
            Width = 5
            Height = 24
          end
          object Control: TButton
            Left = 7
            Top = 26
            Width = 98
            Height = 27
            Caption = #1050#1086#1085#1090#1088#1086#1083#1100
            TabOrder = 0
            OnClick = ControlClick
          end
        end
        object DMW_receive: TGroupBox
          Left = -8
          Top = 153
          Width = 401
          Height = 480
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
          Visible = False
          object Label35: TLabel
            Left = 13
            Top = 46
            Width = 39
            Height = 20
            Caption = #1055#1056#1052
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            Visible = False
          end
          object Label36: TLabel
            Left = 13
            Top = 85
            Width = 32
            Height = 16
            Caption = #1055#1056#1044
            Visible = False
          end
          object Label37: TLabel
            Left = 13
            Top = 124
            Width = 49
            Height = 16
            Caption = #1056#1077#1078#1080#1084
          end
          object Label38: TLabel
            Left = 13
            Top = 156
            Width = 46
            Height = 16
            Caption = #1050#1072#1085#1072#1083
          end
          object Label39: TLabel
            Left = 13
            Top = 221
            Width = 74
            Height = 16
            Caption = #1052#1086#1097#1085#1086#1089#1090#1100
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label40: TLabel
            Left = 13
            Top = 189
            Width = 70
            Height = 16
            Caption = #1057#1082#1086#1088#1086#1089#1090#1100
          end
          object Label41: TLabel
            Left = 117
            Top = 267
            Width = 242
            Height = 16
            Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103' '#1082#1086#1084#1072#1085#1076#1099
          end
          object peerport: TLabel
            Left = 32
            Top = 432
            Width = 6
            Height = 20
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object IPadress: TLabel
            Left = 280
            Top = 448
            Width = 5
            Height = 16
          end
          object L_port1_itog: TLabel
            Left = 32
            Top = 296
            Width = 5
            Height = 16
          end
          object L_port2_itog: TLabel
            Left = 32
            Top = 336
            Width = 5
            Height = 16
            Visible = False
          end
          object L_port3_itog: TLabel
            Left = 32
            Top = 376
            Width = 5
            Height = 16
            Visible = False
          end
          object L_port1_dmw: TLabel
            Left = 169
            Top = 88
            Width = 35
            Height = 16
            Caption = 'P999'
          end
          object L_port2_dmw: TLabel
            Left = 253
            Top = 88
            Width = 5
            Height = 16
            Visible = False
          end
          object L_port3_dmw: TLabel
            Left = 336
            Top = 88
            Width = 5
            Height = 16
            Visible = False
          end
          object E_prm: TEdit
            Left = 144
            Top = 47
            Width = 65
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            Visible = False
          end
          object E_prd: TEdit
            Left = 144
            Top = 86
            Width = 65
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            Visible = False
          end
          object E_frch: TEdit
            Left = 144
            Top = 124
            Width = 65
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 2
          end
          object E_kan: TEdit
            Left = 144
            Top = 156
            Width = 65
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 3
          end
          object E_power: TEdit
            Left = 144
            Top = 221
            Width = 65
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 4
          end
          object E_ck: TEdit
            Left = 144
            Top = 189
            Width = 65
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 5
          end
          object E_itog: TEdit
            Left = 144
            Top = 290
            Width = 241
            Height = 31
            AutoSize = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 6
          end
          object E_itog2: TEdit
            Left = 144
            Top = 330
            Width = 241
            Height = 31
            AutoSize = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 7
            Visible = False
          end
          object E_itog3: TEdit
            Left = 144
            Top = 370
            Width = 241
            Height = 31
            AutoSize = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 8
            Visible = False
          end
          object E_prm2: TEdit
            Left = 240
            Top = 47
            Width = 57
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 9
            Visible = False
          end
          object E_prd2: TEdit
            Left = 240
            Top = 86
            Width = 57
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 10
            Visible = False
          end
          object E_frch2: TEdit
            Left = 240
            Top = 124
            Width = 57
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 11
            Visible = False
          end
          object E_kan2: TEdit
            Left = 240
            Top = 156
            Width = 57
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 12
            Visible = False
          end
          object E_ck2: TEdit
            Left = 240
            Top = 189
            Width = 57
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 13
            Visible = False
          end
          object E_power2: TEdit
            Left = 240
            Top = 221
            Width = 57
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 14
            Visible = False
          end
          object E_prm3: TEdit
            Left = 320
            Top = 47
            Width = 57
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 15
            Visible = False
          end
          object E_prd3: TEdit
            Left = 320
            Top = 86
            Width = 57
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 16
            Visible = False
          end
          object E_frch3: TEdit
            Left = 320
            Top = 124
            Width = 57
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 17
            Visible = False
          end
          object E_kan3: TEdit
            Left = 320
            Top = 156
            Width = 57
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 18
            Visible = False
          end
          object E_ck3: TEdit
            Left = 320
            Top = 189
            Width = 57
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 19
            Visible = False
          end
          object E_power3: TEdit
            Left = 320
            Top = 221
            Width = 57
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 20
            Visible = False
          end
        end
      end
      object DMW_send: TPanel
        Left = -8
        Top = 8
        Width = 329
        Height = 641
        Caption = 'Panel1'
        TabOrder = 1
        object GroupBox3: TGroupBox
          Left = 29
          Top = 18
          Width = 267
          Height = 66
          Caption = #1042#1082#1083#1102#1095#1077#1085#1080#1077
          Color = clBtnFace
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 0
          object Label9: TLabel
            Left = 13
            Top = 46
            Width = 30
            Height = 16
            Caption = #1042#1050#1051
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label10: TLabel
            Left = 59
            Top = 46
            Width = 41
            Height = 16
            Caption = #1054#1058#1050#1051
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object on_dmw1: TRadioButton
            Left = 20
            Top = 26
            Width = 20
            Height = 14
            TabOrder = 0
          end
          object off_dmw: TRadioButton
            Left = 72
            Top = 26
            Width = 20
            Height = 14
            TabOrder = 1
          end
          object B_on: TButton
            Left = 195
            Top = 26
            Width = 61
            Height = 20
            Caption = #1042#1042#1054#1044
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 2
            OnClick = B_onClick
          end
        end
        object GroupBox4: TGroupBox
          Left = 29
          Top = 90
          Width = 267
          Height = 65
          Caption = #1048#1079#1083#1091#1095#1077#1085#1080#1077
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          object Label22: TLabel
            Left = 13
            Top = 46
            Width = 32
            Height = 16
            Caption = #1040#1053#1058
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label23: TLabel
            Left = 59
            Top = 46
            Width = 31
            Height = 16
            Caption = #1069#1050#1042
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object ant: TRadioButton
            Left = 20
            Top = 26
            Width = 13
            Height = 14
            TabOrder = 0
          end
          object ekv: TRadioButton
            Left = 72
            Top = 26
            Width = 20
            Height = 14
            Checked = True
            TabOrder = 1
            TabStop = True
          end
          object B_ant: TButton
            Left = 202
            Top = 20
            Width = 52
            Height = 20
            Caption = #1042#1042#1054#1044
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 2
            Visible = False
            OnClick = B_antClick
          end
        end
        object Panel7: TPanel
          Left = 24
          Top = 160
          Width = 281
          Height = 249
          TabOrder = 2
          object GroupBox5: TGroupBox
            Left = 5
            Top = 169
            Width = 267
            Height = 66
            Caption = #1056#1077#1078#1080#1084
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            object Label24: TLabel
              Left = 7
              Top = 46
              Width = 33
              Height = 16
              Caption = #1060#1056#1063
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object Label25: TLabel
              Left = 52
              Top = 46
              Width = 43
              Height = 16
              Caption = #1055#1055#1056#1063
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object frch: TRadioButton
              Left = 20
              Top = 26
              Width = 20
              Height = 14
              TabOrder = 0
            end
            object pprch: TRadioButton
              Left = 72
              Top = 26
              Width = 20
              Height = 14
              TabOrder = 1
            end
            object B_frch: TButton
              Left = 202
              Top = 26
              Width = 52
              Height = 20
              Caption = #1042#1042#1054#1044
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              ParentFont = False
              TabOrder = 2
              OnClick = B_frchClick
            end
          end
          object GroupBox6: TGroupBox
            Left = 5
            Top = 89
            Width = 268
            Height = 72
            Caption = #1056#1072#1073#1086#1095#1080#1081' '#1082#1072#1085#1072#1083
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            object Label85: TLabel
              Left = 173
              Top = 0
              Width = 93
              Height = 24
              Caption = #1052#1086#1097#1085#1086#1089#1090#1100
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -19
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
            end
            object RK: TCSpinEdit
              Left = 13
              Top = 26
              Width = 52
              Height = 30
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              MaxValue = 39
              ParentFont = False
              TabOrder = 0
            end
            object power: TCSpinEdit
              Left = 213
              Top = 26
              Width = 44
              Height = 30
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              MaxValue = 3
              ParentFont = False
              TabOrder = 1
            end
          end
          object GroupBox7: TGroupBox
            Left = 5
            Top = 12
            Width = 267
            Height = 69
            Caption = #1057#1082#1086#1088#1086#1089#1090#1100
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            object Label26: TLabel
              Left = 0
              Top = 46
              Width = 33
              Height = 16
              Caption = '1200'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object Label27: TLabel
              Left = 39
              Top = 46
              Width = 33
              Height = 16
              Caption = '2400'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object Label28: TLabel
              Left = 85
              Top = 46
              Width = 33
              Height = 16
              Caption = '4800'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object Label29: TLabel
              Left = 124
              Top = 46
              Width = 41
              Height = 16
              Caption = '16000'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object ck1200: TRadioButton
              Left = 13
              Top = 33
              Width = 27
              Height = 13
              TabOrder = 0
            end
            object ck2400: TRadioButton
              Left = 52
              Top = 33
              Width = 20
              Height = 13
              TabOrder = 1
            end
            object RadioButton39: TRadioButton
              Left = 91
              Top = 33
              Width = 92
              Height = 13
              TabOrder = 2
            end
            object ck4800: TRadioButton
              Left = 91
              Top = 33
              Width = 20
              Height = 13
              TabOrder = 3
            end
            object ck16000: TRadioButton
              Left = 137
              Top = 33
              Width = 20
              Height = 13
              TabOrder = 4
            end
          end
        end
        object GroupBox15: TGroupBox
          Left = 24
          Top = 411
          Width = 280
          Height = 54
          Caption = #1055#1077#1088#1077#1076#1072#1095#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          object Label30: TLabel
            Left = 7
            Top = 39
            Width = 30
            Height = 16
            Caption = #1042#1050#1051
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label31: TLabel
            Left = 46
            Top = 39
            Width = 41
            Height = 16
            Caption = #1054#1058#1050#1051
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object on_prd: TRadioButton
            Left = 13
            Top = 26
            Width = 27
            Height = 14
            TabOrder = 0
          end
          object off_prd: TRadioButton
            Left = 59
            Top = 26
            Width = 26
            Height = 14
            TabOrder = 1
          end
          object B_prd: TButton
            Left = 202
            Top = 20
            Width = 52
            Height = 20
            Caption = #1042#1042#1054#1044
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 2
            OnClick = B_prdClick
          end
        end
      end
    end
    object TabSheet1: TTabSheet
      Caption = #1056' '#1042#1042#1054#1044
      ImageIndex = 2
      object Label43: TLabel
        Left = 88
        Top = 64
        Width = 117
        Height = 16
        Caption = #1053#1086#1084#1077#1088' '#1082#1086#1084#1072#1085#1076#1099
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label44: TLabel
        Left = 184
        Top = 120
        Width = 20
        Height = 16
        Caption = #1055'1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label53: TLabel
        Left = 184
        Top = 160
        Width = 20
        Height = 16
        Caption = #1055'2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label60: TLabel
        Left = 184
        Top = 192
        Width = 20
        Height = 16
        Caption = #1055'3'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label61: TLabel
        Left = 184
        Top = 240
        Width = 20
        Height = 16
        Caption = #1055'4'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label62: TLabel
        Left = 184
        Top = 272
        Width = 20
        Height = 16
        Caption = #1055'5'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label83: TLabel
        Left = 232
        Top = 403
        Width = 278
        Height = 20
        Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103' '#1082#1086#1084#1072#1085#1076#1099
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label84: TLabel
        Left = 256
        Top = 24
        Width = 231
        Height = 24
        Caption = #1042#1074#1086#1076' '#1082#1086#1084#1072#1085#1076#1099' '#1074#1088#1091#1095#1085#1091#1102
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object W_Ep1: TEdit
        Left = 232
        Top = 112
        Width = 65
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        Text = '0'
      end
      object W_Ep2: TEdit
        Left = 232
        Top = 152
        Width = 65
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        Text = '0'
      end
      object W_Ep3: TEdit
        Left = 232
        Top = 192
        Width = 65
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        Text = '0'
      end
      object W_Ep4: TEdit
        Left = 232
        Top = 232
        Width = 65
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        Text = '0'
      end
      object W_Ep5: TEdit
        Left = 232
        Top = 272
        Width = 65
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        Text = '0'
      end
      object W_B: TButton
        Left = 224
        Top = 328
        Width = 89
        Height = 33
        Caption = #1042#1042#1054#1044
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        OnClick = W_BClick
      end
      object W_Enk: TEdit
        Left = 232
        Top = 64
        Width = 65
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
        Text = '0'
      end
      object E_W_ITOG: TEdit
        Left = 232
        Top = 442
        Width = 249
        Height = 31
        AutoSize = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 7
      end
      object E_W_ITOG2: TEdit
        Left = 232
        Top = 490
        Width = 249
        Height = 31
        AutoSize = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 8
      end
      object E_W_ITOG3: TEdit
        Left = 232
        Top = 538
        Width = 249
        Height = 31
        AutoSize = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 9
        Visible = False
      end
    end
  end
  object OUT_1: TButton
    Left = 842
    Top = 20
    Width = 98
    Height = 59
    Caption = #1042#1067#1061#1054#1044
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = OUT_1Click
  end
  object Button3: TButton
    Left = 816
    Top = 192
    Width = 193
    Height = 57
    Caption = #1053#1072#1089#1090#1088#1086#1080#1090#1100' '#1072#1076#1088#1077#1089#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = Button3Click
  end
  object Panel_Tuning: TPanel
    Left = 784
    Top = 488
    Width = 265
    Height = 265
    TabOrder = 3
    Visible = False
    object Label1: TLabel
      Left = 10
      Top = 9
      Width = 31
      Height = 16
      Caption = 'IP  1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label15: TLabel
      Left = 11
      Top = 41
      Width = 46
      Height = 16
      Caption = #1055'op'#1090'1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label46: TLabel
      Left = 10
      Top = 80
      Width = 31
      Height = 16
      Caption = 'IP  2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label50: TLabel
      Left = 11
      Top = 113
      Width = 46
      Height = 16
      Caption = #1055#1086#1088#1090'2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label51: TLabel
      Left = 11
      Top = 193
      Width = 46
      Height = 16
      Caption = #1055#1086#1088#1090'3'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label52: TLabel
      Left = 10
      Top = 160
      Width = 31
      Height = 16
      Caption = 'IP  3'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Combo_IP: TComboBox
      Left = 104
      Top = 9
      Width = 153
      Height = 24
      Hint = '192.168.1.35'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ItemHeight = 16
      MaxLength = 15
      ParentFont = False
      TabOrder = 0
      Text = '192.168.1.35'
      Items.Strings = (
        '192.168.1.35'
        '192.168.1.16'
        '192.168.1.135'
        '')
    end
    object Combo_port: TComboBox
      Left = 184
      Top = 41
      Width = 73
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ItemHeight = 16
      MaxLength = 4
      ParentFont = False
      TabOrder = 1
      Text = '4003'
      OnChange = Combo_portChange
      OnKeyPress = Combo_portKeyPress
      Items.Strings = (
        '4000'
        '4001'
        '4002'
        '4003'
        '4004'
        '4005'
        '4006'
        '4007'
        '4008'
        '4009'
        '4010')
    end
    object Combo_IP2: TComboBox
      Left = 104
      Top = 73
      Width = 153
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ItemHeight = 16
      MaxLength = 15
      ParentFont = False
      TabOrder = 2
      Text = '192.168.1.35'
      Items.Strings = (
        '192.168.1.35'
        '192.168.1.16'
        '192.168.1.135')
    end
    object Combo_port2: TComboBox
      Left = 184
      Top = 105
      Width = 73
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ItemHeight = 16
      MaxLength = 4
      ParentFont = False
      TabOrder = 3
      Text = '4005'
      Items.Strings = (
        '4001'
        '4002'
        '4003'
        '4004'
        '4005'
        '4006'
        '4007'
        '4008'
        '4009'
        '4010')
    end
    object Button2: TButton
      Left = 80
      Top = 216
      Width = 129
      Height = 41
      Caption = #1053#1040#1057#1058#1056#1054#1049#1050#1040
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnClick = Button2Click
    end
    object Combo_port3: TComboBox
      Left = 184
      Top = 185
      Width = 73
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ItemHeight = 16
      MaxLength = 4
      ParentFont = False
      TabOrder = 5
      Text = '4007'
      Visible = False
      Items.Strings = (
        '4001'
        '4002'
        '4003'
        '4004'
        '4005'
        '4006'
        '4007'
        '4008'
        '4009'
        '4010')
    end
    object Combo_IP3: TComboBox
      Left = 104
      Top = 153
      Width = 153
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ItemHeight = 16
      MaxLength = 15
      ParentFont = False
      TabOrder = 6
      Text = '192.168.1.35'
      Visible = False
      Items.Strings = (
        '192.168.1.35'
        '192.168.1.16'
        '192.168.1.135')
    end
    object chkChannel3: TCheckBox
      Left = 8
      Top = 136
      Width = 65
      Height = 17
      Caption = #1050#1072#1085#1072#1083' 3'
      TabOrder = 7
      OnClick = chkChannel3Click
    end
  end
  object P_com: TPanel
    Left = 792
    Top = 256
    Width = 329
    Height = 233
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    object Label65: TLabel
      Left = 8
      Top = 72
      Width = 61
      Height = 24
      Caption = 'C'#1095' '#1082#1086#1084
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label66: TLabel
      Left = 8
      Top = 104
      Width = 58
      Height = 24
      Caption = #8470' '#1082#1086#1084
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label67: TLabel
      Left = 8
      Top = 136
      Width = 89
      Height = 24
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label68: TLabel
      Left = 6
      Top = 168
      Width = 107
      Height = 24
      Caption = #1050#1086#1076' '#1079#1072#1074#1077#1088#1096
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label71: TLabel
      Left = 6
      Top = 200
      Width = 107
      Height = 24
      Caption = #1050#1086#1076' '#1086#1096#1080#1073#1082#1080
    end
    object Label78: TLabel
      Left = 96
      Top = 8
      Width = 167
      Height = 24
      Caption = #1055#1088#1080#1085#1103#1090#1072#1103' '#1082#1086#1084#1072#1085#1076#1072
    end
    object Label42: TLabel
      Left = 16
      Top = 40
      Width = 78
      Height = 24
      Caption = #8470' '#1087#1086#1088#1090#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object L_port1: TLabel
      Left = 120
      Top = 40
      Width = 5
      Height = 24
    end
    object L_port2: TLabel
      Left = 184
      Top = 40
      Width = 5
      Height = 24
    end
    object L_port3: TLabel
      Left = 248
      Top = 40
      Width = 5
      Height = 24
    end
    object E_cr_com: TEdit
      Left = 120
      Top = 64
      Width = 49
      Height = 32
      TabOrder = 0
    end
    object E_num_com: TEdit
      Left = 120
      Top = 96
      Width = 49
      Height = 32
      TabOrder = 1
    end
    object E_param: TEdit
      Left = 120
      Top = 128
      Width = 49
      Height = 32
      TabOrder = 2
    end
    object E_kzv: TEdit
      Left = 120
      Top = 160
      Width = 49
      Height = 32
      TabOrder = 3
    end
    object E_k_o: TEdit
      Left = 120
      Top = 192
      Width = 49
      Height = 32
      TabOrder = 4
    end
    object E_cr_com2: TEdit
      Left = 184
      Top = 64
      Width = 49
      Height = 32
      TabOrder = 5
    end
    object E_num_com2: TEdit
      Left = 184
      Top = 96
      Width = 49
      Height = 32
      TabOrder = 6
    end
    object E_param2: TEdit
      Left = 184
      Top = 128
      Width = 49
      Height = 32
      TabOrder = 7
    end
    object E_kzv2: TEdit
      Left = 184
      Top = 160
      Width = 49
      Height = 32
      TabOrder = 8
    end
    object E_k_o2: TEdit
      Left = 184
      Top = 192
      Width = 49
      Height = 32
      TabOrder = 9
    end
    object E_cr_com3: TEdit
      Left = 248
      Top = 64
      Width = 49
      Height = 32
      TabOrder = 10
      Visible = False
    end
    object E_num_com3: TEdit
      Left = 248
      Top = 96
      Width = 49
      Height = 32
      TabOrder = 11
      Visible = False
    end
    object E_param3: TEdit
      Left = 248
      Top = 128
      Width = 49
      Height = 32
      TabOrder = 12
      Visible = False
    end
    object E_kzv3: TEdit
      Left = 248
      Top = 160
      Width = 49
      Height = 32
      TabOrder = 13
      Visible = False
    end
    object E_k_o3: TEdit
      Left = 248
      Top = 192
      Width = 49
      Height = 32
      TabOrder = 14
      Visible = False
    end
  end
  object E_SS0: TEdit
    Left = 968
    Top = 48
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object T_PPR: TTimer
    Enabled = False
    Interval = 500
    OnTimer = T_PPRTimer
    Left = 24
    Top = 768
  end
  object T_PPR2: TTimer
    Enabled = False
    Interval = 500
    OnTimer = T_PPR2Timer
    Left = 64
    Top = 768
  end
  object T_MI: TTimer
    Enabled = False
    Interval = 500
    OnTimer = T_MITimer
    Left = 104
    Top = 768
  end
  object T_MI2: TTimer
    Enabled = False
    Interval = 500
    OnTimer = T_MI2Timer
    Left = 152
    Top = 768
  end
  object udp1: TIdUDPServer
    Active = True
    BufferSize = 1472
    Bindings = <>
    DefaultPort = 4000
    OnUDPRead = udp1UDPRead
    Left = 648
    Top = 776
  end
  object T_READY: TTimer
    OnTimer = T_READYTimer
    Left = 344
    Top = 776
  end
  object T_READY_TEXT: TTimer
    Enabled = False
    OnTimer = T_READY_TEXTTimer
    Left = 392
    Top = 776
  end
  object T_READY_BLANK: TTimer
    OnTimer = T_READY_BLANKTimer
    Left = 304
    Top = 776
  end
  object Client: TIdUDPClient
    Active = True
    BufferSize = 1472
    Host = '192.168.1.35'
    Port = 4003
    ReceiveTimeout = 1000
    Left = 528
    Top = 776
  end
  object T_READ: TTimer
    Left = 440
    Top = 776
  end
  object T_CLIENT_SEND: TTimer
    Interval = 500
    OnTimer = T_CLIENT_SENDTimer
    Left = 488
    Top = 776
  end
  object Client2: TIdUDPClient
    Active = True
    BufferSize = 1472
    Host = '192.168.1.35'
    Port = 4005
    ReceiveTimeout = 1000
    Left = 568
    Top = 776
  end
  object Client3: TIdUDPClient
    Active = True
    BufferSize = 1472
    Host = '192.168.1.35'
    Port = 4007
    ReceiveTimeout = 1000
    Left = 608
    Top = 776
  end
  object T_10sec: TTimer
    Interval = 10000
    OnTimer = T_10secTimer
    Left = 712
    Top = 784
  end
  object udp2: TIdUDPServer
    Active = True
    BufferSize = 1472
    Bindings = <>
    DefaultPort = 4001
    OnUDPRead = udp2UDPRead
    Left = 776
    Top = 776
  end
  object udp3: TIdUDPServer
    Active = True
    BufferSize = 1472
    Bindings = <>
    DefaultPort = 4002
    OnUDPRead = udp3UDPRead
    Left = 832
    Top = 776
  end
end
