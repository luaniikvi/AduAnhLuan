//==========Code by hluan-24162069 (luaniikvi)=============

//                       _oo0oo_
//                      o8888888o
//                      88" : "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \|||   :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====

//                       `=---='
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#include <iostream>
#include <algorithm>
#include <cmath>
//#define MAX_SIZE 1000007

using namespace std;


// ==========BAI_1============
// Kiểu PhanSo

struct PhanSo
{
private:
    int tu;
    int mau;
public:
    
    // structure
    PhanSo(): tu(0),mau(1){};
    PhanSo(int number) : tu(number), mau(1){}; 
    PhanSo(int tu, int mau): tu(tu), mau(mau){this->normalize();}
    PhanSo(int arr[2]): tu(arr[0]), mau(arr[1]){this->normalize();}
    
    //function
    void normalize(){
        if(this->mau == 0) return;
        int gcd = __gcd(abs(this->tu),abs(this->mau));
        this->tu  /= gcd;
        this->mau /= gcd;
        if(this->mau < 0) *this = PhanSo(-tu,-mau);
    }
    //Kiểm tra số vô hạn
    bool isInf(){return this->mau == 0;}
    //Phân số nghịch đảo
    PhanSo reverse(){return PhanSo(this->mau,this->tu);}

    double trueValue()  {
        return (double)tu/mau;
    }
    // Lấy dấu
    string getSign(){
        if(this->isInf()) return "inf";
        if(this->tu == 0) return "0";
        if(this->tu > 0)  return "+";
        return "-";
    }
    
    //operator
    PhanSo operator+(PhanSo ps);
    void operator+= (PhanSo ps){*this = *this + ps;}

    PhanSo operator-(PhanSo ps);
    void operator-=(PhanSo ps){*this = *this - ps;}

    PhanSo operator*(PhanSo ps);
    void operator*= (PhanSo ps){*this = (*this) * ps;}
    PhanSo operator/(PhanSo ps);
    void operator/=(PhanSo ps){*this = *this/ps;}

    void operator=(PhanSo ps);
    void operator=(int ps[2]);
    void operator=(int number);

    bool operator==(PhanSo ps);
    bool operator>(PhanSo ps);
    bool operator>=(PhanSo ps);
    bool operator<(PhanSo ps);
    bool operator<=(PhanSo ps);


    //in-stream
    friend istream& operator>>(istream& is, PhanSo& ps){
        is >> ps.tu >> ps.mau;
        ps.normalize();
        return is;
    }

    // out-stream
    friend ostream& operator<< (ostream &os, PhanSo ps){
        if(ps.isInf()) os << "Inf";
        else if (ps.mau == 1) os << ps.tu;
        else os << ps.tu << "/" << ps.mau;
        return os;
    }

    //destructure
    ~PhanSo(){}
};

PhanSo PhanSo::operator+(PhanSo ps){
    this->tu = this->tu*ps.mau + this->mau*ps.tu;
    this->mau *= ps.mau;
    this->normalize();
    return *this;
}
PhanSo PhanSo::operator-(PhanSo ps){
    this->tu = this->tu*ps.mau - this->mau*ps.tu;
    this->mau *= ps.mau;
    this->normalize();
    return *this;
}
PhanSo PhanSo::operator*(PhanSo ps){
        this->tu  *= ps.tu;
        this->mau *= ps.mau;
        this->normalize();
        return *this;
}
PhanSo PhanSo::operator/(PhanSo ps){
    ps = ps.reverse();
    *this *= ps;
    return *this;
}
void PhanSo::operator=(PhanSo ps){
    this->tu  = ps.tu;
    this->mau = ps.mau;
}
void PhanSo::operator=(int ps[2]){
    this->tu  = ps[0];
    this->mau = ps[1];
}
void PhanSo::operator=(int number){
    *this = PhanSo(number);
}
bool PhanSo::operator==(PhanSo ps){
    return this->tu == ps.mau && this->mau==ps.mau;
}
bool PhanSo::operator>(PhanSo ps) {
    return this->trueValue() > ps.trueValue();
}
bool PhanSo::operator>=(PhanSo ps){
    return *this>ps || *this == ps;
}
bool PhanSo::operator<(PhanSo ps){
    return ps>*this;
}
bool PhanSo::operator<=(PhanSo ps){
    return ps>*this || ps == *this;
}


// ==========BAI_2============
// Kiểu điểm

struct Point{
private:
    double x;
    double y;
public:
    // structure
    Point(): x(0),y(0){};
    Point(double x, double y): x(x), y(y){};

    // Lấy giá trị
    double getX(){return this->x;}
    double getY(){return this->y;}

    //Tính khoảng cách đến 1 điểm bất kì
    double To(Point p) const  {
        return sqrt(pow(this->x - p.x,2) + pow(this->y - p.y, 2));
    }
    //đối xứng qua tâm (0,0)
    Point Symmetry()       const {return Point(-x,-y);};
    // đối xứng qua trục Ox
    Point AxisymmetricOx() const {return Point(x,-y);};
    // đối xứng qua trục Oy
    Point AxisymmetricOy() const {return Point(-x,y);};


    // in-stream -- nhập
    friend istream& operator>> (istream &is, Point &p){
        is >> p.x >> p.y;
        return is;
    }
    // out-stream -- xuất
    friend ostream& operator<< (ostream &os,const Point p){
        os << '(' << p.x << ',' << p.y << ')'; 
        return os;
    }

    ~Point(){}; // destructure
};


// ==========BAI_3============
// Kiểu SinhVien

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
    string GetSex() { return this->gioitinh; }
    float GetMark() { return this->diem; }
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


// ==========BAI_4============
// Kiểu tam giác

