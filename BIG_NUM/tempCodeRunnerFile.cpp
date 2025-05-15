vector<string> Fibo(int max)
{
    if(max <= 1) return {"1","1"};
    vector<string> fi(max+1);
    fi[0] = fi[1] = "1";
    for(int i=2 ; i<=max ; i++)
    {
        fi[i] = str_plus(fi[i-1],fi[i-2]);
    }
    return fi;
}