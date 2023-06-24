#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_SENSOR_NO_LENGTH 10
#define MAX_TIMESTAMP_LENGTH 10

struct LogEntry {
    int entryNo;
    char sensorNo[MAX_SENSOR_NO_LENGTH];
    float temperature;
    int humidity;
    int light;
    char timestamp[MAX_TIMESTAMP_LENGTH];
};

void readDataFile(struct LogEntry logEntries[], int *numEntries) {
    FILE *dataFile = fopen("data.csv", "r");
    if (dataFile == NULL) {
        printf("Failed to open the data file.\n");
        exit(1);
    }

    char line[100];
    int i = 0;

    while (fgets(line, sizeof(line), dataFile) != NULL) {
        if (i >= MAX_ENTRIES) {
            printf("Reached maximum number of entries. Some data might be skipped.\n");
            break;
        }

        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,\n]", &logEntries[i].entryNo, logEntries[i].sensorNo, &logEntries[i].temperature, 
            &logEntries[i].humidity, &logEntries[i].light, logEntries[i].timestamp);

        i++;
    }

    *numEntries = i;

    fclose(dataFile);
}

void displayLogEntries(const struct LogEntry logEntries[], int numEntries) {
    printf("Log Entries:\n");
    printf("--------------------------------------------------------\n");
    printf("EntryNo  SensorNo  Temperature  Humidity  Light  Timestamp\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%-8d %-9s %-12.2f %-8d %-6d %s\n", logEntries[i].entryNo, logEntries[i].sensorNo, logEntries[i].temperature,
            logEntries[i].humidity, logEntries[i].light, logEntries[i].timestamp);
    }

    printf("--------------------------------------------------------\n");
}

int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    readDataFile(logEntries, &numEntries);
    displayLogEntries(logEntries, numEntries);

    return 0;
}
