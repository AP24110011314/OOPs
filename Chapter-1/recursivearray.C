#include <iostream>
using namespace std;

void printSequence(int n) {
    if (n == 1) {
        cout << "1 ";
        return;
    }
    
    printSequence(n - 1);
    
    cout << n << " ";
    
    printSequence(n - 1);
}

int main() {
    int n ;
    cout<<"Enter the number: ";
    cin>>n;  
    printSequence(n);
    return 0;
}