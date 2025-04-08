#include"_lib.h"

class Solution {
    public:
        string multiply(string num1, string num2) {
            if (num1 == "0" || num2 == "0")
                return "0";
    
            int m = num1.size();
            int n = num2.size();
            vector<int> res(m + n, 0); // fixed size
    
            for (int i = m - 1; i >= 0; --i) {
                for (int j = n - 1; j >= 0; --j) {
                    int mul = (num1[i] - '0') * (num2[j] - '0');
                    int sum = mul + res[i + j + 1];
    
                    res[i + j + 1] = sum % 10;
                    res[i + j] += sum / 10; // fixed carry accumulation
                }
            }
    
            string ret;
            for (int num : res) {
                if (!(ret.empty() && num == 0))
                    ret.push_back(num + '0');
            }
    
            return ret.empty() ? "0" : ret;
        }
    };