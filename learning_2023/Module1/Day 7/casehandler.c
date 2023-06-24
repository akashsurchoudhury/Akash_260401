#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

void copyFile(FILE *sourceFile, FILE *destinationFile, int handleCase) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        if (handleCase == 1) {
            for (size_t i = 0; i < bytesRead; i++) {
                buffer[i] = toupper(buffer[i]);
            }
        } else if (handleCase == 2) {
            for (size_t i = 0; i < bytesRead; i++) {
                buffer[i] = tolower(buffer[i]);
            }
        } else if (handleCase == 3) {
            for (size_t i = 0; i < bytesRead; i++) {
                if (islower(buffer[i])) {
                    buffer[i] = toupper(buffer[i]);
                }
            }
        }
        fwrite(buffer, 1, bytesRead, destinationFile);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./cp [option] source_file destination_file\n");
        return 1;
    }

    char *option = argv[1];
    char *sourceFileName = argv[2];
    char *destinationFileName = argv[3];

    FILE *sourceFile = fopen(sourceFileName, "rb");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    FILE *destinationFile = fopen(destinationFileName, "wb");
    if (destinationFile == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    int handleCase = 0;
    if (strcmp(option, "-u") == 0) {
        handleCase = 1;  // Convert to upper case
    } else if (strcmp(option, "-l") == 0) {
        handleCase = 2;  // Convert to lower case
    } else if (strcmp(option, "-s") == 0) {
        handleCase = 3;  // Convert to purely upper case
    }

    copyFile(sourceFile, destinationFile, handleCase);

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
