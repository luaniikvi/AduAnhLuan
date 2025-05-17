#include <iostream>
#include <windows.h>
#include "matrix_1.0.1.h"
// #include <string>
using namespace std;
void PrintMenu();

char chooseMatrix;
int option = -1,calcu = -1;
bool running = true;
Matrix A,B,C,D;
void GetMatrix()
{
    cin >> chooseMatrix;
    chooseMatrix = tolower(chooseMatrix);
    //cout << chooseMatrix << endl;
}
int main()
{
    cout << "___Welcom to may tinh ma tran___\n";
    while(running)
    {
        PrintMenu();
        cin >> option;
        if(option == 1)
        {
            cout << "Chon ma tran (A,B,C,D):" << endl;
            cout << "-->";
            GetMatrix();
            if(chooseMatrix == 'a') cin >> A;
            else if(chooseMatrix == 'b') cin >> B;
            else if(chooseMatrix == 'c') cin >> C;
            else cin >> D;
        }
        else if(option == 2){
            cout << "Just choose option 1 bro..." << endl;
        }
        else if(option == 3)
        {
            cout << "1.Tinh dinh thuc" << endl;
            cout << "2.Nhan ma tran" << endl;
            cout << "-->";cin >> calcu;
            if(calcu == 1)
            {
                Matrix copy = CopyMatrix(chooseMatrix,A,B,C,D);
                cout << "Dinh thuc cua " << (char)toupper(chooseMatrix) <<" = ";
                cout << Det(copy) << endl;
                PauseKeyboard();
            }
        }
        else if(option == 4)
        {
            cout << "Chon 2 ma tran muon nhan: ";
            GetMatrix();
            Matrix m1 = CopyMatrix(chooseMatrix,A,B,C,D);
            GetMatrix();
            Matrix m2 = CopyMatrix(chooseMatrix,A,B,C,D);

            cout << MultiMatrix(m1,m2) << endl;
        }
        else
        {
            cout << "***BYE***";
            Sleep(1500);
            return 0;
        }

        // clear terminal
        system("cls");
    }   
    return 0;
}


void PrintMenu()
{
    cout << "1.Tao ma tran" << endl;
    cout << "2.Sua ma tran" << endl;
    cout << "3.Tinh toan ma tran" << endl;
    cout << "4.Xem ma tran" << endl;
    cout << "  else. OUT  " << endl;
    cout << "-->";
}