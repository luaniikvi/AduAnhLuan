#include <iostream>
using namespace std;

bool Valid(int day, int month, int year);
bool checkLeap(int year);
int Quy(int month);
void printNgaySau(int day, int month, int year);
void printNgayTrc(int day, int month, int year);
int maxDay(int month, int year);

int main()
{
    int day, month, year;
    cin >> day >> month >> year;
    if (!Valid(day, month, year))
    {
        cout << "KHONG HOP LE";
        return 0;
    }
    else
        cout << "HOP LE" << endl;
    cout << Quy(month) << endl;
    cout << maxDay(month, year) << endl;
    printNgaySau(day, month, year);
    printNgayTrc(day, month, year);

    return 0;
}

bool checkLeap(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

bool Valid(int day, int month, int year)
{
    if (month < 1 || month > 12)
        return false;
    int maxDay[13] = {31, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    maxDay[2] = (checkLeap(year)) ? 29 : 28;
    return (day >= 1 && day <= maxDay[month]);
}

int Quy(int month)
{
    return (month - 1) / 3 + 1;
}

void printNgaySau(int day, int month, int year)
{
    int maxDay[13] = {31, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    maxDay[2] = (checkLeap(year)) ? 29 : 28;
    day++;
    if (day > maxDay[month])
    {
        day = 1;
        month++;
        if (month == 13)
        {
            month = 1;
            year++;
        }
    }
    cout << day << " " << month << " " << year << endl;
}

void printNgayTrc(int day, int month, int year)
{
    int maxDay[13] = {31, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    maxDay[2] = (checkLeap(year)) ? 29 : 28;
    day--;
    if (day == 0)
    {
        day = maxDay[month - 1];
        month--;
        if (month == 0)
        {
            month = 12;
            year--;
        }
    }

    cout << day << " " << month << " " << year;
}

int maxDay(int month, int year)
{
    int maxDay[13] = {31, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    maxDay[2] = (checkLeap(year)) ? 29 : 28;
    return maxDay[month];
}
