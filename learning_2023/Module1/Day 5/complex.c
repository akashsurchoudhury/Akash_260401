#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

struct Complex readComplex() {
    struct Complex num;
    
    printf("Enter the real part: ");
    scanf("%f", &num.real);
    
    printf("Enter the imaginary part: ");
    scanf("%f", &num.imaginary);
    
    return num;
}

void writeComplex(struct Complex num) {
    if (num.imaginary < 0) {
        printf("Complex number: %.2f - %.2fi\n", num.real, -num.imaginary);
    } else {
        printf("Complex number: %.2f + %.2fi\n", num.real, num.imaginary);
    }
}

struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    
    return result;
}

struct Complex multiplyComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    
    result.real = num1.real * num2.real - num1.imaginary * num2.imaginary;
    result.imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;
    
    return result;
}

int main() {
    struct Complex num1, num2, sum, product;
    
    printf("Enter the first complex number:\n");
    num1 = readComplex();
    
    printf("\nEnter the second complex number:\n");
    num2 = readComplex();
    
    sum = addComplex(num1, num2);
    product = multiplyComplex(num1, num2);
    
    printf("\nSum of two complex numbers:\n");
    writeComplex(sum);
    
    printf("\nProduct of two complex numbers:\n");
    writeComplex(product);
    
    return 0;
}
