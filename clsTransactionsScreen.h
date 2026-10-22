#pragma once
#include <iomanip>
#include <iostream>

#include "ClsBankClient.h"
#include "clsDepositScreen.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsWhithdraw.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:
  enum enTransactionsMenueOptions
  {
    eDeposit = 1,
    eWhithdraw = 2,
    eShowTotalBalance = 3,
    eTransfer = 4,
    eTransferLog = 5,
    eShowMainMenue = 6
  };

  static short _ReadTransactionsMenueOption()
  {
    cout << setw(37) << left << ""
         << "Choose what do you want to do? [1 to 6]? ";
    short Choice = clsInputValidate::ReadShortNumberBetween(
        1, 6, "Enter Number between 1 to 6? ");
    return Choice;
  }

  static void _GoBackToTransactionsMenue()
  {
    cout << setw(37) << left << ""
         << "\n\tPress any key to go back to Transactions Menue...\n";

    cin.ignore();
    cin.get();
    ShowTransactionsMenue();
  }

  static void _ShowDepositScreen()
  {
    //  cout << "\nDeposit  Screen Will be here...\n";
    clsDepositScreen::ShowDepositScreen();
  }

  static void _ShowWhithdrawScreen()
  {
    //  cout << "\nWhithdraw  Screen Will be here...\n";
    clsWhithdraw::ShowWhithdrawScreen();
  }

  static void _ShowTotalBalanceScreen()
  {
    // cout << "\nTotal Balance Screen Will be here...\n";
    clsTotalBalancesScreen::ShowTotalBalances();
  }

  static void _ShowTransferScreen()
  {
    // cout << "\nTransfer Screen Will be here...\n";
    clsTransferScreen::ShowTransferScreen();
  }

  static void _ShowTransferLogScreen()
  {
    // cout << "\nTransfer Log Screen Will be here...\n";
    clsTransferLogScreen::ShowTransferLogScreen();
  }

  static void _PerformTransactionsMenueOption(
      enTransactionsMenueOptions TransactionsMenueOptions)
  {
    switch (TransactionsMenueOptions)
    {
    case enTransactionsMenueOptions::eDeposit:
    {
      system("clear");
      _ShowDepositScreen();
      _GoBackToTransactionsMenue();
      break;
    }
    case enTransactionsMenueOptions::eWhithdraw:
    {
      system("clear");
      _ShowWhithdrawScreen();
      _GoBackToTransactionsMenue();
      break;
    }
    case enTransactionsMenueOptions::eShowTotalBalance:
    {
      system("clear");
      _ShowTotalBalanceScreen();
      _GoBackToTransactionsMenue();
      break;
    }
    case enTransactionsMenueOptions::eTransfer:
    {
      system("clear");
      _ShowTransferScreen();
      _GoBackToTransactionsMenue();
      break;
    }
    case enTransactionsMenueOptions::eTransferLog:
    {
      system("clear");
      _ShowTransferLogScreen();
      _GoBackToTransactionsMenue();
      break;
    }

    case enTransactionsMenueOptions::eShowMainMenue:
    {
      break;
    }
    }
  }

public:
  static void ShowTransactionsMenue()
  {
    if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
      return;

    system("clear");
    _DrawScreenHeader("\tTransactions Screen");
    cout << left;
    cout << setw(37) << " " << "===========================================\n";
    cout << setw(37) << " " << "\t\tTransactions Menue\n";
    cout << setw(37) << " " << "===========================================\n";
    cout << setw(37) << " " << "\t[1] Deposit.\n";
    cout << setw(37) << " " << "\t[2] Whithdraw.\n";
    cout << setw(37) << " " << "\t[3] Total Balance.\n";
    cout << setw(37) << " " << "\t[4] Transfer.\n";
    cout << setw(37) << " " << "\t[5] Transfer Log.\n";
    cout << setw(37) << " " << "\t[6] Main Menue.\n";
    cout << setw(37) << " " << "===========================================\n";

    _PerformTransactionsMenueOption(
        (enTransactionsMenueOptions)_ReadTransactionsMenueOption());
  }
};
