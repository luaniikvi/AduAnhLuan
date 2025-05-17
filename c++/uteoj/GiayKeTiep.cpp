#include <iostream>
using namespace std;

int main() {
    int h, m, s;
    cin >> h >> m >> s;  // Nhập vào giờ, phút, giây

    s++;  // Tăng giây lên 1

    if (s == 60) {  // Nếu giây vượt quá 59 thì reset lại và tăng phút
        s = 0;
        m++;
    }

    if (m == 60) {  // Nếu phút vượt quá 59 thì reset lại và tăng giờ
        m = 0;
        h++;
    }

    if (h == 24) {  // Nếu giờ vượt quá 23 thì reset lại
        h = 0;
    }

    cout << h << " " << m << " " << s << endl;  // In ra giờ, phút, giây kế tiếp

    return 0;
}
