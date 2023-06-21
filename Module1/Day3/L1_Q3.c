#include <stdio.h>

int digit(int num) {
    int i,count=0;
    while(num!=0)
    {
        num=num/10;
        count++;
    }
    return count;
}
int main() {
    int n;
    printf("Enter a integer: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    for(int i=0;i<n;i++)
    {
    if(digit(arr[i])==4)
    arr[i]/=10;
    }
     int max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[0])
        max=arr[i];
    }
    printf("%d",max);
}