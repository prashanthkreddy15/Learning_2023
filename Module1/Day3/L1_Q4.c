#include <stdio.h>

int findSmallestDigit(int num) {
    int smallest = 9;
    int digit;
    
    while (num > 0) {
        digit = num % 10;
        if (digit < smallest) {
            smallest = digit;
        }
        num /= 10;
    }
    
    printf("smallest=%d ",smallest);
}

int findLargestDigit(int num) {
    int largest = 0;
    int digit;
    
    while (num > 0) {
        digit = num % 10;
        if (digit > largest) {
            largest = digit;
        }
        num /= 10;
    }
    
    printf("largest=%d ",largest);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Not valid.\n");
        return 0;
    }

    int i;
    int num;
    int smallest = 9;
    int largest = 0;
    int validCount = 0;
    
    for (i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);
        
        if (num <= 9) {
            printf("Invalid.\n");
            continue;
        }
        
        validCount++;
        
        int smallestDigit = findSmallestDigit(num);
        int largestDigit = findLargestDigit(num);
        
        if (smallestDigit < smallest) {
            smallest = smallestDigit;
        }
        
        if (largestDigit > largest) {
            largest = largestDigit;
        }
    }
}