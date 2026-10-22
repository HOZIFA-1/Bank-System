#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsScreen.h"

class clsFindCurrencyScreen : protected clsScreen
{

private:
  static void PrintCurrencyCard(clsCurrency &Currency)
  {
    cout << "\n\nCurrency Card:";
    cout << "\n_____________________________________";
    cout << "\nCountry      : " << Currency.Country();
    cout << "\nCode         : " << Currency.CurrencyCode();
    cout << "\nName         : " << Currency.CurrencyName();
    cout << "\nRate(1$) =   : " << Currency.Rate();
    cout << "\n_____________________________________";
  }

  static void _ShowResults(clsCurrency Currency)
  {

    if (!Currency.IsEmpty())
    {
      cout << "\nCurrency Found :-)";
      PrintCurrencyCard(Currency);
    }
    else
    {
      cout << "\nCurrency Not Found :-(";
    }
  }

public:
  static void ShowFindCurrencyScreen()
  {
    _DrawScreenHeader("\t  Find Currency Screen");

    enum enFindOpion
    {
      eCode = 1,
      eCountry = 2
    };

    short number;
    cout << "\nFind By: [1] Code or [2] Country ? ";
    number = clsInputValidate::ReadShortNumberBetween(1, 2);

    string Code, Country;
    switch ((enFindOpion)number)
    {
    case enFindOpion::eCode:
    {
      cout << "\nPlease Enter CurrencyCode: ";
      Code = clsInputValidate::ReadString();
      clsCurrency Currency = clsCurrency::FindByCode(Code);

      _ShowResults(Currency);

      break;
    }

    case enFindOpion::eCountry:
    {
      cout << "\nPlease Enter Country: ";
      Country = clsInputValidate::ReadString();
      clsCurrency Currency = clsCurrency::FindByCountry(Country);
      _ShowResults(Currency);

      break;
    }

    default:
      break;
    }
  }
};