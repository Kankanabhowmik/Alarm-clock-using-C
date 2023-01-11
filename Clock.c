#include <stdio.h>
void check(int number) {
    if (number < 10) {
        printf("0%d", number);
    }
    else {
        printf("%d", number);
    }
}
void count(int present_time, int time_for_alarm) {
    int present_hour = present_time/10000;
    int present_min = (present_time/100) % 100;
    int present_sec = (present_time % 100);
    int alarm_hour = time_for_alarm/10000;
    int alarm_min = (time_for_alarm/100) % 100;
    int alarm_sec = (time_for_alarm % 100);
    while (present_hour != alarm_hour) {
        if (present_hour == alarm_hour && present_min == alarm_min && present_sec == alarm_sec) {
            printf("ALARM");
        }
        else {
            if (present_sec <= 60) {
                present_sec++;
                if (present_sec == 60) {
                    present_sec = 0;
                    present_min++;
                }
                if (present_min == 60) {
                    present_min = 0;
                    present_hour++;
                }
                if (present_hour == 24) {
                    present_hour = 0;
                }
                check(present_hour);
                printf(":");
                check(present_min);
                printf(":");
                check(present_sec);
                printf("\n");
            }
        }
    }
    while (present_min != alarm_min) {
        if (present_hour == alarm_hour && present_min == alarm_min && present_sec == alarm_sec) {
            printf("ALARM");
        }
        else {
            if (present_sec <= 60) {
                present_sec++;

                if (present_sec == 60) {
                    present_sec = 0;
                    present_min++;
                }
                check(present_hour);
                printf(":");
                check(present_min);
                printf(":");
                check(present_sec);
                printf("\n");
            }
        }
    }
    while (present_sec != alarm_sec) {
            check(present_hour);
            printf(":");
            check(present_min);
            printf(":");
            check(present_sec);
            printf("\n");
        present_sec++;
    }
}
int main() {
    int present_time, time_for_alarm;
    printf("What time is it? (HHMMSS)");
    scanf("%d", &present_time);
    printf("What time should the alarm go off? (HHMMSS)");
    scanf("%d", &time_for_alarm);
    count(present_time, time_for_alarm);
    printf("ALARM");
    return 0;
}
