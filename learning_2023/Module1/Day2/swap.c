#include <stdio.h>

void swap_data(void* a, void* b, size_t size) {
    char* temp = (char*)malloc(size);
    char* char_a = (char*)a;
    char* char_b = (char*)b;

    for (size_t i = 0; i < size; i++) {
        temp[i] = char_a[i];
        char_a[i] = char_b[i];
        char_b[i] = temp[i];
    }

    free(temp);
}

int main() {
    int x = 5;
    int y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap_data(&x, &y, sizeof(int));
    printf("After swap: x = %d, y = %d\n", x, y);

    float a = 3.14;
    float b = 2.71;
    printf("Before swap: a = %f, b = %f\n", a, b);
    swap_data(&a, &b, sizeof(float));
    printf("After swap: a = %f, b = %f\n", a, b);

    return 0;
}

