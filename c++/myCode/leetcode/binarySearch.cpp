#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(int target ,vector<int> a,int len);
int main()
{
    vector<int> a = {1,2,3,4,5,17,80,99,120,150,300,301,399}; // a[10]=300

    cout <<  "pos: ";
    cout << BinarySearch(300,a,a.size()) << endl;
    //cout << "end.";

    //return 0;
}

int BinarySearch(int target ,vector<int> a,int len)
{
    //int len = a.size();
    int L = 0;
    int R = len -1; int M;

    while(L <= R)
    {
        M  = L + (R-L)/2;
        if(a[M] == target) return M;
        else if(a[M] < target)
        {
            L = M+1;
        }
        else
        {
            R = M - 1;
        }
    }

    return -1;
}
