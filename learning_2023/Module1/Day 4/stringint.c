#include <stdio.h>
#include <stdlib.h>

int main() {
    char inputString[] = "6.2'5''2''7''8''\0";
    int res = 0;

    for (int i = 0; inputString[i] != '\0'; i++) {
        if (inputString[i] >= '0' && inputString[i] <= '9') {
            int ival = inputString[i] - '0';
            res = res * 10 + ival;
        }
    }

    printf("Converted integer: %d\n", res);

    return 0;
}
