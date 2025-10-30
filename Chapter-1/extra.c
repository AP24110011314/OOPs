#include<stdio.h>
int main(){
    printf("Enter the number of elements:");
    int a;
    scanf("%d",&a);
    int n[a];
    printf("Enter the elements of Array: ");
    for (int i = 0; i < a; i++){
        scanf("%d",&n[i]); }
    for(int i=0;i<a-1;i++){
        
        for(int j=0;j<a-1;j++){
            if(n[j]>n[j+1]){
                int temp=n[j];
                n[j]=n[j+1];
                n[j+1]=temp;
               
            }
           
            }
        }
         
    printf("The sorted array: ");
    for (int i = 0; i < a; i++)
    {
        printf("%d ",n[i]);

    }
    return 0;

    
}