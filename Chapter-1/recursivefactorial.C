#include<iostream>
using namespace std;
int fact(int n){
    if(n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
int main(){
    
    cout<<"Enter a number to calculate factorial: ";
    int n;
    cin>>n;
    int factorial=fact(n);
    cout<<"The factorial: ";
    cout<<factorial;
    return 0;

}