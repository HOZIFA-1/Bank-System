#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "ClsBankClient.h"
#include "clsInputValidate.h"

class clsWhithdraw :protected clsScreen
{
private:
  
   static void _PrintClient(clsBankClient& Client)
   {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";

    }
   
   static string _ReadAccountNumber()
    {
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        return AccountNumber = clsInputValidate::ReadString();
    }

public:

    static  void ShowWhithdrawScreen()
    {
        _DrawScreenHeader("\t WhitDraw  Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Not Exist , Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

         double Amount = 0;
         cout << "\nEnter The Amount you want to WhitDraw";
         Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to WhitDraw this client y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        { 
           if (Client.WhitDraw(Amount))
           {
            cout << "\nAmount WhitDraw Successfully";
            cout << "New Balance  Is: " << Client.GetAccountBalance();
           }
           
            else
           {
               cout << "\nCannot withdraw, Insuffecient Balance!\n";
               cout << "\nAmout to withdraw is: " << Amount;
               cout << "\nYour Balance is: " << Client.GetAccountBalance();
           }
           
           
        }
        else
        {
            cout << "\nOperation was cancelled\n";
        }


    }


};

