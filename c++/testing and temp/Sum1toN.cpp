#include<iostream>
#include<cmath>
using namespace std;

long long OverMul_Int(int tu1, int tu2, int pso)
{
    if(tu1%pso == 0) return tu1/pso*tu2;
    if(tu2%pso == 0) return tu2/pso*tu1;

    return round(tu1/(double)pso*tu2);
}

long long int Sum(int start, int end, int step)
{
    if(step != 1)
        end -= (end-start)%step;
    if(start == end) return start;
    
    int count = (end - start)/step + 1;
   
    return OverMul_Int(end+start,count,2);
}

int main()
{
    int start; cin >> start;
    int end  ; cin >> end;    
    int step ; cin >> step;
    
    cout << Sum(start,end,step);
}