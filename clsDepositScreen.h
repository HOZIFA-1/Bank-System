#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "ClsBankClient.h"
#include "clsInputValidate.h"


class clsDepositScreen:protected clsScreen
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

	static  void ShowDepositScreen()
	{
        _DrawScreenHeader("\t Deposit  Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Not Exist , Choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

            double Amount = 0;
            cout << "\nPlrase Enter Deposit amount? : ";
            Amount = clsInputValidate::ReadDblNumber();
      
       
        cout << "\nAre you sure you want to Deposit this client y/n? : ";
        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer)=='Y')
        {
            
            Client.Deposit(Amount);
            cout << "\nAmount Deposit Successfully";
            cout << "New Balance  Is: " << Client.GetAccountBalance();
        }
        else
        {
            cout << "\nOperation was cancelled\n";
        }


	}


};

