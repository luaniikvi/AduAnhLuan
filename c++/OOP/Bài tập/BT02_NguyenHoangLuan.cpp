// Code by Nguyễn Hoàng Luân - 24162069
#include <iostream>
#include <limits>

using namespace std;

int _max(int a, int b) { return (a>b ? a : b); } 

class CIntArray{
private:
    int* array = NULL; // Array data
    int size;          // Array size
public:
    // Contructor   
    CIntArray();
    CIntArray(const CIntArray& array);
    CIntArray(const int* p, const int size);
    template<int N>
    CIntArray(const int (&array)[N]);

    // Method

    void input();
    void print();

    void addElement(const int val);
    void addElement(const int *p,const int n);

    int getElement(const int idx) const;
    int getSum() const;
    int getSize() const;
    int getMax() const;

    CIntArray getEven();

    void erase(const int idx);
    void insert(const int idx,const int val);

    // destrutor
    ~CIntArray(){
        delete[] this->array;
        this->array = NULL;
        this->size = 0; 
    }
};

// Nguyễn Hoàng Luân
CIntArray::CIntArray(): size(0){
    delete[] this->array;
    this->array = NULL;
};
// Nguyễn Hoàng Luân
CIntArray::CIntArray(const CIntArray& array){
    // Xóa mảng cũ
    delete[] this->array;
    // Copy
    this->size = array.size;
    this->array = new int[this->size];

    for(int i=0 ; i<this->size ; i++)
        *(this->array + i) = *(array.array + i);
}
// Nguyễn Hoàng Luân
CIntArray::CIntArray(const int* p, const int size){
    // Xóa mảng cũ
    delete[] this->array;
    // Copy
    this->size = size;
    this->array = new int[size];
    
    for(int i=0 ; i<size ; i++)
        *(this->array + i) = *(p + i);
}

// Nguyễn Hoàng Luân
template<int N>
// Dùng template để lấy kích thước của mảng
// Dùng &array để tránh suy biến thành -> *array
// cho phép tham chiếu đến cả mảng
CIntArray::CIntArray(const int (&array)[N]){
    // Xóa mảng cũ
    delete[] this->array;
    //Tạo mảng mới
    this->size = N;
    this->array = new int[this->size];
    for(int i=0 ; i<N ; i++)
        *(this->array + i) = array[i];
}

// Nguyễn Hoàng Luân
void CIntArray::input(){
    // Xóa mảng cũ
    delete[] this->array;

    // Tạo mảng mới
    cout << "Nhập kích thước: ";
    cin >> this->size;
    this->array = new int[this->size];
    cout << "Nhập mảng: ";
    for(int i=0 ; i<this->size ; i++)
        cin >> *(this->array + i);
}
// Nguyễn Hoàng Luân
void CIntArray::print(){
    for(int i=0 ; i<this->size ; i++)
        cout << *(this->array + i) << ' ';
}

// Nguyễn Hoàng Luân
void CIntArray::addElement(const int val){
    // Tạo mảng mới
    int *newArray = new int[this->size+1];
    //Copy mảng cũ qua
    for(int i=0 ; i<this->size ; i++)
        *(newArray + i) = *(this->array + i);
    // thêm vào cuối mảng
    *(newArray + size) = val;
    this->size++;
    // Xóa mảng cũ, thay bằng mảng mới
    delete[] this->array;
    this->array = newArray;
}
// Nguyễn Hoàng Luân
void CIntArray::addElement(const int *p, const int n){
    // Tạo mảng mới
    int* newArray = new int[this->size + n];

    // Copy
    int i;
    for(i=0 ; i<this->size ; i++)
        *(newArray + i) = *(this->array + i);
    for(int j=0 ; j<n ; j++, i++)
        *(newArray + i) = *(p+j);
    
    // Xóa mảng cũ
    delete[] this->array;
    this->array = newArray;
    this->size += n;
}

// Nguyễn Hoàng Luân
int CIntArray::getElement(const int idx) const{
    if(idx <0 || idx >= this->size){ 
        cout << "\nInvalid idx\n";
        return int();
    }
    return *(this->array + idx);
}
// Nguyễn Hoàng Luân
int CIntArray::getSize() const{
    return this->size;
}
// Nguyễn Hoàng Luân
int CIntArray::getSum() const{
    int sum = 0;
    for(int i=0 ; i<this->size ; i++)
        sum += *(this->array + i);
    return sum;
}
// Nguyễn Hoàng Luân
int CIntArray::getMax() const {
    if(this->size == 0) return INT_MIN;

    int max = INT_MIN;
    for(int i=0 ; i<this->size ; i++) 
        max = _max(max, *(this->array + i));
    return max;
}

// Nguyễn Hoàng Luân
CIntArray CIntArray::getEven(){
    int* even;
    int evenSize = 0;
    // Kiểm tra trong mảng có bao nhiêu số chẵn
    for(int i=0 ; i<this->size ; i++){
        if(array[i] %2 == 0) 
            evenSize += 1;
    }
    if(evenSize == 0) return CIntArray();
    // Tạo mảng số chẵn
    even = new int[evenSize];
    int evenIdx = 0;
    for(int i=0 ; i<this->size ; i++){
        if(evenIdx == evenSize) 
            return CIntArray(even,evenSize);
        if(array[i] %2 == 0)
            *(even+ evenIdx++) = array[i];
    }
    CIntArray evenArr(even,evenSize);
    delete[] even;
    return evenArr;
}

// Nguyễn Hoàng Luân
void CIntArray::erase(const int idx){
    if(idx <0 || idx >= this->size){ 
        cout << "\nInvalid idx\n";
        return;
    }
    if(this->size == 0){ 
        cout << "Empty array, cannot be deleted";
        return;
    }
    if(this->size == 1){
        delete[] this->array;
        this->array = NULL;
        this->size = 0;
        return;
    }
    int* newArray = new int[this->size - 1];
    int newArrayIdx = 0;

    for(int i=0 ; i<this->size ; i++)
    {
        if(i == idx) continue;
        *(newArray + newArrayIdx++) = *(this->array + i);
    }
    // Xóa mảng cũ
    delete[] this->array;
    this->array = newArray;
    this->size -= 1;
}  
// Nguyễn Hoàng Luân
void CIntArray::insert(const int idx,const int val){
    if(idx > this->size) {
        cout << "\nInvalid idx\n";
        return;
    }
    int* newArray = new int[this->size + 1];
    int newArrayIdx = 0;

    for(int i=0 ; i<=this->size ; i++){
        if(i == idx) 
            *(newArray + newArrayIdx++) = val;
        if(i < this->size)
            *(newArray + newArrayIdx++) = *(this->array + i);
    }
    // Xóa mảng cũ
    delete[] this->array;
    this->array = newArray;
    this->size += 1;
}

int main(){
    // int p[] = {1,2,3,4,5,6,7};
    // CIntArray c(p);
    CIntArray a((int[]){1});
    // CIntArray b(a);
    //a.erase(0);
    //a.print();
    cout << a.getElement(1);
    cout << endl;
    // b.print();
    // cout << endl;
    // c.print();
    // cout << endl;
    // a.addElement(8);
    // cout << a.getSize() << endl;
    // a.erase(8);
    //a.insert(8,-1);
    // a.print();
    //a = {1,2,3};
    //a.print();
    //int p[] = {1,2,3};
    //a.addElement(p,3);
    //a.print();
    //cout << a.getSize() << endl;
    //a.getEven().print();
    // CIntArray b;
    // b.input();
    // b.print();
    //a.print();
}