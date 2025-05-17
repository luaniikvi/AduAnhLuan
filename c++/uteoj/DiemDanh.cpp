#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
using namespace std;
pair<int, int> findTwoMissingStudents(const vector<int>& presentStudents) {
    int n = 30; // Tổng số học sinh
    int xor_full = 0;
    for (int i = 1; i <= n; ++i) {
        xor_full ^= i;
    }

    int xor_present = 0;
    for (int studentID : presentStudents) {
        xor_present ^= studentID;
    }

    int xor_result = xor_full ^ xor_present;

    // Tìm bit khác nhau đầu tiên
    int diff_bit = 1;
    while ((xor_result & diff_bit) == 0) {
        diff_bit <<= 1;
    }

    int missing1 = 0;
    int missing2 = 0;

    // Phân loại và XOR các số
    for (int i = 1; i <= n; ++i) {
        if (i & diff_bit) {
            missing1 ^= i;
        } else {
            missing2 ^= i;
        }
    }

    for (int studentID : presentStudents) {
        if (studentID & diff_bit) {
            missing1 ^= studentID;
        } else {
            missing2 ^= studentID;
        }
    }

    return make_pair(missing1, missing2);
}

int main() {
    vector<int> presentStudents;
    int studentID;
    for (int i = 0; i < 28; ++i) {
        cin >> studentID;
        presentStudents.push_back(studentID);
    }

    pair<int, int> missingStudents = findTwoMissingStudents(presentStudents);
    cout << missingStudents.first << missingStudents.second << endl;

    return 0;
}