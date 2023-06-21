#include <stdio.h>

void printExponent(double x) {
    unsigned long long *ptr = (unsigned long long *)&x;
    unsigned long long exponent = (*ptr >> 52) & 0x7FF;

    printf("Exponent (Hex): 0x%llX\n", exponent);
    printf("Exponent (Binary): 0b");
    
    int i;
    for (i = 10; i >= 0; i--) {
        printf("%lld", (exponent >> i) & 1);
    }
    
    printf("\n");
}

int main() {
    double x;
    scanf("%lf",&x);
    printExponent(x);
    
    return 0;
}