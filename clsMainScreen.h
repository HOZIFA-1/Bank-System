#pragma once
#include <iomanip>
#include <iostream>

#include "Global.h"
#include "clsAddNewClientScreen.h"
#include "clsClientListScreen.h"
#include "clsDeleteClient.h"
#include "clsFindClientScreen.h"
#include "clsInputValidate.h"
#include "clsLoginRegisterScreen.h"
#include "clsManageUsers.h"
#include "clsScreen.h"
#include "clsTransactionsScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsCurrencyExchangeScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
  enum enMainMenueOptions
  {
    eListClients = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClient = 4,
    eFindClient = 5,
    eShowTransactionsMenue = 6,
    eManageUsers = 7,
    eLoginRegister = 8,
    eCurrencyExchange = 9,
    eExit = 10
  };

  static string _PrintIfCanAccessOrNot(clsUser::enPermissions Permission, string sign = "*")
  {

    return CurrentUser.CheckAccessPermission(Permission) ? sign : "";
  }

  static short _ReadMainMenueOption()
  {
    cout << setw(37) << left << ""
         << "Choose what do you want to do? [1 to 10]? ";
    short Choice = clsInputValidate::ReadShortNumberBetween(
        1, 10, "Enter Number between 1 to 10? ");
    return Choice;
  }

  static void _GoBackToMainMenue()
  {
    cout << setw(37) << left << ""
         << "\n\tPress any key to go back to Main Menue...\n";

    cin.ignore();
    cin.get();
    ShowMainMenue();
  }

  static void _ShowAllClientsScreen()
  {
    // cout << "\nClient List Screen Will be here...\n";
    clsClientListScreen::ShowClientsList();
  }

  static void _ShowAddNewClientsScreen()
  {
    // cout << "\nAdd New Client Screen Will be here...\n";
    clsAddNewClientScreen::ShowAddNewClientScreen();
  }

  static void _ShowDeleteClientScreen()
  {
    // cout << "\nDelete Client Screen Will be here...\n";
    clsDeleteClient::ShowDeleteClientScreen();
  }

  static void _ShowUpdateClientScreen()
  {
    // cout << "\nUpdate Client Screen Will be here...\n";
    clsUpdateClientScreen::ShowUpdateClientScreen();
  }

  static void _ShowFindClientScreen()
  {
    // cout << "\nFind Client Screen Will be here...\n";
    clsFindClientScreen::ShowFindClientScreen();
  }

  static void _ShowTransactionsMenue()
  {
    // cout << "\nTransactions Menue Will be here...\n";
    clsTransactionsScreen::ShowTransactionsMenue();
  }

  static void _ShowManageUsersMenue()
  {
    // cout << "\nUsers Menue Will be here...\n";
    clsManageUsersScreen::ShowManageUsersMenue();
  }

  static void _ShowLoginRegisterScreen()
  {
    // cout << "\nLogin Register Will be here...\n";
    clsLoginRegisterScreen::ShowLoginRegisterList();
  }

  static void _ShowCurrencyExchangeMenue()
  {
    // cout << "\n Currency Exchange Will be here...\n";
    clsCurrencyExchangeScreen::ShowCurrencyExchangeMenue();
  }

  static void _LoginOut() { CurrentUser = clsUser::Find("", ""); }

  static void _PerformMainMenueOption(enMainMenueOptions MainMenueOption)
  {
    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:
    {
      system("cls");
      _ShowAllClientsScreen();
      _GoBackToMainMenue();
      break;
    }
    case enMainMenueOptions::eAddNewClient:
      system("cls");
      _ShowAddNewClientsScreen();
      _GoBackToMainMenue();
      break;

    case enMainMenueOptions::eDeleteClient:
      system("cls");
      _ShowDeleteClientScreen();
      _GoBackToMainMenue();
      break;

    case enMainMenueOptions::eUpdateClient:
      system("cls");
      _ShowUpdateClientScreen();
      _GoBackToMainMenue();
      break;

    case enMainMenueOptions::eFindClient:
      system("cls");
      _ShowFindClientScreen();
      _GoBackToMainMenue();
      break;

    case enMainMenueOptions::eShowTransactionsMenue:
      system("cls");
      _ShowTransactionsMenue();
      _GoBackToMainMenue();
      break;

    case enMainMenueOptions::eManageUsers:
      system("cls");
      _ShowManageUsersMenue();
      _GoBackToMainMenue();
      break;

    case enMainMenueOptions::eLoginRegister:
      system("cls");
      _ShowLoginRegisterScreen();
      _GoBackToMainMenue();
      break;
    case enMainMenueOptions::eCurrencyExchange:
      system("cls");
      _ShowCurrencyExchangeMenue();
      _GoBackToMainMenue();
      break;

    case enMainMenueOptions::eExit:
      system("cls");
      _LoginOut();
      break;
    }
  }

public:
  static void ShowMainMenue()
  {
    system("cls");
    _DrawScreenHeader("\t\tMain Screen");
    cout << left;
    cout << setw(37) << " " << "===========================================\n";
    cout << setw(37) << " " << "\t\t\tMain Menue\n";
    cout << setw(37) << " " << "===========================================\n";
    cout << setw(37) << " " << _PrintIfCanAccessOrNot(clsUser::enPermissions::pListClients) << "\t[1] Show Client List.\n";
    cout << setw(37) << " " << _PrintIfCanAccessOrNot(clsUser::enPermissions::pAddNewClient) << "\t[2] Add New Client.\n";
    cout << setw(37) << " " << _PrintIfCanAccessOrNot(clsUser::enPermissions::pDeleteClient) << "\t[3] Delete Client.\n";
    cout << setw(37) << " " << _PrintIfCanAccessOrNot(clsUser::enPermissions::pUpdateClients) << "\t[4] Update Client Info.\n";
    cout << setw(37) << " " << _PrintIfCanAccessOrNot(clsUser::enPermissions::pFindClient) << "\t[5] Find Client.\n";
    cout << setw(37) << " " << _PrintIfCanAccessOrNot(clsUser::enPermissions::pTranactions) << "\t[6] Transactions.\n";
    cout << setw(37) << " " << _PrintIfCanAccessOrNot(clsUser::enPermissions::pManageUsers) << "\t[7] Manage Users.\n";
    cout << setw(37) << " " << _PrintIfCanAccessOrNot(clsUser::enPermissions::pShowLogInRegister) << "\t[8] Login Register.\n";
    cout << setw(37) << " " << _PrintIfCanAccessOrNot(clsUser::enPermissions::pCurrencyExchange) << "\t[9] Currency Exchange.\n";
    cout << setw(37) << " " << "\t[10] Logout.\n";
    cout << setw(37) << " " << "===========================================\n";

    _PerformMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
  }
};
