#include<iostream>
#include<vector>
using namespace std;

struct Tree
{
    int val;
    vector<Tree*> paths;

    Tree() : val(0) {};
    Tree(int x) : val(x) {};
};

    
int main()
{

    return 0;
}