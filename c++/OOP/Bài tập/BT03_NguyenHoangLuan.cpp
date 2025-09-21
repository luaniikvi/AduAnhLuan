// Code by Nguyễn Hoàng Luân - 24162069
#include <iostream>
using namespace std;

// Nguyễn Hoàng Luân
int _gcd(int a, int b) { return (!b ? a : _gcd(b,a%b)); }
int _abs(int num) { return (num > 0 ? num : -num); }
int _max(int a, int b) { return (a > b ? a : b); }
int _min(int a, int b) { return (a < b ? a : b); }

class CPhanSo
{
private:
    int tu;
    int mau;
public:
    // Contructor
    CPhanSo();
    CPhanSo(const int& num);
    CPhanSo(const int& tu,const int& mau);
    CPhanSo(const CPhanSo& other);

    // Method
    void ChuanHoa();
    CPhanSo reverse() const;

    // Operator
        // Arithmetic
    CPhanSo operator+(const CPhanSo& other) const;
    CPhanSo operator+() const;
    CPhanSo operator-(const CPhanSo& other) const;
    CPhanSo operator-() const;
    CPhanSo operator*(const CPhanSo& other) const;
    CPhanSo operator/(const CPhanSo& other) const;

    CPhanSo operator++(int);
    CPhanSo operator++();
    CPhanSo operator--(int);
    CPhanSo operator--();

        // Comparison
    bool operator>(const CPhanSo& other) const;
    bool operator<(const CPhanSo& other) const;
    bool operator>=(const CPhanSo& other) const;
    bool operator<=(const CPhanSo& other) const;
    bool operator==(const CPhanSo& other) const;

        // Assignment
    void operator=(const CPhanSo& other);
    void operator+=(const CPhanSo& other);
    void operator-=(const CPhanSo& other);
    void operator*=(const CPhanSo& other);
    void operator/=(const CPhanSo& other);


    // in-out stream
    friend istream& operator>>(istream& is, CPhanSo& ps);
    friend ostream& operator<<(ostream& os, const CPhanSo& ps);


    // Get tử & mẫu
    
    //int* operator.*() const; --theo đề bài
    // .* không thể nạp chồng được

    // Thay thế = cách cast CPhanSo về int* cho giống với yêu cầu
    operator int*() const;


    // Destructor
    ~CPhanSo() = default; // Để compiler tự thêm phương thức hủy mặc định
};


// ==================Constructor====================
// Nguyễn Hoàng Luân
CPhanSo::CPhanSo(): tu(0) , mau(1){}
// Nguyễn Hoàng Luân
CPhanSo::CPhanSo(const int& num) : tu(num), mau(1){}
// Nguyễn Hoàng Luân
CPhanSo::CPhanSo(const int& tu,const int& mau): tu(tu), mau(mau) {
    if(!mau) this->mau = 1;
    this->ChuanHoa();
}
// Nguyễn Hoàng Luân
CPhanSo::CPhanSo(const CPhanSo& other){
    this->tu = other.tu;
    this->mau = other.mau;
}


