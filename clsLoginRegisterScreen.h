#pragma once
#include <iomanip>
#include <iostream>

#include "clsScreen.h"
#include "clsUser.h"

class clsLoginRegisterScreen : protected clsScreen
{
private:
     static void _PrintLoginRegisterRecordLine(stLoginRegisterRecord Register)
     {
          cout << setw(8) << left << "" << "| " << left << setw(35)
               << Register.DateAndTime;
          cout << "| " << left << setw(20) << Register.UserName;
          cout << "| " << left << setw(20) << Register.Password;
          cout << "| " << left << setw(12) << Register.Permissions;
     }

public:
     static void ShowLoginRegisterList()
     {
          if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pShowLogInRegister))
          {
               return;
          }

          vector<stLoginRegisterRecord> vRecords = clsUser::GetLoginRegistersList();
          string Title = "\t  LoginRegiste List Screen";
          string SubTitle = "\t    (" + to_string(vRecords.size()) + ") Record(s).";

          _DrawScreenHeader(Title, SubTitle);

          cout << setw(8) << left << ""
               << "\n\t_______________________________________________________";
          cout << "_________________________________________\n"
               << endl;

          cout << setw(8) << left << "" << "| " << left << setw(35)
               << "Date/Time";
          cout << "| " << left << setw(20) << "User Name";
          cout << "| " << left << setw(20) << "Password";
          cout << "| " << left << setw(12) << "Permissions";
          cout << setw(8) << left << ""
               << "\n\t_______________________________________________________";
          cout << "_________________________________________\n"
               << endl;

          if (vRecords.size() == 0)
               cout << "\t\t\t\tNo LoginRegistes Available In the System!";
          else

               for (stLoginRegisterRecord &vRecord : vRecords)
               {
                    _PrintLoginRegisterRecordLine(vRecord);
                    cout << endl;
               }

          cout << setw(8) << left << ""
               << "\n\t_______________________________________________________";
          cout << "_________________________________________\n"
               << endl;
     }
};