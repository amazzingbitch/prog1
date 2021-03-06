//
// Created by casde on 21.09.2021.
//

#ifndef PROG1_DATA_H
#define PROG1_DATA_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
class Date {
public:
    Date();
    Date(int day, int month, int year, int hour, int minute, int second);
    Date(Date &a);
    ~Date();
    void SetDay(int day);
    void SetMonth(int month);
    void SetY(int year);
    void SetH(int hour);
    void SetMinute(int minute);
    void SetSecond(int second);
    void Plus(char k);
    void DayPlus();
    void HourPlus();
    void MinutePlus();
    void SecondPlus();
    void Minus(char k);
    void DayMinus();
    void HourMinus();
    void MinuteMinus();
    void SecondMinus();
    static int countCalc(int num);
    void ToString();
    char* GetStr();
private:
    int Day, Month, Year, Hour, Minute, Second, sizeStr;
    char* str;
    static bool CheckData(int day, int month, int year);
    static bool CheckTime(int hour, int minute, int second);
    static bool CheckDay(int day, int month, int year);
};

#endif //PROG1_DATA_H
