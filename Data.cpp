//
// Created by casde on 21.09.2021.
//

#include "Data.h"

Date::Date() {
    Day = 1, Month = 1, Year = 2007,
    Hour = 0, Minute = 0, Second = 0;
    this->str = nullptr;
    ToString();
}

Date::Date(int day, int month, int year, int hour, int minute, int second) {
    if (CheckTime(hour, minute, second) && CheckData(day, month, year)) {
        SetDay(day);
        SetMonth(month);
        SetY(year);
        SetH(hour);
        SetMinute(minute);
        SetSecond(second);
        this->str = nullptr;
        ToString();
    } else {
        Day = 1, Month = 1, Year = 2007,
        Hour = 0, Minute = 0, Second = 0;
        this->str = nullptr;
        ToString();
    }
}

/*Data::Data(char* a) {
    int size = (int)strlen(a);
    int flag = 0, p = 0;
    while (flag != 5) {
        int* m = new int[5];
        int j = 0;
        for (int i = p; i < size; i++) {
            if (a[i] == '.' || a[i] == ':' || a[i] == ' ') {
                flag++;
                p = i + 1;
                break;
            } else {
                m[j] = a[i] - '0';
                j++;
            }
        }
        for (int i = 0; i < j; i++) {

        }
    }
}*/

Date::Date(Date &a) {
    this-> Day = a.Day, this-> Month = a.Month, this-> Year = a.Year;
    this-> Hour = a.Hour, this-> Minute = a.Minute, this-> Second = a.Second;
    this->str = nullptr;
    ToString();
}

Date::~Date() {
    delete[]this->str;
}

void Date::ToString() {
    int size[6], sum = 0;
    int date[6] = { Day, Month, Year, Hour, Minute, Second };
    for (int i = 0; i < 6; i++) {
        size[i] = countCalc(date[i]);
        sum += countCalc(date[i]);
    }
    delete[] this->str;
    this->str = new char[sum + 6];
    int move = 0;
    for (int i = 0; i < 6; i++) {
        sprintf(str + move, "%d", date[i]);
        move += size[i];
        if (i < 2) {
            sprintf(str + move, "%c", '/');
            move++;
        }
        else if (i == 2) {
            sprintf(str + move, "%c", ' ');
            move++;
        }
        else if (i < 5) {
            sprintf(str + move, "%c", ':');
            move++;
        }
    }
}

int Date::countCalc(int num) {
    int len = 0;
    if (num == 0) return 1;
    while (num > 0) {
        len++;
        num = num / 10;
    }
    return len;
}

char* Date::Getstr() { // геттер строки
    return this->str;
}

void Date::SetDay(int day) {
    this-> Day = day;
}

void Date::SetMonth(int month) {
    this-> Month = month;
}

void Date::SetY(int year) {
    this-> Year = year;
}

void Date::SetH(int hour) {
    this-> Hour = hour;
}

void Date::SetMinute(int minute) {
    this-> Minute = minute;
}

void Date::SetSecond(int second) {
    this-> Second = second;
}

bool Date::CheckData(int day, int month, int year)
{
    if (year < 0 || day < 1 || month < 1 || month > 12 || !(CheckDay(day, month, year)))
        return false;
    else
        return true;
}

bool Date::CheckDay(int day, int month, int year) {
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && year % 4 == 0) {
        if (day > 29) return false;
        else return true;
    } else {
        if (day > a[month]) return false;
        else return true;
    }
}

bool Date::CheckTime(int hour, int minute, int second)
{
    if (hour >= 0  && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60)
        return true;
    else
        return false;
}

void Date::Plus(char k) {
    switch (k) {
        case 'y':
            Year++;
            break;
        case 'M':
            if (Month == 12) {
                Year++;
                Month = 1;
            } else {
                Month++;
            }
            break;
        case 'd':
            if (Day > 27)
                DayPlus();
            else
                Day++;
            break;
        case 'h':
            if (Hour == 23)
                HourPlus();
            else
                Hour++;
            break;
        case 'm':
            if (Minute == 59)
                MinutePlus();
            else
                Minute++;
            break;
        case 's':
            if (Second == 59)
                SecondPlus();
            else
                Second++;
            break;
        default:
            break;
    }
    ToString();
}

void Date::DayPlus() {
    switch (Day) {
        case 28:
            if (Month == 2 && Year % 4 != 0) {
                Day = 1;
                Month = 3;
            } else {
                Day++;
            }
            break;
        case 29:
            if (Month == 2) {
                Day = 1;
                Month = 3;
            } else {
                Day++;
            }
            break;
        case 30:
            if (Month == 4 || Month == 6 || Month == 9 || Month == 11) {
                Day = 1;
                Month++;
            } else {
                Day++;
            }
            break;
        case 31:
            if (Month == 12) {
                Day = 1;
                Month = 1;
                Year++;
            } else {
                Month++;
                Day = 1;
            }
            break;
    }
}

void Date::HourPlus() {
    if (Day < 28) {
        Day++;
        Hour = 0;
    } else {
        DayPlus();
        Hour = 0;
    }
}

void Date::MinutePlus() {
    if (Hour < 23) {
        Minute = 0;
        Hour++;
    } else {
        Minute = 0;
        HourPlus();
    }
}

void Date::SecondPlus() {
    if (Minute < 59) {
        Second = 0;
        Minute++;
    } else {
        Second = 0;
        MinutePlus();
    }
}

void Date::Minus(char k) {
    switch (k) {
        case 'y':
            if (Year != 0)
                Year--;
            break;
        case 'M':
            if (Month == 1) {
                Year--;
                Month = 12;
            } else {
                Month--;
            }
            break;
        case 'd':
            if (Day == 1)
                DayMinus();
            else
                Day--;
            break;
        case 'h':
            if (Hour == 0)
                HourMinus();
            else
                Hour--;
            break;
        case 'm':
            if (Minute == 0)
                MinuteMinus();
            else
                Minute--;
            break;
        case 's':
            if (Second == 0)
                SecondMinus();
            else
                Second--;
            break;
        default:
            break;
    }
    ToString();
}

void Date::DayMinus() {
    if (Month == 1) {
        Year--;
        Month = 12;
        Day = 31;
    } else if (Month == 3 && Year % 4 == 0) {
        Month--;
        Day = 29;
    } else if (Month == 3) {
        Month--;
        Day = 28;
    } else if (Month == 5 || Month == 7 || Month == 10 || Month == 12) {
        Month--;
        Day = 30;
    } else {
        Month--;
        Day = 31;
    }
}

void Date::HourMinus() {
    if (Day > 1) {
        Hour = 23;
        Day--;
    } else {
        Hour = 23;
        DayMinus();
    }
}

void Date::MinuteMinus() {
    if (Hour > 0) {
        Minute = 59;
        Hour--;
    } else {
        Minute = 59;
        HourMinus();
    }
}

void Date::SecondMinus() {
    if (Minute > 0) {
        Second = 59;
        Minute--;
    } else {
        Second = 59;
        MinuteMinus();
    }
}

/*void Date::Print() {
        cout << Getstr() << endl << "--------------------" << endl;
}*/