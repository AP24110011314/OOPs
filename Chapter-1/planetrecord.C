
#include<iostream>
using namespace std;

class planet {
private:
    string name;
    double distance;
    double gravity;



public:
    void setData(string n, double d,double g) {
        name = n;
        distance=d;
        gravity=g;

    }

    void display(); 
};
void planet::display(){
        cout << "Name: " << name<<endl;
        cout<<"Distance from sun : "<<distance<<endl;
        cout<<"Relative gravity: "<<gravity<<endl;
        

    }

int main() {
    planet plt1;
    plt1.setData("Earth",140000000,1);
    plt1.display();
    planet plt2;
    plt2.setData("Venus",10000000,2);
    plt2.display();

    return 0;
}