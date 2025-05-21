#include <iostream>
#include <string>
using namespace std;
int Count_Special_SubStr(const std::string &s) {
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

int main() {
    std::string s;
    std::cin >> s;
    std::cout << Count_Special_SubStr(s);
    return 0;
}