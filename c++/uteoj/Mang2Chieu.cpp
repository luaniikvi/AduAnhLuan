    #include<iostream>
    using namespace std;
    int main()
    {
        int n;cin >> n;
        int a[100][100];
        
        long long tongchiing = 0,tongbien = 0;  
        int minphu = 100000;

        for(int h = 0 ; h < n ; h++)
        {
            for(int c= 0 ; c < n ; c++)
            {
                cin >> a[h][c];
                // tong chinh
                if(h == c) tongchiing+=a[h][c];
                if(c == n-h-1) minphu = min(minphu,a[h][c]);
                if(h == 0 || c == 0 || h == n-1 || c == n -1) tongbien+=a[h][c];
            }
        }
        for(int h = 0 ; h < n ; h++)
        {
            for(int c= 0 ; c < n ; c++)
            {
                cout << a[h][c] << ' ';
            }
            cout << endl;
        }
        for(int h = 0 ; h < n ; h++)
        {
            for(int c= 0 ; c < n ; c++)
            {
                cout << a[c][h] << ' ';
            }
            cout << endl;
        }
        cout << tongchiing << endl;
        cout << minphu << endl;
        cout <<     tongbien;
    }