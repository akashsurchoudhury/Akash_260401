
#include <stdio.h>

int bit_operations(int num, int oper_type) {
    if (oper_type == 1) {
        // Set 1st bit
        num |= 1;
    } else if (oper_type == 2) {
        // Clear 31st bit
        num &= ~(1 << 30);
    } else if (oper_type == 3) {
        // Toggle 16th bit
        num ^= (1 << 15);
    } else {
        // Invalid operation type
        printf("Invalid operation type\n");
        return 0; // Or any other appropriate error handling
    }

    return num;
}

int main() {
    int number = 1000; // Example input number
    int operation = 3; // Example operation type

    int result = bit_operations(number, operation);
    printf("Result: %d\n", result);

    return 0;
}
