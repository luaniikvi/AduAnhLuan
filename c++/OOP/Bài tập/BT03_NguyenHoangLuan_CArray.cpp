// Code by Nguyễn Hoàng Luân - 24162069
#include <iostream>

using namespace std;

int _max(int a, int b) { return (a>b ? a : b); } 
int _min(int a, int b) { return (a<b ? a : b); } 

class CIntArray{
private:
    int* array = NULL; // Array data
    int size;          // Array size
public:
    // Contructor   
    CIntArray();
    CIntArray(const CIntArray& array);
    CIntArray(const int* p, const int& size);
    template<int N>
    CIntArray(const int (&array)[N]);

    // Method

    void input();
    void print(string end) const;

    void addElement(const int& val);
    void addElement(const int *p,const int& n);

    int getElement(const int& idx) const;
    int getSum() const;
    int getSize() const;
    int getMax() const;

    CIntArray getEven();

    void erase(const int& idx);
    void insert(const int& idx,const int& val);

    // Operator
    // Arithmetic
    CIntArray operator+(const CIntArray& array) const;
    CIntArray operator++();
    CIntArray operator++(int);
    
    CIntArray operator--();
    CIntArray operator--(int);

    // Comparison
    bool operator>(const CIntArray& array) const;
    bool operator<(const CIntArray& array) const;
    bool operator==(const CIntArray& array) const;

    // Asignment
    void operator=(const CIntArray& array);
    void operator+=(const CIntArray& array);

    // in-out stream
    friend istream& operator>>(istream& is, CIntArray& array);
    friend ostream& operator<<(ostream& os, const CIntArray& array);

    // Destrutor
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
CIntArray::CIntArray(const int* p, const int& size){
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
void CIntArray::print(string end = "\n") const {
    for(int i=0 ; i<this->size ; i++)
        cout << *(this->array + i) << ' ';
    cout << endl;
}

// Nguyễn Hoàng Luân
void CIntArray::addElement(const int& val){
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
void CIntArray::addElement(const int *p, const int& n){
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
int CIntArray::getElement(const int& idx) const{
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
    if(this->size == 0) return 0;

    int max = *(this -> array);
    for(int i=1 ; i<this->size ; i++) 
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
void CIntArray::erase(const int& idx){
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
void CIntArray::insert(const int& idx,const int& val){
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


CIntArray CIntArray::operator+(const CIntArray& array)const {
    CIntArray newArray = *this;
    newArray.addElement(array.array, array.size);
    return newArray;
}
CIntArray CIntArray::operator++(){
    this->addElement(0);
    return *this;
}
CIntArray CIntArray::operator++(int){
    CIntArray temp = *this;
    this->addElement(0);
    return temp;
}


CIntArray CIntArray::operator--(){
    this->erase(this->size - 1);
    return *this;
}
CIntArray CIntArray::operator--(int){
    CIntArray temp = *this;
    this->erase(this->size - 1);
    return temp;
}


bool CIntArray::operator>(const CIntArray& array) const{
    return array < *this;
}
bool CIntArray::operator<(const CIntArray& array) const{
    int k = -1;

    int n = _min(this->size, array.size);
    for(int i=0 ; i<n ; i++){
        if(this->array[i] == array.array[i]){
            k = i;
        }
        else break;
    }
    if(k == -1 || k == array.size) return false;

    if(k == this->size - 1 && k < array.size - 1)
        return true;
    
    return this->array[k+1] < array.array[k+1]; 
}
bool CIntArray::operator==(const CIntArray& array) const {
    if(this->size != array.size) return false;
    
    int n = this->size;
    for(int i=0 ; i<n ; i++){
        if(this->array[i] != array.array[i])
            return false;
    }
    return true;
}


void CIntArray::operator=(const CIntArray& array){
    delete[] this->array;
    this->size = array.size;
    this->array = new int[size];

    for(int i=0 ; i<size ; i++)
        this->array[i] = array.array[i];
}
void CIntArray::operator+=(const CIntArray& array){
    *this = *this + array;
}


istream& operator>>(istream& is, CIntArray& array){
    cout << "Size: "; is >> array.size;
    delete[] array.array;
    array.array = new int[array.size];
    cout << "Array: ";
    for(int i=0 ; i<array.size ; i++)
        is >> array.array[i];
    return is;
}
ostream& operator<<(ostream& os, const CIntArray& array){
    for(int i=0 ; i<array.size ; i++)
        cout << array.array[i] << ' ';
    return os;
}

int main(){
    // int p[] = {1,2,3,4,5,6,7};
    // CIntArray c(p);
    CIntArray a = (int[]) {0,1,2,3,4,5};
    CIntArray b;
    b+=a;
    cout << b << endl;
    cin >> a;
    cout << a;
    // cout << boolalpha << (b > a) << endl;
    // cout << boolalpha << (b == CIntArray((int[]){0,2,3,4})) << endl;
    // (a+b).print();
    // a.print();
    // b.print();
    // (b++).print();
    // b.print();
    // CIntArray b(a);
    //a.erase(0);
    //a.print();
    // cout << a.getElement(1);
    // cout << endl;
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