// Nguyễn Hoàng Luân
// ======================Method=======================
void CPhanSo::ChuanHoa(){
    int ucln = _gcd(_abs(this->tu), _abs(this->mau));
    this->tu /= ucln;
    this->mau /= ucln;
    if(mau < 0){
        this->tu *= -1;
        this->mau *= -1;
    }
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::reverse() const{
    return CPhanSo(this->mau,this->tu);
}



// Nguyễn Hoàng Luân
//=====================Operator===================
    // Arithmetic
CPhanSo CPhanSo::operator+(const CPhanSo& other) const{
    return CPhanSo(this->tu*other.mau + other.tu*this->mau, 
                  this->mau * other.mau);
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator+() const{
    return *this;
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator-(const CPhanSo& other) const{
    return CPhanSo(this->tu*other.mau - other.tu*this->mau, 
                  this->mau * other.mau);
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator-() const{
    return CPhanSo(-this->tu,this->mau);
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator*(const CPhanSo& other) const{
    return CPhanSo(this->tu*other.tu, this->mau*other.mau);
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator/(const CPhanSo& other) const{
    return (*this) * other.reverse();
}



// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator++(int){
    CPhanSo temp(*this);
    this->tu += this->mau;
    return temp;
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator++(){
    this->tu += this->mau;
    return *this;
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator--(int){
    CPhanSo temp(*this);
    this->tu -= this->mau;
    return temp;
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator--(){
    this->tu -= this->mau;
    return *this;
}



// Nguyễn Hoàng Luân
    //  Comparison
bool CPhanSo::operator>(const CPhanSo& other) const{
    return this->tu*other.mau > this->mau*other.tu;
}
// Nguyễn Hoàng Luân
bool CPhanSo::operator<(const CPhanSo& other) const{
    return other > *this;
}
// Nguyễn Hoàng Luân
bool CPhanSo::operator>=(const CPhanSo& other) const{
    return *this > other || *this == other;
}
// Nguyễn Hoàng Luân
bool CPhanSo::operator<=(const CPhanSo& other) const{
    return other <= *this;
}
// Nguyễn Hoàng Luân
bool CPhanSo::operator==(const CPhanSo& other) const{
    return this->tu == other.tu && this->mau == other.mau;
}



// Nguyễn Hoàng Luân
        // Assignment
void CPhanSo::operator=(const CPhanSo& other){
    this->tu = other.tu;
    this->mau = other.mau;
}
// Nguyễn Hoàng Luân
void CPhanSo::operator+=(const CPhanSo& other){
    *this = *this + other;
}
// Nguyễn Hoàng Luân
void CPhanSo::operator-=(const CPhanSo& other){
    *this = *this - other;
}
// Nguyễn Hoàng Luân
void CPhanSo::operator*=(const CPhanSo& other){
    *this = *this * other;
}
// Nguyễn Hoàng Luân
void CPhanSo::operator/=(const CPhanSo& other){
    *this = *this / other;
}



// Nguyễn Hoàng Luân
// =============in-out stream================
istream& operator>>(istream& is, CPhanSo& ps){
    is >> ps.tu >> ps.mau;
    if(ps.mau == 0) ps.mau = 1;
    ps.ChuanHoa();
    return is;
}
// Nguyễn Hoàng Luân
ostream& operator<<(ostream& os, const CPhanSo& ps){
    os << ps.tu << '/' << ps.mau;
    return os;
}


// Nguyễn Hoàng Luân
// =============Get tử & mẫu===============
CPhanSo::operator int*() const{ // cast về int*
    int* ps = new int[2];
    ps[0] = this->tu;
    ps[1] = this->mau;
    return ps;
}








//==============================================//

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


// Nguyễn Hoàng Luân
CIntArray CIntArray::operator+(const CIntArray& array)const {
    CIntArray newArray = *this;
    newArray.addElement(array.array, array.size);
    return newArray;
}
// Nguyễn Hoàng Luân
CIntArray CIntArray::operator++(){
    this->addElement(0);
    return *this;
}
// Nguyễn Hoàng Luân
CIntArray CIntArray::operator++(int){
    CIntArray temp = *this;
    this->addElement(0);
    return temp;
}


// Nguyễn Hoàng Luân
CIntArray CIntArray::operator--(){
    this->erase(this->size - 1);
    return *this;
}
CIntArray CIntArray::operator--(int){
    CIntArray temp = *this;
    this->erase(this->size - 1);
    return temp;
}


// Nguyễn Hoàng Luân
bool CIntArray::operator>(const CIntArray& array) const{
    return array < *this;
}
// Nguyễn Hoàng Luân
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
// Nguyễn Hoàng Luân
bool CIntArray::operator==(const CIntArray& array) const {
    if(this->size != array.size) return false;
    
    int n = this->size;
    for(int i=0 ; i<n ; i++){
        if(this->array[i] != array.array[i])
            return false;
    }
    return true;
}


// Nguyễn Hoàng Luân
void CIntArray::operator=(const CIntArray& array){
    delete[] this->array;
    this->size = array.size;
    this->array = new int[size];

    for(int i=0 ; i<size ; i++)
        this->array[i] = array.array[i];
}
// Nguyễn Hoàng Luân
void CIntArray::operator+=(const CIntArray& array){
    *this = *this + array;
}


// Nguyễn Hoàng Luân
istream& operator>>(istream& is, CIntArray& array){
    cout << "Size: "; is >> array.size;
    delete[] array.array;
    array.array = new int[array.size];
    cout << "Array: ";
    for(int i=0 ; i<array.size ; i++)
        is >> array.array[i];
    return is;
}
// Nguyễn Hoàng Luân
ostream& operator<<(ostream& os, const CIntArray& array){
    for(int i=0 ; i<array.size ; i++)
        cout << array.array[i] << ' ';
    return os;
}
