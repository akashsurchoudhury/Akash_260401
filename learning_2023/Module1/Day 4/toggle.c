#include <stdio.h>

void toggleCase(char str[]) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }

        i++;
    }
}

int main() {
    char str[] = {'A', 'b', 'c', 'd', ' ', 'X', 'Y', 'Z', '\0'};

    printf("Original string: %s\n", str);

    toggleCase(str);

    printf("Toggled case string: %s\n", str);

    return 0;
}
