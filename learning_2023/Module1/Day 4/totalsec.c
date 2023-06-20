#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char timeString[9]; // Assume the time string is no longer than 8 characters (including null terminator)
    int hours, minutes, seconds, totalSeconds;

    printf("Enter the time in the format hh.mm.ss: ");
    scanf("%8s", timeString); // Read the time string from user input
    
    // Parse the time string
    hours = atoi(strtok(timeString, "."));
    minutes = atoi(strtok(NULL, "."));
    seconds = atoi(strtok(NULL, "."));

    // Calculate the total seconds
    totalSeconds = hours * 3600 + minutes * 60 + seconds;

    printf("Total seconds: %d\n", totalSeconds);

    return 0;
}
