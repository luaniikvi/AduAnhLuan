#include<iostream>
#include<vector>
using namespace std;
int a[100][100];
int n;
int main()
{
    freopen("Bai2.inp","r",stdin);
    freopen("task.out","w",stdout);
    cin >> n;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ;j <=n ; j++)
            cin >> a[i][j];
	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j && a[i][j]==1)
				cout<<"Vi tri co vong: "<<i<<endl;
			if(a[i][j]==a[j][i] && a[i][j]>=2 &&i<j)
				cout<<"Vi tri song song la: "<<i<<" "<<j <<endl;
		}
	}
    vector<int> treo,colap;
	for(int i=1;i<=n;i++)
	{ 
	    int sum=0;
	    for(int j=1;j<=n;j++)
	    	sum+=a[i][j];
	    if(sum==1) treo.push_back(i);
	    if(sum==0) colap.push_back(i);
	}
    if(treo.size())
    {
        cout << "Dinh treo: ";
        for(auto i : treo)
            cout << i << ' ';
        cout << endl;
    }
    if(colap.size())
    {
        cout << "Dinh co lap: ";
        for(auto i : colap)
            cout << i << ' ';
    }
}