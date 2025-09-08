#include <iostream>
#include <string>

using namespace std;

// --- Định nghĩa các lớp đa hình ---

// Lớp cha Animal phải có ít nhất một hàm ảo (virtual)
// để dynamic_cast có thể hoạt động.
class Animal {
public:
    // Hàm hủy ảo là cách phổ biến nhất để làm điều này.
    virtual ~Animal() {} 
    
    // Một hàm ảo khác để minh họa
    virtual string getType() { return "Animal"; }
};

// Lớp Dog kế thừa từ Animal
class Dog : public Animal {
public:
    // Hàm này chỉ có ở lớp Dog
    void bark() { 
        cout << "Gâu gâu!" << endl; 
    }
    
    string getType() override { return "Dog"; }
};

// Lớp Cat kế thừa từ Animal
class Cat : public Animal {
public:
    // Hàm này chỉ có ở lớp Cat
    void meow() { 
        cout << "Meo meo!" << endl; 
    }
    
    string getType() override { return "Cat"; }
};

int main() {
    // --- Tình huống 1: Ép kiểu đúng (Animal* trỏ tới Dog) ---
    cout << "--- TÌNH HUỐNG 1: Ép kiểu một con chó ---" << endl;
    Animal* animal1 = new Dog();

    // Dùng dynamic_cast (AN TOÀN)
    cout << "Thử dynamic_cast tới Dog*: ";
    Dog* dog_ptr_dynamic = dynamic_cast<Dog*>(animal1);
    if (dog_ptr_dynamic != nullptr) {
        cout << "Thành công! Gọi hàm bark(): ";
        dog_ptr_dynamic->bark();
    } else {
        cout << "Thất bại." << endl;
    }

    // Dùng static_cast (CŨNG ĐÚNG, VÌ BẠN BIẾT CHẮC ĐÂY LÀ CHÓ)
    cout << "Thử static_cast tới Dog*: ";
    Dog* dog_ptr_static = static_cast<Dog*>(animal1);
    cout << "Thành công! Gọi hàm bark(): ";
    dog_ptr_static->bark();

    cout << "\n--------------------------------------------\n" << endl;


    // --- Tình huống 2: Ép kiểu sai (Animal* trỏ tới Cat, nhưng ép kiểu sang Dog) ---
    //cout << "--- TÌNH HUỐNG 2: Cố gắng ép kiểu một con mèo thành chó ---" << endl;
    Animal* animal2 = new Cat();
    //cout << "Đối tượng thực sự là: " << animal2->getType() << endl;

    // Dùng dynamic_cast (AN TOÀN)
    //cout << "Thử dynamic_cast tới Dog*: ";
    Dog* wrong_dog_ptr_dynamic = dynamic_cast<Dog*>(animal2);
    if (wrong_dog_ptr_dynamic != nullptr) {
        cout << "Thành công! Gọi hàm bark(): ";
        wrong_dog_ptr_dynamic->bark();
    } else {
        cout << "Thất bại một cách an toàn, con trỏ trả về là nullptr." << endl;
    }

    // Dùng static_cast (CỰC KỲ NGUY HIỂM)
    cout << "Thử static_cast tới Dog*: ";
    Dog* wrong_dog_ptr_static = static_cast<Dog*>(animal2);
    wrong_dog_ptr_static ->bark();
    //cout << "Ép kiểu vẫn thành công về mặt cú pháp..." << endl;
    //cout << "=> CỐ GẮNG GỌI HÀM BARK() TRÊN MỘT CON MÈO..." << endl;
    
    // DÒNG LỆNH DƯỚI ĐÂY SẼ GÂY RA LỖI KHÔNG XÁC ĐỊNH (UNDEFINED BEHAVIOR)
    // Rất có thể chương trình của bạn sẽ bị SẬP (CRASH) ở đây.
    // wrong_dog_ptr_static->bark(); 
    //cout << "=> (Đã bình luận dòng lệnh gây sập để chương trình chạy hết)" << endl;


    // Dọn dẹp bộ nhớ
    delete animal1;
    delete animal2;

    return 0;
}