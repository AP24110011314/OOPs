#include<iostream>
using namespace std;
int main(){
    int i=0;
    label:
       i++;
       cout<<i<<"  ";
       if(i<10){
        goto label;
       }
    return 0;
}