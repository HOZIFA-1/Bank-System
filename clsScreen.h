#pragma once
#include <iostream>

#include "Global.h"
#include "clsDate.h"
#include "clsUser.h"

using namespace std;

class clsScreen {
 protected:
  static void _DrawScreenHeader(string Title, string SubTitle = "") {
    cout << "\t\t\t\t\t______________________________________";
    cout << "\n\n\t\t\t\t\t  " << Title;
    if (SubTitle != "") {
      cout << "\n\t\t\t\t\t  " << SubTitle;
    }
    cout << "\n\t\t\t\t\t______________________________________\n\n";
    _GetDateAndUsername();
  }

  static void _GetDateAndUsername() {
    cout << "\t\t\t\t\tUser: " << CurrentUser.GetUserName() << endl;
    cout << "\t\t\t\t\tDate:"
         << clsDate::DateToString(clsDate::GetSystemDate());
    cout << "\n\n";
  }

  static bool CheckAccessRights(clsUser::enPermissions Permission) {
    if (!CurrentUser.CheckAccessPermission(Permission)) {
      cout << "\t\t\t\t\t______________________________________";
      cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
      cout << "\n\t\t\t\t\t______________________________________\n\n";
      return false;
    } else {
      return true;
    }
  }
};
