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
        //os <<"============================="<< endl;
        return os;
    }

    void operator=(SinhVien sv){
        this->mssv = sv.mssv;
        this->hoten = sv.hoten;
        this->gioitinh = sv.gioitinh;
        this->diem = sv.diem;
    } 

    // 5 điểm trở lên là pass, dưới 5 là pass away
    bool Pass(){ return this->diem >= 5; }

    //Lấy thông tin
    string GetName(){ return this->hoten; }
    string GetSex(){ return this->gioitinh; }
    float GetMark(){ return this->diem; }
    // Xếp loại trên điểm số
    string XepLoai();

    ~SinhVien(){}; // destructure
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
    if(diem >= 9.0f) return "A+";
    if(diem >= 8.5f) return "A";
    if(diem >= 8.0f) return "B+";
    if(diem >= 7.5f) return "B";
    if(diem >= 7.0f) return "C+";
    if(diem >= 6.5f) return "C";
    if(diem >= 5.0f) return "D+";
    if(diem >= 4.0f) return "D";
    return "F";
}
void SinhVien::operator=(SinhVien sv){
    this->mssv = sv.mssv;
    this->hoten = sv.hoten;
    this->gioitinh = sv.gioitinh;
    this->diem = sv.diem;
} 

void InputSinhVienList(SinhVien list[], int size){
    for(int i=0 ; i<size ; i++)
    {
        cout << "STT: " << i + 1 << endl;
        cin >> list[i];
    }
}
void PrintSinhVienList(SinhVien list[], int size)
{
    for(int i=0 ; i<size ; i++)
    {
        cout << "STT: " << i+1;
        cout << list[i] << endl;
    }
}
void PrintPass(SinhVien list[], int size){
    cout << "Danh sách sinh viên qua môn: " << endl;
    for(int i=0 ; i<size ; i++)
        if(list[i].Pass()) cout << list[i] << endl;
}
float PassPercent(SinhVien list[], int size){
    int passCounter = 0;
    for(int i=0 ; i<size ; i++)
        if(list[i].Pass()) passCounter++;

    return (float)passCounter/size*100;
}
float AverageMark(SinhVien list[], int size){
    float res = 0.0f;
    for(int i=0 ; i<size ; i++)
        res += (float)list[i].GetMark() / size;
    return res;
}
SinhVien max(SinhVien a, SinhVien b){ return (a.GetMark() > b.GetMark() ? a : b); }
SinhVien FindMaxMark(SinhVien list[], int size){
    SinhVien maxMark = SinhVien();
    for(int i=0 ; i<=size ; i++)
        maxMark = max(maxMark,list[i]);

    return maxMark;
}
string NameOfMaxMark(SinhVien list[], int size){
    return FindMaxMark(list,size).GetName();
}
void FindExcellentFemale(SinhVien list[], int size){
    bool notFound = true;
    for(int i=0 ; i<size ; i++)
    {
        if(list[i].GetSex() != "nu") continue;
        if(list[i].GetMark() < 8.0f) continue;
        notFound = false;
        cout << list[i] << endl;
    }
    if(notFound) cout << "none";
}
