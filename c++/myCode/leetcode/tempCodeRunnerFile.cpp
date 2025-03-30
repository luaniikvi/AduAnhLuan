bool isOpen(const char &c)
{
    if(c == '{') return true;
    if(c == '[') return true;
    if(c == '(') return true;
    return false;
}

bool isClose(const char &c)
{
    return !(isOpen(c));
}

char rev(const char &c)
{
    if(c == '(') return ')';
    if(c == ')') return '(';
    if(c == '{') return '}';
    if(c == '}') return '{';
    if(c == '[') return ']';
    if(c == ']') return '[';
    return 0;
}

bool isValid(string s)
{
    //int len = s.length();
    int open_c = 0;
    int close_c  = 0;

    for(char &c : s)
    {
        if(isOpen(c)) open_c++;
        else close_c++;
    }
    if(open_c!=close_c) return false;
    if(isClose(s[0])) return false;

    bool checking = true;
    int i = 1;
    while(!s.empty())
    {
        if(isClose(s[i]))
        {
            if(s[i] != rev(s[i-1]))
            {
                return false;
            }
            else 
            {
                s.erase(i-1,2);
                i--;
            }
        }
        else
        {
            i++;
        }
    }
    
    return true;
}