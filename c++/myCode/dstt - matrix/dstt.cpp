#include<iostream>
#include"matrix.h"
#include<string>
//#include<stdio.h>
#include<Windows.h>
using namespace std;


char matrixChoose;
int calcu = -1;
int m,n;                        

int main()
{
    // vector A B C D
    vvi A,B,C,D;
    cout << "___Welcom to may tinh ma tran___\n";
    while(true)
    {   
        int option;
        PrintMenu();
        cin >> option;
        if(option < 1 || option > 4)
        {
            cout << "***BYE***";
            Sleep(1500);
            return 0;
        }

        switch (option)
        {
            // tao
            case 1:
                cout << "Tao ma tran? (A,B,C,D): ";
                cin >> matrixChoose;
                matrixChoose = (char) tolower((int) matrixChoose);
                switch(matrixChoose)
                {
                    case 'a':
                        cout << "Nhap kich thuoc(m x n): ";
                        cin >> m >> n;
                        InputMaxtrix(A,m,n);
                        cout << "--------" << endl;
                        break;
                    case 'b':
                        cout << "Nhap kich thuoc(m x n): ";
                        cin >> m >> n;
                        InputMaxtrix(B,m,n);
                        cout << "--------" << endl;
                        break;
                    case 'c':
                        cout << "Nhap kich thuoc(m x n): ";
                        cin >> m >> n;
                        InputMaxtrix(C,m,n);
                        cout << "--------" << endl;
                        break;
                    case 'd':
                        cout << "Nhap kich thuoc(m x n): ";
                        cin >> m >> n;
                        InputMaxtrix(D,m,n);
                        cout << "--------" << endl;
                        break;
                    
                }
                break;


            // sua
            case 2:
                cout << "Chon ma tran muon sua(A,B,C,D): ";
                cin >> matrixChoose;matrixChoose = (char) tolower((int) matrixChoose);

                if(matrixChoose == 'a')
                {
                    if(!A.empty())
                    {
                        cout << "Ma tran cu:" << endl;
                        PrintMatrix(A);
                        cout << "--------------\n";
                    }
                    A.clear();
                    cout << "Nhap kich thuoc muon sua (m x n): ";
                    cin >> m >> n;
                    cout << "Sua ma tran.....\n";
                    InputMaxtrix(A,m,n);
                }
                else if(matrixChoose == 'b')
                {
                    if(!B.empty())
                    {
                        cout << "Ma tran cu:" << endl;
                        PrintMatrix(A);
                        cout << "--------------\n";
                    }
                    B.clear();
                    cout << "Nhap kich thuoc muon sua (m x n): ";
                    cin >> m >> n;
                    cout << "Sua ma tran.....\n";
                    InputMaxtrix(B,m,n);
                }
                else if(matrixChoose == 'c')
                {
                    if(!C.empty())
                    {
                        cout << "Ma tran cu:" << endl;
                        PrintMatrix(A);
                        cout << "--------------\n";
                    }
                    C.clear();
                    cout << "Nhap kich thuoc muon sua (m x n): ";
                    cin >> m >> n;
                    cout << "Sua ma tran.....\n";
                    InputMaxtrix(C,m,n);
                }
                else if(matrixChoose == 'd')
                {
                    if(!D.empty())
                    {
                        cout << "Ma tran cu:" << endl;
                        PrintMatrix(A);
                        cout << "--------------\n";
                    }
                    D.clear();
                    cout << "Nhap kich thuoc muon sua (m x n): ";
                    cin >> m >> n;
                    cout << "Sua ma tran.....\n";
                    InputMaxtrix(D,m,n);
                }

                break;
            // tinh toan
            case 3:
                cout << "1.Tinh dinh thuc" << endl;
                cout << "2.Nhan ma tran" << endl;
                cout << "-->";
                cin >> calcu;
                switch(calcu)
                {
                    case 1:
                        long long int det;
                        cout << "Chon ma tran (A,B,C,D): ";
                        cin >> matrixChoose;matrixChoose = (char) tolower((int) matrixChoose);
                        switch (matrixChoose)
                        {
                            case 'a':
                                det = Det(A);
                                cout << "Dinh thuc cua ma tran " << (char)toupper(matrixChoose)
                                     << " : " << det << endl;
                                PauseKeyboard();
                                break;
                            case 'b':
                                det = Det(A);
                                cout << "Dinh thuc cua ma tran " << (char)toupper(matrixChoose)
                                     << " : " << det << endl;
                                PauseKeyboard();
                                
                                break;
                            case 'c':
                                det = Det(A);
                                cout << "Dinh thuc cua ma tran " << (char)toupper(matrixChoose)
                                     << " : " << det << endl;
                                PauseKeyboard();
                                
                                break;
                            case 'd':
                                det = Det(A);
                                cout << "Dinh thuc cua ma tran " << (char)toupper(matrixChoose)
                                     << " : " << det << endl;
                                PauseKeyboard();
                                
                                break;
                            default: break;
                        }
                        break;
                    case 2:
                        cout << "Chon 2 ma tran muon nhan: ";
                        cin >> matrixChoose;matrixChoose = (char) tolower((int) matrixChoose);
                        vvi Mt1 = CopyMatrix(matrixChoose,A,B,C,D);

                        cin >> matrixChoose;
                        matrixChoose = (char) tolower((int) matrixChoose);
                        vvi Mt2 = CopyMatrix(matrixChoose,A,B,C,D);

                        vvi MultiResult = MultiMatrix(Mt1,Mt2);
                        cout << "Ket qua: \n";
                        PrintMatrix(MultiResult);
                        PauseKeyboard(); 
                        break;
                    break;
                }
            case 4:
            {
                cout << "Chon ma tran muon xem (A,B,C,D): ";
                cin >> matrixChoose;matrixChoose = tolower(matrixChoose);
                cout << "Ma tran " << (char)toupper(matrixChoose) << GetSize(matrixChoose,A,B,C,D) << ":\n";
                if(matrixChoose == 'a') PrintMatrix(A);
                else if(matrixChoose == 'b') PrintMatrix(B);
                else if(matrixChoose == 'c') PrintMatrix(C);
                else if(matrixChoose == 'd') PrintMatrix(D);
                PauseKeyboard();
                break;
            }
        }
    }

    return 0;
}

void PrintMenu()
{
    cout << "1.Tao ma tran" << endl;
    cout << "2.Sua ma tran" << endl;
    cout << "3.Tinh toan ma tran" << endl;
    cout << "4.Xem ma tran" << endl;
    cout << "   def. OUT  " << endl;
    cout << "-->";
}