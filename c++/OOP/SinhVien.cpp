//Code by hluan-24162069 (luaniikvi)

#include <iostream>
#include <string>

using namespace std;

struct SinhVien
{
private:
    string mssv = "null";
    string hoten = "null";
    string gioitinh = "null";
    float diem = 0;
public:
    // structure
    SinhVien(){};

    // Hàm chuẩn hóa tên
    string ChuanHoa(string str);

    // in-stream -- hàm nhập
    friend istream& operator>> (istream& is, SinhVien &sv){
        cout << "Nhập mssv: "; is >> sv.mssv;
        cout << "Nhạp họ tên: "; 
        is.ignore();
        getline(is,sv.hoten);
        sv.hoten = sv.ChuanHoa(sv.hoten);

        cout << "Nhập giới tính (nam, nu): "; is >> sv.gioitinh;
        while (sv.gioitinh != "nam" && sv.gioitinh != "nu")
        {
            cout << "Không hợp lệ.\n";
            cout << "Nhập giới tính (nam, nu): ";
            is >> sv.gioitinh;
        }
        sv.gioitinh = sv.ChuanHoa(sv.gioitinh);
        cout << "Nhập điểm: "; is >> sv.diem;
        while (sv.diem < 0 || sv.diem > 10)
        {
            cout << "Không hợp lệ.\n";
            cout << "Nhập điểm: "; is >> sv.diem;
        }
        return is;
    }
    
    // out-stream -- hàm in
    friend ostream& operator<< (ostream& os,const SinhVien sv){
        os <<"============================="<< endl;
        os << "Mssv      : " << sv.mssv     << endl;
        os << "Họ tên    : " << sv.hoten    << endl;
        os << "Giới tính : " << sv.gioitinh << endl;
        os << "Điểm      : " << sv.diem     << endl;
        os <<"============================="<< endl;
        return os;
    }

    // 5 điểm trở lên là pass, dưới 5 là pass away
    bool Pass(){
        return this->diem >= 5;
    }
    // Đại đại đi
    string XepLoai();

    ~SinhVien(){};
};

string SinhVien::ChuanHoa(string str){
    string ans = "";
    for(char c : str){
        // Nếu là chữ cái
        if(isalpha(c)){
            // Nếu đứng đầu thì viết hoa
            if (ans == "" || ans.back() == ' ') ans += toupper(c);
            // Không thì viết thường
            else ans += tolower(c);
        }
        // Chỉ thêm ' ' khi cuối ans là chữ cái
        else if (c == ' ' && isalpha(ans.back())) ans += c;
        // trường hợp c là số thì bỏ qua
    }
    // Xóa khoảng trắng cuối cùng (nếu có)
    if(ans.back() == ' ') ans.pop_back();
    return ans;
}
string SinhVien::XepLoai(){
    if(diem >= 9.0) return "A+";
    if(diem >= 8.5) return "A";
    if(diem >= 8.0) return "B+";
    if(diem >= 7.5) return "B";
    if(diem >= 7.0) return "C+";
    if(diem >= 6.5) return "C";
    if(diem >= 5.0) return "D+";
    return "F";
}

int main(){
    SinhVien a;
    cout << a;
}