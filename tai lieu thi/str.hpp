#include <string>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>
using namespace std;

        //          phep toan         //
char mod2(string num)
{
    return (num.back() -'0')%2 +'0';
}

string div2(string num)
{
    string result = "";
    int carry = 0;
    for (char digit : num) {
        int current = (digit - '0') + carry * 10;
        result += (current / 2) + '0';
        carry = current % 2;
    }
    if (result[0] == '0' && result.length() > 1) {
        result = result.substr(1);
    }
    return result;
}

string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0") return "0";

    int m = num1.size();
    int n = num2.size();
    vector<int> res(m + n, 0); // fixed size

    for (int i = m - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10; // fixed carry accumulation
        }
    }

    string ret;
    for (int num : res)
    {
        if (!(ret.empty() && num == 0))
            ret.push_back(num + '0');
    }
    return ret.empty() ? "0" : ret;
}

string PlusBinary(string binary1, string binary2) {
        string res = "";
        int i = binary1.length()-1;
        int j = binary2.length()-1;
        int carry = 0;
        while(i>=0 || j>=0 || carry)
        {
            if(i>=0) carry += binary1[i--] - '0';
            if(j>=0) carry += binary2[j--] - '0';

            res += to_string(carry%2);
            carry/=2;
        }
        if(res.empty()) return "0";
        reverse(res.begin(), res.end());
        return res;
}




        //          Chuoi doi xung          //

int lengthOfLastWord(string s) {
    int len = 0;
    while(s.back() == ' ') s.pop_back();
    for(int i=s.length()-1 ; i >=0 ; i--)
    {
        if(s[i] == ' ') break;
        len++;
    }
    return len;
}

int len_longestPalindrome(string s)
{
    int oddCount = 0;
    unordered_map<char, int> ump;
    for (char ch : s)
    {
        ump[ch]++;
        if (ump[ch] % 2 == 1) oddCount++;
        else oddCount--;
    }
    if (oddCount > 1) return s.length() - oddCount + 1;
    return s.length();
}

string longestCommonSubstring(const string &text1, const string &text2)
{
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxLength = 0;
    int endIndex_text1 = -1;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {

            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength)
                {
                    maxLength = dp[i][j];
                    endIndex_text1 = i - 1;
                }
            }
            else dp[i][j] = 0;
        }
    }
    if (maxLength == 0)
        return "";
    else
    {
        int startIndex_text1 = endIndex_text1 - maxLength + 1;
        return text1.substr(startIndex_text1, maxLength);
    }
}




string longestPalindrome_1(string s) {
    int stringSize = s.size();
    if(stringSize < 2) return s;
    int start;// for substr
    int longestWidth = INT_MIN;
    int index = 0;
    while(index < stringSize){
        int l_ptr = index;
        int r_ptr = index;
        while( r_ptr < stringSize-1 && s[r_ptr] == s[r_ptr+1]){
            ++r_ptr;
        }
        index = r_ptr+1;
        while(l_ptr > 0 && r_ptr < stringSize-1 && s[r_ptr+1] == s[l_ptr-1]){
            --l_ptr;
            ++r_ptr;
        }
        int newWindowLength = r_ptr - l_ptr + 1;
        if(newWindowLength > longestWidth){
            start = l_ptr;
            longestWidth = newWindowLength;
        }
    }
    return s.substr(start, longestWidth);
}

string longestPalindrome_2(string s) {
    int sSize = s.size();
    if(sSize < 2){
        return  s;
    }
    int start;
    int index = 0;
    int longestWidht = INT_MIN;
    while(index < sSize){
        int l_ptr = index;
        int r_ptr = index;
        while(r_ptr < sSize-1 && s[r_ptr] == s[r_ptr+1]){
            ++r_ptr;
        }
        index = r_ptr+1;
        while(l_ptr >0 && r_ptr < sSize && s[l_ptr-1] == s[r_ptr+1]){
            --l_ptr;
            ++r_ptr;
        }
        int currentWindow = r_ptr - l_ptr +1;
        if(longestWidht < currentWindow){
            start = l_ptr;
            longestWidht = currentWindow;
        }
    }
    return s.substr(start,longestWidht);
}

int expandAroundCenter(const string &s, int left, int right)
{
    int n = s.length();
    while (left >= 0 && right < n && s[left] == s[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}


string longestPalindrome(const string &s)
{
    int n = s.length();
    if (n < 1)
        return "";

    int start = 0;
    int maxLength = 1;

    for (int i = 0; i < n; ++i)
    {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int currentMaxLen = max(len1, len2);

        if (currentMaxLen > maxLength)
        {
            maxLength = currentMaxLen;
            start = i - (maxLength - 1) / 2;
        }
    }
    return s.substr(start, maxLength);
}


int exp(const string &s, int i, int j){
    int cnt = 0;
    int mistake = 0;
    while(i >= 0 && j<s.length() && s[i] == s[j]){
        cnt++;
        i--;j++;
    }
    return cnt;
}
int Count_PalinDrome_SubStr(const string &s){
    int cnt = 0, n = s.length();

    for(int i=0 ; i<n ; i++){
        int odd = exp(s,i,i);
        int evn = exp(s,i,i+1);
        cnt += odd + evn;
    }
    return cnt;
}


// special is near PalinDrome
int Count_Special_SubStr(const string &s) {
    int n = s.length();
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        int diff = 0;
        int left = i;
        int right = i;
        while (left >= 0 && right < n) {
            if (s[left] != s[right]) diff++;
            if(diff > 1) break;

            cnt++;
            left--;
            right++;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        int diff = 0;
        int left = i;
        int right = i + 1;

        while (left >= 0 && right < n) {
            if (s[left] != s[right]) diff++;
            if(diff > 1) break;

            if (diff == 1) cnt++;

            left--;
            right++;
        }
    }
    return cnt;
}

// valid patheles
char rev(char c)
{
    if(c == '(') return ')';
    if(c == '{') return '}';
    if(c == '[') return ']';
    return 0;
}

bool isValidParentheses(string s)
{
    vector<char> open;
    for(char &c : s)
    {
        if(c == '{' || c == '(' || c == '[') open.push_back(c);
        else // close
        {
            if(open.empty()) return false;
            if( c == rev(open.back()) ) open.pop_back();
            else return false;
        }
    }

    return open.empty();
}

// valid patheles
char rev(char c)
{
    if(c == '(') return ')';
    if(c == '{') return '}';
    if(c == '[') return ']';
    return 0;
}

bool isValidParentheses(string s)
{
    vector<char> open;
    for(char &c : s)
    {
        if(c == '{' || c == '(' || c == '[') open.push_back(c);
        else // close
        {
            if(open.empty()) return false;
            if( c == rev(open.back()) ) open.pop_back();
            else return false;
        }
    }

    return open.empty();
}


int strStr(string haystack, string needle) {
    long pos = haystack.find(needle);
    if(pos == string::npos) return -1;
    return pos;
}