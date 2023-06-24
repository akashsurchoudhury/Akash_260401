#include <stdio.h>

struct Rectangle {
    int length;
    int width;
};

void swapRectangles(struct Rectangle* rect1, struct Rectangle* rect2) {
    struct Rectangle temp = *rect1;
    *rect1 = *rect2;
    *rect2 = temp;
}

int main() {
    struct Rectangle rect1 = {5, 10};
    struct Rectangle rect2 = {3, 7};

    printf("Before swapping:\n");
    printf("Rectangle 1: Length = %d, Width = %d\n", rect1.length, rect1.width);
    printf("Rectangle 2: Length = %d, Width = %d\n", rect2.length, rect2.width);

    swapRectangles(&rect1, &rect2);

    printf("\nAfter swapping:\n");
    printf("Rectangle 1: Length = %d, Width = %d\n", rect1.length, rect1.width);
    printf("Rectangle 2: Length = %d,
