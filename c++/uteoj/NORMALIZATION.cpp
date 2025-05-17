#include<iostream>
#include<string>
using namespace std;

// ASCII: 
// A->Z : 65->90
// a->z : 97->122
 ///   97 - 65 = 32

string normalization(string input);
string lowerCase(string str);
string upperHead(string str);

int main(){
    string input;// = "BAN **    Se     ‘’’qua ‘’’’’’’ mon";
    getline(cin,input);
    string nor = normalization(input);
    // cout << nor<<endl;
    // cout << lowerCase(nor) << endl;
    cout << upperHead(lowerCase(nor)) << endl;
}

string normalization(string in){
    string str ="";
    bool empty = true;
    for(int i =0 ; i<in.length() ; i++){
        if((in[i] >= 65 && in[i] <= 90) || (in[i] >=97 && in[i]<=122)){
            str+=in[i];
            empty = false;
        }
        else{
            if(empty) continue; 
            if(str[str.size()-1]==' '){
                continue;
            }
            str+=" ";
        }
    }
    return str;
}
string lowerCase(string str){
    for(int i =0 ; i<str.length(); i++){
        if(str[i] < 97){
            if(str[i] == ' ') continue;
            str[i] = str[i]+ 32;
        }
    }
    while(!str.empty() && str.back() ==' '){
        str.pop_back();
    }
    return str;
}

string upperHead(string str){
    str[0] -=32;
    for(int i = 0 ; i<str.length()-1 ; i++){
        if(str[i] == ' ') str[i+1]-=32;
    }
    return str;
}