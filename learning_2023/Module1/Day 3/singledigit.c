#include <stdio.h>

int findLargestNumber(int num) {
    int largest = 0;
    int divisor = 1;
    
    while (divisor <= 1000) {
        int truncatedNum = (num / (divisor * 10)) * divisor + (num % divisor);
        if (truncatedNum > largest) {
            largest = truncatedNum;
        }
        divisor *= 10;
    }
    
    return largest;
}

int main() {
    int num;
    
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
    
    int largest = findLargestNumber(num);
    
    printf("The largest number by deleting a single digit is: %d\n", largest);
    
    return 0;
}
