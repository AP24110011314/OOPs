#include<stdio.h>
int main(){
    printf("Enter the number of elements:");
    int a;
    scanf("%d",&a);
    int n[a];
    printf("Enter the elements of Array: ");
    for (int i = 0; i < a; i++){
        scanf("%d",&n[i]); }
    for(int i=0;i<a;i++){
        int min=i;
        for(int j=i+1;j<a;j++){
            if(n[min]>n[j]){
                min=j;
            }
        }
        int temp=n[i];
        n[i]=n[min];
        n[min]=temp; }
    printf("The sorted array: ");
    for (int i = 0; i < a; i++)
    {
        printf("%d ",n[i]);

    }
    return 0;

    
}