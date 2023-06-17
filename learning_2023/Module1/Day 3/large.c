#include <stdio.h>

void findSmallestLargestDigits(int n, ...) {
    int smallestDigit = 9;
    int largestDigit = 0;
    int i;

    // Initialize variable argument list
    va_list args;
    va_start(args, n);

    // Process each number
    for (i = 0; i < n; i++) {
        int number = va_arg(args, int);
        int temp = number;

        // Find the smallest and largest digits in the current number
        while (temp > 0) {
            int digit = temp % 10;
            if (digit < smallestDigit) {
                smallestDigit = digit;
            }
            if (digit > largestDigit) {
                largestDigit = digit;
            }
            temp /= 10;
        }
    }

    // Cleanup variable argument list
    va_end(args);

    // Print the result
    if (smallestDigit == 9 && largestDigit == 0) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallestDigit);
        printf("Largest Digit: %d\n", largestDigit);
    }
}

int main() {
    int n, i, num;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Initialize variable argument list
    va_list args;
    va_start(args, n);

    // Pass the numbers to the function
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        va_arg(args, int) = num;
    }

    // Call the function to find smallest and largest digits
    findSmallestLargestDigits(n, ...);

    // Cleanup variable argument list
    va_end(args);

    return 0;
}
