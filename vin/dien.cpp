#include<iostream>
using namespace std;

long long int TienDien(long long kwh)
{
    long long int tien = 0;
    while(kwh > 0)
    {
        if( kwh >= 401 ) tien+= 2871;
        else if (kwh >= 301) tien+= 2780;
        else if (kwh >= 201) tien+= 2487;
        else if (kwh >= 101) tien+= 1976;
        else if (kwh >= 51) tien+= 1701;
        else tien += 1646;
        kwh--;
    }
    return tien;
}

void PrintSoKWH(int tien)
{
    int i=1;
    while(true)
    {
        if(TienDien(i) < tien)
        {
            //cout << TienDien(i)<<endl;
            i++;
        }
        else
        {
            printf("So kwh: %d - %d\n",i,TienDien(i));
            return;
        }
    }
}
int main()
{
    int tar = 467658;
    cout <<"============TIEN DIEN=============\n";
    PrintSoKWH(tar);
    // tien tu lanh
    cout << "Tu lanh 1 thang  : " << TienDien(29) << endl;
    // Tien may giac
    cout << "May giac 1 thang : " << TienDien(32) << endl;
    // may quat + sac pin
    cout << "May quat + sac dt: " << TienDien(16) << endl;
    // bong den
    cout << "den              : " << TienDien(10) << endl;
    // am nuoc sieu toc
    cout << "Am nuoc sieu toc : " << TienDien(5)  << endl;
    // bep dien
    cout << "Bep dien         : " << TienDien(45) << endl;
    // hut mui
    cout << "Hut mui          : " << TienDien(22) << endl;
    // may lanh
    cout << "May lanh 1 ngay 8 tieng : 400k" << endl;


    cout << "Tong (kh may lanh): " << TienDien(29+32+16+10+5+45+22) << endl;
    cout <<"==================================\n";
    return 0;
}