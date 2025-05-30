#include <stdio.h>
#include <stdlib.h>

// Define constants for true/false logic
#define TRUE 1
#define FALSE 0

// Days in each month for a non-leap year
#define DAYS {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

// Names of the months
#define MONTHS {"January", "February", "March", "April", "May", \
                "June", "July", "August", "September", "October", "November", "December"}

// Struct to represent a date
typedef struct {
    int day;
    int mounth; // Note: Typo in 'mounth' — it should be 'month'
    int year;
} n;

// Function to print a date in the format: "day Month year"
void print_date(n date) {
    char *mon[] = MONTHS;
    printf("%d %s %d\n", date.day, mon[date.mounth - 1], date.year);
}

// Check if a year is a leap year
int is_leap_year(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return TRUE;
    }
    return FALSE;
}

// Get the number of days in a given month of a specific year
int get_days_in_month(int month, int year) {
    int days[] = DAYS;
    if (month < 1 || month > 12) return -1;
    if (month == 2 && is_leap_year(year)) return 29; // Adjust for leap year February
    return days[month - 1];
}

// Print a simple list of months with their number of days
void print_calendar(int year) {
    char *months[] = MONTHS;
    int days[] = DAYS;

    printf("Calendar for the year %d:\n\n", year);

    for (int i = 0; i < 12; i++) {
        int days_in_month = (i == 1 && is_leap_year(year)) ? 29 : days[i];
        printf("%s: %d days\n", months[i], days_in_month);
    }
}

// Print a full calendar layout for the entire year
void print_full_calendar(int year) {
    char *months[] = MONTHS;
    int days[] = DAYS;

    printf("Full Calendar for the year %d:\n\n", year);

    int day_of_week = 0; // Assume January 1st starts on Sunday (0 = Sunday)

    for (int i = 0; i < 12; i++) {
        int days_in_month = (i == 1 && is_leap_year(year)) ? 29 : days[i];

        // Print month header
        printf("\n%s:\n", months[i]);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        // Print leading spaces for the first row
        for (int s = 0; s < day_of_week; s++) {
            printf("    ");
        }

        // Print days of the month
        for (int day = 1; day <= days_in_month; day++) {
            printf("%3d ", day);
            day_of_week = (day_of_week + 1) % 7; // Move to the next day of the week
            if (day_of_week == 0) {
                printf("\n"); // New line after Saturday
            }
        }

        // Add spacing after the month if the last week isn't complete
        if (day_of_week != 0) {
            printf("\n");
        }
    }
}
