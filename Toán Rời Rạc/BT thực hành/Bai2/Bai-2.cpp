// Lưu y: các đỉnh bắt đầu từ 0 đến n-1

#include<iostream>
#include<vector>
using namespace std;
int n;  // số đỉnh
int main()
{
    freopen("bai-2.inp","r",stdin);  
    freopen("task.out", "w",stdout); 
    cin >> n;                       // đọc số đỉnh
    vector<vector<int>> a(n,vector<int>(n)); // tạo ma trận kề
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
            cin >> a[i][j];  
    vector<int> treo,colap,vong;
    vector<vector<int>> songsong(2, vector<int>(10000));
    int k=0;
	for(int i=0 ; i<n ; i++)
    {
        if(a[i][i] >= 1) vong.push_back(i);
        int sum = 0;
        for(int j=0 ; j<n ; j++)
		{
            sum+= a[i][j];
			if(a[i][j]==a[j][i] && a[i][j]>=2 && i!=j)
            {
                songsong[0][k]=i;
                songsong[1][k]=j;
                k++;
            }
        }
        if(sum == 0)
            colap.push_back(i);
        else if(sum == 1)
            treo.push_back(i);
    }
		

    // cout
    if(songsong.size())
    {
        cout << "Canh song song: ";
        for(int i=0; i<k;i++)
            cout << songsong[0][i]<<'-'<<songsong[1][i]<< ' ';
        cout << endl;
    } else cout << "Canh song song: Khong co"<<endl;
    if(vong.size())
    {
        cout << "Dinh vong: ";
        for(auto i : vong)
            cout << i << ' ';
        cout << endl;
    } else cout << "Dinh vong: Khong co"<<endl;
    if(treo.size())
    {
        cout << "Dinh treo: ";
        for(auto i : treo)
            cout << i << ' ';
        cout << endl;
    } else cout << "Dinh treo: Khong co"<<endl;
    if(colap.size())
    {
        cout << "Dinh co lap: ";
        for(auto i : colap)
            cout << i << ' ';
    } else cout << "Dinh co lap: Khong co";
    return 0;
}