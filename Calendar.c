#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Days in each month (non-leap year)
const int DAYS_IN_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Month names
const char *MONTH_NAMES[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Date structure
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Print a date in "day Month year" format
void print_date(Date date) {
    printf("%d %s %d\n", date.day, MONTH_NAMES[date.month - 1], date.year);
}

// Check if a year is a leap year
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Get number of days in a given month for a specific year
int get_days_in_month(int month, int year) {
    if (month < 1 || month > 12) return -1;
    if (month == 2 && is_leap_year(year)) return 29;
    return DAYS_IN_MONTH[month - 1];
}

// Print number of days in each month
void print_calendar(int year) {
    printf("Calendar for the year %d:\n\n", year);
    for (int i = 0; i < 12; i++) {
        int days = (i == 1 && is_leap_year(year)) ? 29 : DAYS_IN_MONTH[i];
        printf("%s: %d days\n", MONTH_NAMES[i], days);
    }
}

// Print the full calendar layout for the year
void print_full_calendar(int year) {
    printf("Full Calendar for the year %d:\n", year);

    int day_of_week = 0;  // Assume Jan 1 starts on Sunday

    for (int i = 0; i < 12; i++) {
        int days = (i == 1 && is_leap_year(year)) ? 29 : DAYS_IN_MONTH[i];

        printf("\n%s:\n", MONTH_NAMES[i]);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        // Initial spacing for the first day
        for (int space = 0; space < day_of_week; space++) {
            printf("    ");
        }

        // Print all days of the month
        for (int day = 1; day <= days; day++) {
            printf("%3d ", day);
            day_of_week = (day_of_week + 1) % 7;

            if (day_of_week == 0) {
                printf("\n");  // New line after Saturday
            }
        }

        // Ensure spacing between months
        if (day_of_week != 0) {
            printf("\n");
        }
    }
}

// Example usage
int main() {
    int year = 2024;

    print_calendar(year);           // Simple days per month
    print_full_calendar(year);      // Full visual calendar

    Date date = {15, 2, 2024};
    print_date(date);               // Example date output

    return 0;
}
