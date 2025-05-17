#include<iostream>
using namespace std;

bool isLeap(int y)
{
    return (y%400 == 0 || (y%4 == 0 && y%100!= 0));
}

int MaxDay(int m, int y)
{
    const int MaxDay[] = {31, 31, -1 , 31, 30, 31, 30,31,31,30,31,30,31,31};
    if(m!= 2) return MaxDay[m];
    else if(isLeap(y)) return 29;
    else return 28;
}

bool isValidDay(int d, int m , int y)
{
    if(d < 0 || d > MaxDay(m,y)) return false;
    if(m < 0 || m > 12) return false;
    else return true;
}

struct Date
{
public:
    int day = 0;
    int month = 0;
    int year = 0;
    bool valid = true;
    Date(){};
    Date(int a , int b , int c){
        if(!isValidDay(a,b,c))
        {
            this->valid = false;
            cout << "Date kh hop le";
            return;
        }

        this->day = a;
        this->month = b;
        this-> year = c;
    }

    friend ostream &operator<<(ostream& os, Date d)
    {
        if(!d.valid)
        {
            cout << "InValid Date!\n";
            return os;
        }
        os << "Day: " << d.day << " Month: "<< d.month << " Year: " << d.year<< endl; 
        return os;
    }
    friend istream& operator>>(istream& is, Date& d)
    {
        cin >> d.day >> d.month >> d.year;
        return is;
    }
    void Format(Date &d)
    {
        while (d.day > MaxDay(d.month,d.year))
            day -= MaxDay(d.month++,d.year);
        
        while(d.month > 12){
            d.year ++;
            d.month -= 12;
        }
    }
};

int main()
{
    Date d1;
    cin >> d1;
    cout << d1;
    return 0;
}