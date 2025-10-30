#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    if(n%2==0){
        cout<<"The number is even: "<<n;
    }
    else{
        cout<<"The number is odd: "<<n;
    }
    return 0;
}