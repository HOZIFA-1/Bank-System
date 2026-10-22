#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <string>

#include "clsString.h"

using namespace std;

class clsTime {
 private:
  short _Second = 0;
  short _Minute = 0;
  short _Hour = 6;

 public:
  clsTime() {
    time_t t = time(0);
    tm* now = localtime(&t);

    _Hour = now->tm_hour;
    _Minute = now->tm_min;
    _Second = now->tm_sec;
  }

  clsTime(short Second, short Minute, short Hour) {
    _Second = Second;
    _Minute = Minute;
    _Hour = Hour;
  }

  void SetSecond(short Second) { _Second = Second; }

  short GetSecond() { return _Second; }
  //__declspec(property(get = GetSecond, put = SetSecond)) short Second;

  void SetMinute(short Minute) { _Minute = Minute; }

  short GetMinute() { return _Minute; }
  //__declspec(property(get = GetMinute, put = SetMinute)) short Minute;

  void SetHour(short Hour) { _Hour = Hour; }

  short GetHour() { return _Hour; }
  //__declspec(property(get = GetHour, put = SetHour)) short Hour;

  static clsTime GetSystemTime() {
    time_t t = time(0);
    tm* now = localtime(&t);
    short Second, Minute, Hour;

    Hour = now->tm_hour;
    Minute = now->tm_min;
    Second = now->tm_sec;
    return clsTime(Second, Minute, Hour);
  }

  static string TimeToString(clsTime Time) {
    return to_string(Time.GetHour()) + ":" + to_string(Time.GetMinute()) + ":" +
           to_string(Time.GetSecond());
  }

  string TimeToString() { return TimeToString(*this); }
};