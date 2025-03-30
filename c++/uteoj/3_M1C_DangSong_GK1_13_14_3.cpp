    #include<iostream>
    #include<vector>
    using namespace std;

    int checkWave(vector<int> a,int size);

    int main()
    {
        int size;
        cin >> size;
        vector<int> a(size);

        for(int i=0; i<size ; i++)
        {
            cin >> a[i];
        }

        cout << checkWave(a,size);

        return 0;
    }


    bool SimpleCheck(int a, int b , int c)
    {
        return ( (a<b && b>c) || (b<a && b<c) );
    }

    int checkWave(vector<int> a,int size)
    {
        for(int i=1 ; i<size-1;i++)
        {
            if(SimpleCheck(a[i-1],a[i],a[i+1]))
            {
                continue;
            }
            else return i;
        }
        return -1;
    }