struct TamGiac
{
private:
    Point point[3]; // 3 points
    double dis[3]; // 3 distances
public:
    //structure
    TamGiac(){};

    // bất đẳng thức tam giác
    bool isTriagle(double dis[3]);
    // phân loại tam giác
    string PhanLoai();
    // Tìm trọng tâm tam giác
    Point Centroid(){
        if(!isTriagle(dis))
            cout << "Đây kh phải tam giác nên kh có trọng tâm.";
        else{
            double xG =(point[0].getX() + point[1].getX() + point[2].getX())/3; 
            double yG =(point[0].getY() + point[1].getY() + point[2].getY())/3;
            return Point(xG,yG); 
        }
        return Point();
    } 

    // in-stream -- nhập
    friend istream& operator>>(istream& is, TamGiac &tamgiac){
        // nhập 3 đỉnh
        for(int i=0 ; i<3 ; i++)
            is >> tamgiac.point[i];
        // tính 3 khoảng cách
        for(int i=0 ; i<3 ; i++)
        {
            tamgiac.dis[i] = tamgiac.point[i].To(tamgiac.point[(i+1)%3]);
            //cout << tamgiac.dis[i] << " ";
        }
        sort(tamgiac.dis,tamgiac.dis+3);
        return is;
    }
    // out-stream -- in
    friend ostream& operator<<(ostream& os, TamGiac tamgiac){
        for(int i=0 ; i<3 ; i++)
            os << tamgiac.point[i] << " ";
        return os;
    }

    ~TamGiac(){};// destructure
};

bool TamGiac::isTriagle(double dis[3]){
    return dis[0] < dis[1]+dis[2]
    && dis[1] < dis[0]+dis[2]
    && dis[3] < dis[1] + dis[0];
}
string TamGiac::PhanLoai(){
    sort(begin(dis),end(dis));
    double a,b,c;
    a = dis[0]; b = dis[1]; c = dis[2];
    if(!isTriagle(dis)) return "Không phải tam giác";
    if(c*c < a*a + b*b) return "Tam giác nhọn";
    if(c*c == a*a + b*b) return "Tam giác vuông";
    return "Tam giác tù";
}


// ==========BAI_5============
// Mảng PhanSo

// Tìm max giữa 2 phân số
PhanSo max(PhanSo a, PhanSo b){
    return (a > b ? a : b);
}
// In mảng phân số
void Print(PhanSo arr[], int size){
    for(int i=0 ; i<size ; i++)
        cout << arr[i] << " ";
}
// In số âm trong mảng
void PrintNegative(PhanSo arr[], int size){
    for(int i=0 ; i<size ; i++)
        if(arr[i].getSign() == "-")
            cout << arr[i] << " ";
}
// Tổng các số trong mảng
PhanSo Sum( PhanSo arr[], int size){
    PhanSo ans(0);
    for(int i=0 ; i<size ; i++)
        ans += arr[i];
    return ans;
}
// Đếm các phân số âm
int CountNegative(PhanSo arr[], int size) {
    int cnt = 0;
    for(int i=0 ; i<size ; i++)
        if(arr[i].getSign() == "-") cnt++;
    return cnt;
}
// Có số âm trong mảng
bool HasAnyNegative(PhanSo arr[], int size){
    for(int i=0 ; i<size ; i++)
        if(arr[i].getSign() == "-") return true;
    return false;
}
// Tất cả đều là số âm
bool IsAllNegative(PhanSo arr[], int size){
    for(int i=0 ; i<size ; i++)
        if(arr[i].getSign() != "-") return false;
    return true;
}
// Phân số lớn nhất trong mảng
PhanSo Max( PhanSo arr[], int size){
    PhanSo ans(0);
    for(int i=0 ; i<size ; i++)
        ans = max(ans,arr[i]);
    return ans;
}


// ==========BAI_6============
// Mảng SinhVien

//Nhập danh sách sinh viên
void InputSinhVienList(SinhVien list[], int size){
    for(int i=0 ; i<size ; i++)
    {
        cout << "STT: " << i + 1 << endl;
        cin >> list[i];
    }
}
// In danh sách sinh viên
void PrintSinhVienList(SinhVien list[], int size)
{
    for(int i=0 ; i<size ; i++)
    {
        cout << "STT: " << i+1;
        cout << list[i] << endl;
    }
}
// In danh sách sinh viên pass môn
void PrintPass(SinhVien list[], int size){
    cout << "Danh sách sinh viên qua môn: " << endl;
    for(int i=0 ; i<size ; i++)
        if(list[i].Pass()) cout << list[i] << endl;
}
// Tinh tỉ lệ pass môn (%)
float PassPercent(SinhVien list[], int size){
    int passCounter = 0;
    for(int i=0 ; i<size ; i++)
        if(list[i].Pass()) passCounter++;

    return (float)passCounter/size*100;
}
// Tính điểm trung bình
float AverageMark(SinhVien list[], int size){
    float res = 0.0f;
    for(int i=0 ; i<size ; i++)
        res += (float)list[i].GetMark() / size;
    return res;
}
// So sánh điểm 2 sinh viên
SinhVien max(SinhVien a, SinhVien b){ return (a.GetMark() > b.GetMark() ? a : b); }
// Tìm sinh viên có điểm cao nhất
SinhVien FindMaxMark(SinhVien list[], int size){
    SinhVien maxMark = SinhVien();
    for(int i=0 ; i<=size ; i++)
        maxMark = max(maxMark,list[i]);

    return maxMark;
}
// Tên sinh viên có điểm cao nhất
string NameOfMaxMark(SinhVien list[], int size){
    return FindMaxMark(list,size).GetName();
}
// In danh sách sinh viên nữ đạt loại giỏi
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
