#include <stdio.h>
#include <string.h>
  
int main()
{
    char* str = "4213";
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        num = num * 10 + (str[i] - 48);
    }
  
    printf("%d\n", num);
    return 0;
}