#include<iostream>
#include<cmath>
using namespace std;
int cd(char a)
{
	int cd=0;
	if (a==65)
	cd=10;
	else if (a==66)
	cd=11;
	else if (a==67)
	cd=12;
	else if (a==68)
	cd=13;
	else if (a==69)
	cd=14;
	else if (a==70)
	cd=15;
	else cd=a-48;
	return cd;
}
int main()
{
	string chuoi,chuoi2,chuoi2s="";
	int j=2,k=-1;
	int chuoi10=0;
	cin>>chuoi;
	j=chuoi.length()-1;
	for (int i=0; i<chuoi.length();i++)
	{
		chuoi10 += (cd(chuoi[i])*pow(16,j)); 
		j--;
	}
    cout << "dec : " << chuoi10 << endl;
	while (chuoi10>0)
	{
		chuoi2 = char(chuoi10%2 == 0 ? '0':'1') + chuoi2;
        chuoi10/=2;
	}
	for (int l=chuoi2.length()-1;l>=0;l--)
	chuoi2s=chuoi2s+chuoi2[l];
	cout<<chuoi2s;
	return 0;
}