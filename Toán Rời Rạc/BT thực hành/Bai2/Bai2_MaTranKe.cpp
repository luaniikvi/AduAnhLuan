// Lưu y: các đỉnh bắt đầu từ 0 đến n-1

#include<iostream>
#include<vector>
using namespace std;
int n;  // số đỉnh
int main()
{
    freopen("bai2.inp","r",stdin);  // đọc file
    freopen("task.out","w",stdout); // ghi file
    cin >> n;                       // đọc số đỉnh
    vector<vector<int>> a(n,vector<int>(n)); // tạo ma trận kề
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
            cin >> a[i][j];         // nhập ma trận kề
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
		{
            // song song
			if(i==j && a[i][j]==1)
				cout<<"Vi tri co vong: "<<i<<endl;
            // vòng
			if(a[i][j]==a[j][i] && a[i][j]>=2 &&i<j)
				cout<<"Vi tri song song la: "<< i <<" "<< j <<endl;
		}
    vector<int> treo,colap; // tạo mảng chứa các đỉnh treo và cô lập
	for(int i=1;i<=n;i++)
	{ 
	    int sum=0;
	    for(int j=1;j<=n;j++)
	    	sum+=a[i][j];
        // nếu tổng bằng 1 thì là đỉnh treo
	    if(sum==1) treo.push_back(i);
        // tổng = 0 -> cô lập
	    if(sum==0) colap.push_back(i);
	}
    // cout
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