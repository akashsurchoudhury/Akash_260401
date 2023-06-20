#include <stdio.h>

int main() {
    int arr[] = {12, 84, 203, 66, 456, 72, 1045, 90};
    int len = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }

    double avg = (double)sum / len;

    printf("Array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);

    return 0;
}
