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
    vector<int> treo,colap,vong,songsong;

	for(int i=0 ; i<n ; i++)
    {
        int sum = 0;
        for(int j=0 ; j<n ; j++)
		{
            sum+= a[i][j];

			if(i==j && a[i][j]==1)
				vong.push_back(i);
			else if(a[i][j]==a[j][i] && a[i][j]>=2)
                songsong.push_back(i);
        }
        if(sum == 0)
            colap.push_back(i);
        else if(sum == 1)
            treo.push_back(i);
    }
		



    // cout
    if(songsong.size())
    {
        cout << "Dinh song song: ";
        for(auto i : songsong)
            cout << i << ' ';
        cout << endl;
    }
    if(vong.size())
    {
        cout << "Dinh vong: ";
        for(auto i : vong)
            cout << i << ' ';
        cout << endl;
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