#include<stdio.h>

// Using if-else statement
int maxUsingIfElse(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Using ternary operator
int maxUsingTernaryOperator(int a, int b) {
    int max = (a > b) ? a : b;
    return max;
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int resultIfElse = maxUsingIfElse(num1, num2);
    int resultTernaryOperator = maxUsingTernaryOperator(num1, num2);

    printf("Using if-else: %d\n", resultIfElse);
    printf("Using ternary operator: %d\n", resultTernaryOperator);

    return 0;
}