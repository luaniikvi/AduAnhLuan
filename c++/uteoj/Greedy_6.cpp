#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct P{
    int s,b,r;
};

bool compare(const P p1 , const P p2)
{
    return p1.b+p1.r > p2.b+p2.r;
}
// function optimal_schedule(s[], b[], r[]):
//  # Sắp xếp thí sinh theo (b[i] + r[i]) giảm dần
//  contestants = sort_descending_by(b[i] + r[i])
//  pool_time = 0
//  end_time = 0
//  for each contestant i in contestants:
//  pool_time = pool_time + s[i] # tổng thời gian bơi cộng dồn
//  end_time = max(end_time, pool_time + b[i] + r[i]) # thời
// gian kết thúc muộn nhất
//  return end_time, contestants 
int main()
{
    int n;cin >> n;
    vector<P> pars(n);
    for(auto &i : pars) cin >> i.s >> i.b >> i.r;

    int pool_time = 0, end_time = 0;
    sort(pars.begin() , pars.end() , compare);
    for(auto a : pars)
    {
        pool_time += a.s;
        end_time = max(end_time, pool_time + a.b + a.r);
    }    
    cout << end_time;

    return 0;
}