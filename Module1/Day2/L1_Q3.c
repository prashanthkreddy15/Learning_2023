#include <stdio.h>

int sum(int a[],int size)
{
   int i,sum=0;
   for(i=0;i<size;i+=2)
   sum+=a[i];
   return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
   int arr[n];
   for(int i=0;i<n;i++)
   scanf("%d",&arr[i]);
   int res=sum(arr,n);
   printf("res=%d",res);
}