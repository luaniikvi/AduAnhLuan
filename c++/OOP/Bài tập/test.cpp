#include <iostream>
using namespace std;

template<class _T>
class vector{
private:
    _T* arr;
    _T _size;

public:
    vector():  _size(0){
        delete[] arr;
        arr(nullptr);
    };
    vector(_T size);

    const int size() const {
        return this->_size;
    }
    const _T begin() const{
        return this->arr;
    }
    const _T end() const{
        return this->arr + _size;
    }

    _T& operator[](int index){
        return *(this->arr + index);
    }
};

template<class _T>
vector<_T>::vector(_T size): _size(size){
    delete[] arr;
    arr(new int[size]);
}


int main(){
    int* p = NULL;
    cout << (p);
}