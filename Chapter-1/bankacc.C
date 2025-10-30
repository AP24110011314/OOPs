#include<iostream>
using namespace std;
class Customer{
    private:
    string fname;
    string sname;
    public:
    void setdata(string n,string sn){
        fname=n;
        sname=sn;

    }
    void display(){
        cout<<"Customer: "<<fname<<" "<<sname;
    }
};
class Account{
    private:
    Customer customer;
    double balance;
    public:
     void setacc(Customer c,double b){
        customer=c;
        balance=b;

    }
    void displayAccount(){
        customer.display();
        cout<<endl<<"Balance: "<<balance<<endl;
        cout<<"_________________________"<<endl;
    }


};
int main() {
    Customer c1;
    c1.setdata("Aman", "Maddheshiya");
    Account acc1;
    Account acc2;
    acc1.setacc(c1, 5000.75);
    acc2.setacc(c1, 12000.50);
    acc1.displayAccount();
    acc2.displayAccount();

    return 0;
}