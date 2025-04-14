#include<iostream>
#include<queue>
using namespace std;

int main()
{
    std::queue <int> q_data;
    q_data.push(1);
    q_data.push(2);
    q_data.push(4);
    q_data.pop();
    while(q_data.size()!= 0)
    {
        cout << q_data.front() << ' ';
        q_data.pop();
    }
}