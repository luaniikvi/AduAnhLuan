#include<iostream>
#include<cmath>
using namespace std;

void GetInputSize(int &size);
void PrintMenu();
void checkValidOption(int &option);
void Insert(int a[],int size);
void Sort(int a[],int size);
void Delete(int a[],int size);
void ListSquareNum(int a[],int size);
void ListDivisorThan5Even(int a[],int size);
void PalidromeMostDivisor(int a[],int size);

int main()
{
    while(true)
    {
        int size;
        GetInputSize(size);

        int a[100]; // tao mang
        cout << "Nhap cac phan tu: ";
        for(int i=0;i<size;i++)
        {
            cin >> a[i];
        }


        PrintMenu();
        int UserOption;
        cout << "-->";
        cin >> UserOption;
        checkValidOption(UserOption);


        if(UserOption == 1) Insert(a,size);
        else if(UserOption == 2) Sort(a,size);
        else if(UserOption == 3) Delete(a,size);
        else if(UserOption == 4) ListSquareNum(a,size);
        else if(UserOption == 5) ListDivisorThan5Even(a,size);
        else PalidromeMostDivisor(a,size);

        
        cout << endl;
        
        cout << "Neu muon chay lai chuong trinh hay an \"yes\"" << endl;
        cout << "-->";
        string strInput;
        cin >> strInput;
        if(strInput!= "yes")
        {
            cout << "---Ban da hoan thanh chuong trinh---" << endl;
            break;
        }
    }


    return 0;
}

void GetInputSize(int &size)
{
    cout << "Nhap vao so luong phan tu: ";cin >> size;
    while(size<=0)
    {
        cout << "Khong hop le." << endl;
        cout << "Vui long nhap lai: ";cin >> size;
    }
}


void PrintMenu()
{
    cout << "Chao ban den voi chuong trinh thuc hien cac thao tac voi mang 1 chieu" << endl;
    cout << "1. Chen mot so vao mang"                         << endl;
    cout << "2. Sap xep mang"                                 << endl;
    cout << "3. Xoa mot phan tu khoi mang"                    << endl;
    cout << "4. Liet ke cac so chinh Phuong chia het cho 5"   << endl;
    cout << "5. Liet ke cac so co nhieu hon 5 uoc so chan"    << endl;
    cout << "6. Liet ke cac so doi xung co nhieu uoc so nhat" << endl;
    cout << "Ban chon thao tac nao?"                          << endl;
}

void checkValidOption(int &option)
{
    while( option < 1 || option > 6 )
    {
        cout << "---Lua chon khong hop le---" << endl;
        cout << "     Vui long nhap lai     " << endl;
        cout << "-->";
        cin >> option;
    }
}

void Insert(int a[],int size)
{
    int x,k;
    cout << "Nhap so can chen: ";cin >> x;
    cout << "Nhap vi tri chen: ";cin >> k;
    for(int i = size ; i>k ; i--)
    {
        a[i] = a[i-1];
    }
    a[k] = x;
    cout << "Mang moi: ";
    for(int i=0 ; i<=size; i++)
    {
        cout << a[i] << "  ";
    }
}

void Sort(int a[],int size)
{
    for(int i = size - 1 ; i>= 1 ; i--)
    {
        for(int p = 1 ; p <=i;  p++)
        {
            if(a[p-1] > a[p]) swap(a[p],a[p-1]);
        }
    }
    cout << "Mang moi: ";
    for(int i=0 ; i<size; i++)
    {
        cout << a[i] << "  ";
    }

}

int checkInArr(int a[],int size,int target)
{
    for(int i =0 ; i<size ;i++)
    {
        if(a[i] == target) return i;
    }
    return -1;
}

void Delete(int a[],int size)
{
    int tar;
    cout << "Nhap so can kiem tra: ";
    cin >> tar;
    if(checkInArr(a,size,tar) == -1)
    {
        cout << "So da nhap khong co trong mang";
    }
    else{
        while (checkInArr(a,size,tar) != -1)
        {
            int pos = checkInArr(a,size,tar);
            for(int i = pos ; i<size -1 ; i++)
            {
                a[i] = a[i+1];
            }
            size--;
        }

        cout << "Mang moi: ";
        for(int i=0 ; i<size ; i++)
        {
            cout << a[i] << "  ";
        }
        if(size == 0)
        {
            cout << "**Mang khong con so nao**";
        }  
    }
    
    

}
bool isSquareNum(int n)
{
    int i = sqrt(n);
    return (i*i == n);
}

void ListSquareNum(int a[],int size)
{
    int count = 0;
    int b[100];
    for(int i=0 ; i<size ;i++)
    {
        if(isSquareNum(a[i]) && a[i]%5 == 0)
        {
            b[count] = a[i];
            count++;
        }
    }
    if(count == 0)
    {
        cout << "Mang khong co so chinh phuong chia het cho 5";
    }
    else{
        cout << "So can tim la: ";
        for(int i=0 ; i<count ; i++)
        {
            cout << b[i] << "  ";
        }
    }
}

int CountDivisionEven(int n)
{
    int count = 0;
    for(int i=2 ; i<=n ; i+=2)
    {
        if(n%i == 0) count++;
    }
    return count;
}

void ListDivisorThan5Even(int a[],int size)
{
    int b_size =0;
    int b[100];
    for(int i=0 ;i<size ;i++)
    {
        if(CountDivisionEven(a[i]) > 5)
        {
            b[b_size] = a[i];
            b_size++;
        }
    }
    if(b_size == 0)
    {
        cout << "Mang khong co so can tim";
    }
    else
    {
        cout << "So can tim la: ";
        for(int i =0; i<b_size ; i++)
        {
            cout << b[i] << "  ";
        }
    }
}

bool isPalindrome(int a)
{
    int ori = a;
    int temp =0;
    while (a!=0)
    {
        temp = temp*10 + a % 10;
        a/=10;
    }
    return (ori==temp);
}

int CountDivision(int num)
{   
    int count=0;
    for(int i=1 ; i<=num ;i++)
    {
        if(num%i == 0) count++;
    }
    return count;
} 
void PalidromeMostDivisor(int a[],int size)
{
    
    int b[50];// so doi xung
    int b_size =0;
    for(int i =0 ; i<size ;i++)
    {
        if(isPalindrome(a[i]))
        {
            b[b_size] = a[i];
            b_size++;
        }
    }

    int countMax = CountDivision(b[0]);
    int SpecificNum = b[0];
    for(int j =0 ;j<b_size ;j++)
    {
        if(CountDivision(b[j]) > countMax)
        {
            countMax = CountDivision(b[j]);
            SpecificNum = b[j];
        }
    }
    if(b_size == 0){
        cout << "Khong co so can tim";
    }
    else
    {
        cout << "So doi xung co nhieu uoc nhat: " << SpecificNum;
    }
}

