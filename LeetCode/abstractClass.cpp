// A virtual function is a member function that you expect to be redefined in
// derived classes. When you refer to a derived class object using a pointer or
// a reference to the base class, you can call a virtual function for that
// object and execute the derived class's version of the function.

// A pure virtual function implicitly makes the class it is defined for
// abstract. Abstract classes cannot be instantiated. Derived classes need to
// override/implement all inherited pure virtual functions. If they do not, they
// too will become abstract.

// An abstract class is a class that is designed to be specifically used as a
// base class. An abstract class contains at least one pure virtual function.

#include <iostream>

class Book{
    protected:
        std::string title;
        std::string author;
    public:
        Book(std::string t, std::string a){
            title = t;
            author = a;
        }
        virtual void display() = 0;

};

//Write MyBook class
class MyBook : public Book{
    protected:
        int price;
    public:
        MyBook(std::string t, std::string a, int p) : Book(t, a){
            this->price = p;
        }
    void display(){
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
};

int main() {
    std::string title, author;
    int price;

    getline(std::cin,title);
    getline(std::cin,author);
    std::cin >> price;

    MyBook novel(title, author, price);
    novel.display();
    
    return 0;
}