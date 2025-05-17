#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

// khai báo các hàm sử dụng trong main
void printPrime(int a[] ,int size);
bool checkIncrease(int a[],int size);
int abs(int n);
void printSort(int a[],int size);

int main(){
    int size; int a[100];
    // nhập số lượng mảng
    cin >> size;
    // nhập mảng
    for(int i =0 ; i<size; i++){
        cin >> a[i];
    }
    
    // in mảng ra màn hình + tìm số có trị tuyệt đối nhỏ nhất
    int min_abs = INT_MAX;
    for(int i =0 ; i<size; i++){
        cout << a[i] << " ";
        if(a[i] == 0) continue; // neu a[i] = 0 thì bỏ qua,không thực hiện dòng phía dưới

        if(abs(a[i]) < abs(min_abs)) min_abs = a[i];
    }
    cout << endl;

    // in ra các phần tử số nguyên tố  + tổng
    printPrime(a,size);
    cout << endl;

    //in ra số có abs nhỏ nhất
    if(min_abs == INT_MAX){
        cout <<"KHONG CO" << endl;
    }
    else cout << min_abs << endl;

    // kiểm tra mảng có tăng hay không
    cout << (checkIncrease(a,size) ? "TANG" : "KHONG TANG") << endl;

    //in mảng sắp xếp theo thứ tự giảm dần
    printSort(a,size);

    return 0;
}

bool isPrime(int n){
    // thuật toán kiểm tra số nguyên tố tối ưu
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2 == 0 || n%3==0) return false;

    for(int i = 5; i*i<=n ; i+=6){
        if(n%i==0 || n%(i+2) == 0) return false;
    }
    return true;
}

bool checkIncrease(int a[],int size){
    // kiểm tra nếu số đứng sau nhỏ hơn thì lập tức trả về false
    for(int i =0 ; i<size-1 ;i++){
        if(a[i+1] < a[i]) return false;
    }
    // nếu tất cả cấc số sau đều lớn hơn số sau là hàm tăng tiến, trả về true
    return true;
}

int abs(int n){
    // tính trị tuyệt đối
    // hàm này nếu #include<cmath> hoặc <math.h> thì sẽ có sẵn kh cần code
    return (n>0 ? n : -n);
}

void printPrime(int a[] ,int size){
    vector<int> prime; // tạo 1 vector(mảng nhưng xịn) để lưu trữ các số nguyên tố tìm đc
    int sum =0;
    for(int i=0;i<size;i++){
        // kiểm tra a[i] nếu là số nguyên tố thì thêm vào vector
        if(isPrime(a[i])) prime.push_back(a[i]); // push_back() là hàm thêm giá trị vào vecto
    }

    // nếu không có số nguyên tố nào tức là vector sễ trống(empty)
    if(prime.empty()){
        cout << "KHONG CO\n0";
    }
    else{
        // nếu có số nguyên số thì in ra
        for(int i : prime){
            cout << i << " ";
            sum+=i; // tính tổng các số nguyên số
        }
        cout << endl;
        cout << sum;
    }
}
void printSort(int a[],int size){
    // này là thuật toán sắp xếp theo chiều giảm dần cơ bản
    // for(int i = 0 ; i<size -1 ; i++){
    //     for(int j =0 ; j < size -i-1 ; j++){
    //         if(a[j] < a[j+1]) swap(a[j],a[j+1]);
    //     }
    // }
    // for(int i=0 ; i<size;i++){
    //     cout << a[i] << " ";
    // }
    vector<int> sortVt;
    for(int i=0;i<size;i++){
        sortVt.push_back(a[i]);
    }
    sort(sortVt.begin(),sortVt.end(),greater<int>());
    for(int num : sortVt){
        cout << num << " ";
    }
}