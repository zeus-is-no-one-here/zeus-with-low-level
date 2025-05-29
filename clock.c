#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    time_t t;
    struct tm *tm_info;

    time(&t);
    while(1) {
        system("cls");  // Clear the console screen (Windows only)

        t = time(NULL);  // Get current system time
        tm_info = localtime(&t);  // Convert raw time to local time structure

        printf("\n\n\n\n");  // Add vertical spacing for visual layout
        printf("        ===============================\n");
        printf("        %02d : %02d : %02d\n", tm_info->tm_hour, tm_info->tm_min , tm_info->tm_sec);  // Display time in HH:MM:SS format
        printf("        ===============================\n");

        Sleep(1000);  // Pause for 1 second (1000 milliseconds)
    }

    return 0;
}
