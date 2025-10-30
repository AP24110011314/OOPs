
#include<iostream>
using namespace std;

class student {
private:
    string name;
    string lastname;
    int Class;
    int year;
    string major;



public:
    void setData(string n, string l,int c,int y,string m) {
        name = n;
        lastname = l;
        Class=c;
        year=y;
        major=m;

    }

    void display(); 
};
void student::display(){
        cout << "Name: " << name<<" "<<lastname<<endl;
        cout<<"Class: "<<Class<<endl;
        cout<<"Year: "<<year<<endl;
        cout<<"Major: "<<major<<endl;

    }

int main() {
    student std1;
    std1.setData("Aman","Maddheshiya",12,2023,"Eco");
    std1.display();
    student std2;
    std2.setData("Ram","Patil",12,2025,"Bio");
    std2.display();

    return 0;
}