#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

struct LogEntry {
    int entryNo;
    char sensorNo[MAX_LENGTH];
    float temperature;
    int humidity;
    int light;
    char time[MAX_LENGTH];
};

void readLogData(struct LogEntry* logEntries, int* numEntries);
void displayLogData(struct LogEntry* logEntries, int numEntries);

int main() {
    struct LogEntry logEntries[MAX_LINES];
    int numEntries = 0;

    readLogData(logEntries, &numEntries);

    printf("Log Data:\n");
    displayLogData(logEntries, numEntries);

    return 0;
}

void readLogData(struct LogEntry* logEntries, int* numEntries) {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[MAX_LENGTH];
    int entryNo;
    char sensorNo[MAX_LENGTH];
    float temperature;
    int humidity;
    int light;
    char time[MAX_LENGTH];

    // Read and skip the header line
    fgets(line, MAX_LENGTH, file);

    while (fgets(line, MAX_LENGTH, file) != NULL) {
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,\n]", &entryNo, sensorNo, &temperature, &humidity, &light, time);

        logEntries[*numEntries].entryNo = entryNo;
        strcpy(logEntries[*numEntries].sensorNo, sensorNo);
        logEntries[*numEntries].temperature = temperature;
        logEntries[*numEntries].humidity = humidity;
        logEntries[*numEntries].light = light;
        strcpy(logEntries[*numEntries].time, time);

        (*numEntries)++;
    }

    fclose(file);
}

void displayLogData(struct LogEntry* logEntries, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("Entry No: %d\n", logEntries[i].entryNo);
        printf("Sensor No: %s\n", logEntries[i].sensorNo);
        printf("Temperature: %.2f\n", logEntries[i].temperature);
        printf("Humidity: %d\n", logEntries[i].humidity);
        printf("Light: %d\n", logEntries[i].light);
        printf("Time: %s\n", logEntries[i].time);
        printf("\n");
    }
}