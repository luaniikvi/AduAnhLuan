// Code by nhóm 8

#include "SchoolMember.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <limits>

using namespace std;

vector<Person*> data;

void Pause(){
    cout << "Ấn phím bất kì để tiếp tục...";
    _getch();
    cout << endl;
    return;
}

int PrintMenu()
{
    cout << "========MENU========" << endl;
    cout << "1. Tìm kiếm bằng ID" << endl;
    cout << "2. Thêm dữ liệu 1 người" << endl;
    cout << "3. Xóa dữ liệu 1 người" << endl;
    cout << "4. Sửa thông tin 1 người" << endl;
    cout << "0. EXIT " << endl;
    cout << "\n-->";
    return 4;
}
//Kiểm tra input có hợp lệ không
bool isNumber(const string number){
    for(auto c : number){
        if(!isdigit(c)) return false;
    }
    return true;
}
// tìm vị trí của ID trong data
int GetOption(const int begin,const int end) 
{
    string raw;
    getline(cin,raw);
    while(raw == "" || !isNumber(raw) || stoi(raw) < begin || stoi(raw) > end){
        cout << "--Không hợp lệ, vui lòng nhập lại--" << endl;
        cout << "-->";
        getline(cin,raw);
    }
    return stoi(raw);
}
// liner search
int Search()
{
    string target;
    cout << "Nhập ID: "; cin >> target;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for(int i=0 ; i < ::data.size() ; i++)
    {
        for(string id : ::data[i]->GetID())
        {
            if(id == target){
                ::data[i]->ShowInfo();
                return i;
            }
        }
    }
    cout << "--Không tìm thấy dữ liệu!--" << endl;
    return -1;
}
// tạo class
Person* CreatePerson(int option) {
    switch (option) {
        case 1: return new Student();
        case 2: return new Teacher();
        case 3: return new Staff();
        case 4: return new TeachingAssistant();
        case 5: return new AdminTeacher();
        case 6: return new ClubMember();
        case 7: return new ClubLeader();
        case 8: return new Researcher();
        case 9: return new ResearchAssistant();
        default: return nullptr; // Trả về con trỏ null nếu lựa chọn không hợp lệ
    }
}
// thêm dữ liệu
void Add()
{
    cout << "Chọn kiểu dữ liệu muốn thêm vào:" << endl;
    //cout << "-1. Person" << endl;
    cout << "1. Student" << endl;
    cout << "2. Teacher" << endl;
    cout << "3. Staff" << endl;
    cout << "4. TeachingAssistant" << endl;
    cout << "5. AdminTeacher" << endl;
    cout << "6. ClubMember" << endl;
    cout << "7. ClubLeader" << endl;
    cout << "8. Researcher" << endl;
    cout << "9. ResearchAssistant" << endl;
    cout << "0. Hủy" << endl;
    cout << "-->";

    int option = GetOption(0,9);
    if (!option) return;

    Person *newData = nullptr;
    newData = CreatePerson(option);

    if(newData != nullptr){
        newData->Input();
        ::data.push_back(newData);
        cout << "Đã thêm thành công"<< endl;
        return;
    }
    cout << "Thất bại"<< endl;
}
// xóa dữ liệu
void Delete()
{
    int pos = Search(); 
    if(pos == -1) return;
    ::data.erase(::data.begin()+pos , ::data.begin()+pos+1);
    cout << "Đã xóa thành công" << endl;
}
// sửa dữ liệu
void Edit()
{
    int pos = Search(); 
    if(pos == -1) return;
    ::data[pos]->Edit();
    cout << "Đã sửa thành công" << endl;
}

// Do what?
void Do(int option){
    switch (option)
    {
    case 1:
        Search();Pause();
        break;
    case 2:
        Add();Pause();
        break;
    case 3:
        Delete();Pause();
        break;
    case 4:
        Edit();Pause();
        break;
    default:
        return;
    }
}