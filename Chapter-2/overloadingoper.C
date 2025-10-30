#include <iostream>
using namespace std;

class Complex {
    int real, img;

public:
    
    Complex() {
        real = 0;
        img = 0;
    }

    
    Complex(int r, int i) {
        real = r;
        img = i;
    }

    
    Complex operator + (const Complex &obj) {
        Complex res;
        res.real = real + obj.real;
        res.img = img + obj.img;
        return res;
    }

    
    void print() {
        cout << real << " + " << img << "i" << endl;
    }
};

int main() {
    Complex c1(100,12), c2(2, 4);

    Complex c3 = c1 + c2;  
    c1.print(); 
    c2.print(); 
    c3.print();            

    return 0;
}