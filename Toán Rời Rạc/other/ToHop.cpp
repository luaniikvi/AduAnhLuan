#include"Func.h"
using namespace std;
int main()
{
    cout << "n ptu chon m\n";
    int m,n;cout << "nhap m ,n: "; cin >> m >> n;
    vector<int> s(m);
    for(int i=0 ; i<m ; i++) s[i] = i+1; 
    Print(s);
    int j = 0;
    for(int i=0 ; i<min(m,n)-1 ; i++)
        if(s[i] != n-m+i+1 ) j = i;
    s[j]++;
    for (int r = j+1; r < m; r++)
    {
        s[r] = s[r-1]+1;
    }
    Print(s);
    
    return 0;
}