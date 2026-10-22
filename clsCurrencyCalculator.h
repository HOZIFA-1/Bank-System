#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsScreen.h"

class clsCurrencyCalculator : protected clsScreen
{

private:
    static float ReadAmount()
    {

        float Amount;
        cout << "\nEnter Amount to Exchange: ";
        Amount = clsInputValidate::ReadFloatNumber();
        return Amount;
    }

    static void PrintCurrencyCard(clsCurrency &Currency, string Tital)
    {
        cout << Tital;
        cout << "\n_____________________________________";
        cout << "\nCountry      : " << Currency.Country();
        cout << "\nCode         : " << Currency.CurrencyCode();
        cout << "\nName         : " << Currency.CurrencyName();
        cout << "\nRate(1$) =   : " << Currency.Rate();
        cout << "\n_____________________________________";
    }

    static clsCurrency GetCurrency(string Tital)
    {
        string CurrencyCode;
        cout << Tital;
        CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }

    static void PrintResult(float Amount,
                            clsCurrency Currency1, clsCurrency Currency2)
    {
        PrintCurrencyCard(Currency1, "\n\nConvert From:");

        cout << endl
             << endl
             << Amount << " " << Currency1.CurrencyCode() << " = " << Currency1.ConvertCurrncyToUSD(Amount) << " USD";
        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }

        PrintCurrencyCard(Currency2, "\n\nConverting From USD to:");
        cout << endl
             << endl
             << Amount << " " << Currency1.CurrencyCode() << " = " << Currency1.ConvertFromUSD(Amount, Currency2) << " " << Currency2.CurrencyCode();
    }

public:
    static void ShowCurrencyCalculatorScreen()
    {
        char Y_N = 'N';
        do
        {
            system("clear");
            _DrawScreenHeader("\t  Update Currency Screen");

            clsCurrency Currency1 = GetCurrency("\nPlease Enter Currency1 Code: ");
            clsCurrency Currency2 = GetCurrency("\nPlease Enter Currency2 Code: ");
            float Amount = ReadAmount();

            PrintResult(Amount, Currency1, Currency2);

            cout << "\n\n Do you want to perform another calculation? Y/n ?";
            cin >> Y_N;

        } while (toupper(Y_N) == 'Y');
    }
};