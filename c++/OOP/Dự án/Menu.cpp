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
    getch();
    cout << "\n";
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
// tìm vị trí của ID trong data
int GetOption(const int begin,const int end) 
{
    string raw;
    getline(cin,raw);
    while(!isNumber(raw) || stoi(raw) < begin || stoi(raw) > end){
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
    cout << endl;
    
    for(int i=0 ; i< ::data.size() ; i++)
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
    //cout << "0. Person" << endl;
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

    int option = GetOption(0,9);
    Person *newData = CreatePerson(option);

    if(newData != NULL)
        newData->Input();
    ::data.push_back(newData);
    cout << "Đã thêm thành công"<< endl;
}
void Delete()
{
    int pos = Search(); 
    if(pos == -1) return;
    ::data.erase(::data.begin()+pos , ::data.begin()+pos+1);
    cout << "Đã xóa thành công" << endl;
}
void Edit()
{
    int pos = Search(); 
    if(pos == -1) return;
    cin.ignore();
    ::data[pos]->Edit();
    cout << "Đã sửa thành công" << endl;
}


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