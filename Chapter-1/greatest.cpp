#include<iostream>
using namespace std;
int main(){
    int n1,n2,n3;
    cout<<"Enter 1st number: "<<endl;
    cin>>n1;
    cout<<"Enter 2st number: "<<endl;
    cin>>n2;
    cout<<"Enter 3st number: "<<endl;
    cin>>n3;
    if(n1>n2){
        if(n1>n3){
            cout<<"The Greatest No:"<<n1;
        }
        else{
            cout<<"The Greatest No:"<<n3;
        }
    }
    else if(n2>n3){
        cout<<"The Greatest No:"<<n2;
    }
    else{
        cout<<"The Greatest No:"<<n3;
    }

    cout<<endl;

    if(n1<n2){
        if(n1<n3){
            cout<<"The Smallest No:"<<n1;
        }
        else{
            cout<<"The Smallest No:"<<n3;
        }
    }
    else if(n2<n3){
        cout<<"The Smallest No:"<<n2;
    }
    else{
        cout<<"The Smallest No:"<<n3;
    }

    

    return 0;

}