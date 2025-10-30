#include <iostream>
using namespace std;
void sol(){
    int x;
	    cin>>x;
	    string a;
	    cin>>a;
	    int j=0;
	    int con=0;
	    while(a[j]){
	        if(a[j]!='a'&&a[j]!='e'&&a[j]!='i'&&a[j]!='o'&&a[j]!='u'){
	            con++;
	            if(con>=4){
	                continue;
	                
	            }
	        }
	        else{
	            con=0;
	        }
	        
	        
	    }
	    if(con>=4){
	        cout<<"NO"<<endl;
	    }
	    else{
	        cout<<"YES"<<endl;}
}

int main(){
	int n;
	cin>>n;
	while(n--){
	    sol();
	}
	        
	
	return 0;

}