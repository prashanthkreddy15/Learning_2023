#include <stdio.h>

void swap(void *a, void *b, size_t size) {
    char temp[size];

    // Copy the content of 'a' to 'temp'
    char *ptrA = (char *)a;
    char *ptrTemp = temp;
    for (size_t i = 0; i < size; i++) {
        *ptrTemp++ = *ptrA++;
    }

    // Copy the content of 'b' to 'a'
    char *ptrB = (char *)b;
    ptrA = (char *)a;
    for (size_t i = 0; i < size; i++) {
        *ptrA++ = *ptrB++;
    }

    // Copy the content of 'temp' to 'b'
    ptrTemp = temp;
    ptrB = (char *)b;
    for (size_t i = 0; i < size; i++) {
        *ptrB++ = *ptrTemp++;
    }
}

int main() {
    int a = 5;
    int b = 10;

    printf("Before swap: a = %d, b = %d\n", a, b);

    swap(&a, &b, sizeof(int));

    printf("After swap: a = %d, b = %d\n", a, b);

    double x = 2.5;
    double y = 7.8;

    printf("Before swap: x = %lf, y = %lf\n", x, y);

    swap(&x, &y, sizeof(double));

    printf("After swap: x = %lf, y = %lf\n", x, y);

    return 0;
}