#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void differenceBetweenTimePeriods(struct Time start, struct Time end, struct Time* diff) {
    if (end.seconds < start.seconds) {
        end.minutes--;
        end.seconds += 60;
    }

    diff->seconds = end.seconds - start.seconds;

    if (end.minutes < start.minutes) {
        end.hours--;
        end.minutes += 60;
    }

    diff->minutes = end.minutes - start.minutes;
    diff->hours = end.hours - start.hours;
}

int main() {
    struct Time startTime, endTime, diffTime;

    printf("Enter start time:\n");
    printf("Hours: ");
    scanf("%d", &startTime.hours);
    printf("Minutes: ");
    scanf("%d", &startTime.minutes);
    printf("Seconds: ");
    scanf("%d", &startTime.seconds);

    printf("\nEnter end time:\n");
    printf("Hours: ");
    scanf("%d", &endTime.hours);
    printf("Minutes: ");
    scanf("%d", &endTime.minutes);
    printf("Seconds: ");
    scanf("%d", &endTime.seconds);

    differenceBetweenTimePeriods(startTime, endTime, &diffTime);

    printf("\nTime difference: %d:%d:%d\n", diffTime.hours, diffTime.minutes, diffTime.seconds);

    return 0;
}
