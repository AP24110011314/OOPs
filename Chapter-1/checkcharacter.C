#include<iostream>
using namespace std;
//To check character,whether it is a digit,capital letter,small letter and other
int main(){
    char m;
    cout<<"Enter the character: ";
    cin>>m;
    if(m>='A' &&m<='Z'){
       cout<<"It is a capital letter. ";
    }
    else if(m>='a' && m<='z'){
         cout<<"It is a small letter.";
    }
    else if(m>='0' && m<='9'){
          cout<<" it is a digit. ";
    }
    else{
        cout<<" it is a special character. ";
    }
   
    return 0;
}