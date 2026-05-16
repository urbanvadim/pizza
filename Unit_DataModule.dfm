object DM: TDM
  Height = 480
  Width = 640
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\'#1050#1059#1056#1057#1054#1042#1040' '#1056#1054#1041#1054#1058#1040'\P' +
      'izzeriaDB1.mdb;Mode=Share Deny None;Persist Security Info=False;' +
      'Jet OLEDB:System database="";Jet OLEDB:Registry Path="";Jet OLED' +
      'B:Database Password="";Jet OLEDB:Engine Type=5;Jet OLEDB:Databas' +
      'e Locking Mode=0;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:G' +
      'lobal Bulk Transactions=1;Jet OLEDB:New Database Password="";Jet' +
      ' OLEDB:Create System Database=False;Jet OLEDB:Encrypt Database=F' +
      'alse;Jet OLEDB:Don'#39't Copy Locale on Compact=False;Jet OLEDB:Comp' +
      'act Without Replica Repair=False;Jet OLEDB:SFP=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 552
    Top = 376
  end
  object Table_Pizzas: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    LockType = ltReadOnly
    TableName = #1055#1110#1094#1080
    Left = 64
    Top = 152
    object Table_PizzasID: TIntegerField
      FieldName = 'ID'
    end
    object Table_PizzasНазва_піци: TWideStringField
      FieldName = #1053#1072#1079#1074#1072'_'#1087#1110#1094#1080
      Size = 255
    end
    object Table_PizzasСклад: TWideStringField
      FieldName = #1057#1082#1083#1072#1076
      Size = 255
    end
    object Table_PizzasЦіна: TBCDField
      FieldName = #1062#1110#1085#1072
      Precision = 19
    end
    object Table_PizzasКатегорія: TWideStringField
      FieldName = #1050#1072#1090#1077#1075#1086#1088#1110#1103
      Size = 255
    end
    object Table_PizzasВага: TWideStringField
      FieldName = #1042#1072#1075#1072
      Size = 255
    end
    object Table_PizzasФото: TWideStringField
      FieldName = #1060#1086#1090#1086
      Size = 255
    end
  end
  object Table_Clients: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = #1050#1083#1110#1108#1085#1090#1080
    Left = 64
    Top = 40
    object Table_ClientsID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object Table_ClientsПІБ_Клієнта: TWideStringField
      FieldName = #1055#1030#1041'_'#1050#1083#1110#1108#1085#1090#1072
      Size = 255
    end
    object Table_ClientsТелефон: TWideStringField
      FieldName = #1058#1077#1083#1077#1092#1086#1085
      Size = 255
    end
    object Table_ClientsАдреса_доставки: TWideStringField
      FieldName = #1040#1076#1088#1077#1089#1072'_'#1076#1086#1089#1090#1072#1074#1082#1080
      Size = 255
    end
    object Table_ClientsЛогін: TWideStringField
      FieldName = #1051#1086#1075#1110#1085
      Size = 255
    end
    object Table_ClientsПароль: TWideStringField
      FieldName = #1055#1072#1088#1086#1083#1100
      Size = 255
    end
    object Table_ClientsБонуси: TIntegerField
      FieldName = #1041#1086#1085#1091#1089#1080
    end
  end
  object Table_Ingredients: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = #1030#1085#1075#1088#1072#1076#1110#1108#1085#1090#1080
    Left = 64
    Top = 208
  end
  object Table_PizzaIngredients: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = #1057#1082#1083#1072#1076' '#1087#1110#1094
    Left = 64
    Top = 264
  end
  object Table_Orders: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = #1047#1072#1084#1086#1074#1083#1077#1085#1085#1103
    Left = 64
    Top = 320
    object Table_OrdersID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object Table_OrdersID_Клієнта: TIntegerField
      FieldName = 'ID_'#1050#1083#1110#1108#1085#1090#1072
    end
    object Table_OrdersСума: TBCDField
      FieldName = #1057#1091#1084#1072
      Precision = 19
    end
    object Table_OrdersЧас_замовлення: TDateTimeField
      FieldName = #1063#1072#1089'_'#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
    end
    object Table_OrdersІD_працівника: TIntegerField
      FieldName = #1030'D_'#1087#1088#1072#1094#1110#1074#1085#1080#1082#1072
    end
    object Table_OrdersСума_до_оплати: TBCDField
      FieldName = #1057#1091#1084#1072'_'#1076#1086'_'#1086#1087#1083#1072#1090#1080
      Precision = 19
    end
  end
  object Table_OrderDetails: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = #1044#1077#1090#1072#1083#1110' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
    Left = 64
    Top = 376
    object Table_OrderDetailsID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object Table_OrderDetailsID_замовлення: TIntegerField
      FieldName = 'ID_'#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
    end
    object Table_OrderDetailsНазва_піци: TWideStringField
      FieldName = #1053#1072#1079#1074#1072'_'#1087#1110#1094#1080
      Size = 255
    end
    object Table_OrderDetailsЦіна_за_штуку: TWideStringField
      FieldName = #1062#1110#1085#1072'_'#1079#1072'_'#1096#1090#1091#1082#1091
      Size = 255
    end
    object Table_OrderDetailsСклад: TWideStringField
      FieldName = #1057#1082#1083#1072#1076
      Size = 255
    end
    object Table_OrderDetailsКількість: TWideStringField
      FieldName = #1050#1110#1083#1100#1082#1110#1089#1090#1100
      Size = 255
    end
    object Table_OrderDetailsФото: TWideStringField
      FieldName = #1060#1086#1090#1086
      Size = 255
    end
  end
  object Table_Employees: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = #1055#1088#1072#1094#1110#1074#1085#1080#1082#1080
    Left = 64
    Top = 96
  end
  object Pizza_constructor: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = #1030#1085#1075#1088#1072#1076#1110#1108#1085#1090#1080'_'#1050#1086#1085#1089#1090#1088#1091#1082#1090#1086#1088
    Left = 168
    Top = 40
  end
  object Query_Execute: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 464
    Top = 40
  end
  object Source_Pizzas: TDataSource
    AutoEdit = False
    DataSet = Table_Pizzas
    Left = 544
    Top = 152
  end
  object Table_Basket: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = #1050#1086#1096#1080#1082
    Left = 168
    Top = 96
    object Table_BasketID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object Table_BasketНазва_піци: TWideStringField
      FieldName = #1053#1072#1079#1074#1072'_'#1087#1110#1094#1080
      Size = 255
    end
    object Table_BasketСклад: TWideStringField
      FieldName = #1057#1082#1083#1072#1076
      Size = 255
    end
    object Table_BasketЦіна: TBCDField
      FieldName = #1062#1110#1085#1072
      Precision = 19
    end
    object Table_BasketЛогін: TWideStringField
      FieldName = #1051#1086#1075#1110#1085
      Size = 255
    end
    object Table_BasketКількість: TIntegerField
      FieldName = #1050#1110#1083#1100#1082#1110#1089#1090#1100
    end
    object Table_BasketФото_Файл: TWideStringField
      FieldName = #1060#1086#1090#1086'_'#1060#1072#1081#1083
      Size = 255
    end
  end
  object Source_Basket: TDataSource
    DataSet = Table_Basket
    Left = 544
    Top = 200
  end
  object Query_Ingredients: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 544
    Top = 40
  end
  object Source_Orders: TDataSource
    DataSet = Table_Orders
    Left = 544
    Top = 104
  end
  object Source_Details: TDataSource
    DataSet = Table_OrderDetails
    Left = 544
    Top = 248
  end
end
