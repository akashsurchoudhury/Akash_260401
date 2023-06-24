#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box* box) {
    return box->length * box->width * box->height;
}

double calculateSurfaceArea(struct Box* box) {
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main() {
    struct Box myBox;
    struct Box* boxPtr = &myBox;
    
    // Accessing structure members using (*)
    (*boxPtr).length = 10.0;
    (*boxPtr).width = 5.0;
    (*boxPtr).height = 2.5;
    
    // Accessing structure members using (->)
    boxPtr->length = 10.0;
    boxPtr->width = 5.0;
    boxPtr->height = 2.5;
    
    double volume = calculateVolume(boxPtr);
    double surfaceArea = calculateSurfaceArea(boxPtr);
    
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);
    
    return 0;
}
