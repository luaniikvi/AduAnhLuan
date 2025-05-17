#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Greedy_7
{
    int j,f;
};
bool compare(const Greedy_7& g1,const Greedy_7& g2 ){
    return g1.f > g2.f;
}

int main(){
    int n;cin >> n;
    vector<Greedy_7> a(n);
    for(auto &i : a) cin >> i.j >> i.f;
    sort(a.begin() , a.end() , compare);
    
    int cur_time = 0;
    int completion_time = 0;

    for(auto i : a)
    {
        cur_time += i.j;
        completion_time = max(completion_time, cur_time + i.f) ;
    }
    cout << completion_time;
    return 0;
}