#include<bits/stdc++.h>
using namespace std;
int cd(char a)
{
	int cd=0;
	if (int(a)==65)
	cd=10;
	else if (int(a)==66)
	cd=11;
	else if (int(a)==67)
	cd=12;
	else if (int(a)==68)
	cd=13;
	else if (int(a)==69)
	cd=14;
	else if (int(a)==70)
	cd=15;
	else cd=int(a)-48;
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
		chuoi10=chuoi10+(cd(chuoi[i])*pow(16,j)); 
		j--;
	}
	while (chuoi10>0)
	{
		k=chuoi10%2;
		if (k==1)
		chuoi2=chuoi2+char(49);
		else 
		chuoi2=chuoi2+char(48);
		chuoi10=chuoi10/2;
	}
	for (int l=chuoi2.length()-1;l>=0;l--)
	chuoi2s=chuoi2s+chuoi2[l];
	cout<<chuoi2s;
	return 0;
}