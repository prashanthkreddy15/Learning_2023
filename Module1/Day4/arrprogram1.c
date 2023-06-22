#include <stdio.h>
#include <stdlib.h>


void reverse(char *a, int n) {

  for (int i=0, j=n-1; i < j; i++, j--) {
      a[i] = a[i] ^ a[j];
      a[j] = a[j] ^ a[i];
      a[i] = a[i] ^ a[j];
  }
}


int main(int argc, char const *argv[]) {

int k = 2; // shift count
int n = 5;
char a[100];
scanf("%s",a);

reverse(&a[n-k], k); // reverse end of array
reverse(a, n-k);     // reverse beginning of array
reverse(a, n);       // reverse entire array
for (int i=0; i < n; i++) {
    printf("%c\n", a[i]);
}
}