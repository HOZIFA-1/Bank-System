#pragma once

#include <iomanip>
#include <iostream>

#include "Global.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsUser.h"

class clsLoginScreen : protected clsScreen {
 private:
  static bool _Login() {
    bool LoginFaild = false;

    short NumberOfTrials = 3;
    string Username, Password;
    do {
      cout << "Enter Username? ";
      cin >> Username;
      cout << "Enter Password? ";
      cin >> Password;

      CurrentUser = clsUser::Find(Username, Password);

      LoginFaild = CurrentUser.IsEmpty();

      if (LoginFaild) {
        cout << "\nInvlaid Username/Password!\n";
        cout << "You have " << (NumberOfTrials -= 1) << " Trials to Login.\n\n";
      }

      if (NumberOfTrials == 0) {
        cout << "Your are Loked after 3 faild trails \n\n";
        return false;
      }

    } while (LoginFaild);
    CurrentUser.RegisterLogIn();
    clsMainScreen::ShowMainMenue();
    return true;
  }

 public:
  static bool ShowLoginScreen() {
    system("cls");
    _DrawScreenHeader("\t  Login Screen");
    return _Login();
  }
};
