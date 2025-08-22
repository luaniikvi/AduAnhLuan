#include <iostream>
#include <vector>

using namespace std;

struct Book{

private:
    string name = "";
    string author ="";
    string tag ="";
    long cost = -1;

public:
    Book(string name){this->name = name;}
    Book(string name,string author){
        this->name = name;
        this->author = author;
    }

    void setCost(int value){this->cost = value;}


    friend ostream& operator<< (ostream &os, Book book){
        os << "Book name: " << book.name << endl; 
        if(book.author != "") os << "Author: " << book.author << endl;
        if(book.tag != "") os << "Tag: " << book.tag << endl;
        if(book.cost + 1) os << "Cost: " << book.cost << endl;
        return os;
    }
};

class Library
{

private:
    vector<Book> bookCollection;
public:
    Library(){};
    ~Library(){
        cout << "The _Library_ has been destructor." << endl;
    };

    void addBook(Book book){
        this->bookCollection.push_back(book);
    }

    void removeBookByIsbn(string isbn){
    }

    void printBookList(){
        for(auto book : this->bookCollection){
            cout << book <<" ";
        }
    }
};

int main(){
    Library lib;
    lib.addBook(Book("300 bài code thiếu nhi","AduAluan"));

    lib.printBookList();
}