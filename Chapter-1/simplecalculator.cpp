#include<iostream>
using namespace std;
int main(){
    int x,y;
    cout<<"Enter the value of x: ";
    cin>>x;
    cout<<endl<<"Enter the value of y:";
    cin>>y;
    cout<<endl<<"::Simple calculator::"<<endl;
    cout<<"Enter 1 to add two numbers."<<endl;
    cout<<"Enter 2 to subtract two numbers."<<endl;
    cout<<"Enter 3 to multiply two numbers."<<endl;
    cout<<"Enter 4 to divide two numbers."<<endl;
    cout<<"Enter the Number: ";
    int z;
    cin>>z;
    switch (z)
    {
    case 1:
        cout<< x+y;
        break;
    case 2:
        cout<< x-y;
        break;
    case 3:
        cout<< x*y;
        break;
    case 4:
        cout<< x/y;
        break;
    default:
        cout<<"Please choose a valid operator.";
        break;
    }
    return 0;
}