#include <stdio.h>
#include <time.h>
#include <windows.h>

// Enable ANSI Colors on Windows 10+
void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= 0x0004;  // ENABLE_VIRTUAL_TERMINAL_PROCESSING
    SetConsoleMode(hOut, dwMode);
}

// 7-segment digits
char *digits[10][3] = {
    {"\033[92m _ \033[0m", "\033[92m| |\033[0m", "\033[92m|_|\033[0m"}, // 0
    {"\033[92m   \033[0m", "\033[92m  |\033[0m", "\033[92m  |\033[0m"}, // 1
    {"\033[92m _ \033[0m", "\033[92m _|\033[0m", "\033[92m|_ \033[0m"}, // 2
    {"\033[92m _ \033[0m", "\033[92m _|\033[0m", "\033[92m _|\033[0m"}, // 3
    {"\033[92m   \033[0m", "\033[92m|_|\033[0m", "\033[92m  |\033[0m"}, // 4
    {"\033[92m _ \033[0m", "\033[92m|_ \033[0m", "\033[92m _|\033[0m"}, // 5
    {"\033[92m _ \033[0m", "\033[92m|_ \033[0m", "\033[92m|_|\033[0m"}, // 6
    {"\033[92m _ \033[0m", "\033[92m  |\033[0m", "\033[92m  |\033[0m"}, // 7
    {"\033[92m _ \033[0m", "\033[92m|_|\033[0m", "\033[92m|_|\033[0m"}, // 8
    {"\033[92m _ \033[0m", "\033[92m|_|\033[0m", "\033[92m _|\033[0m"}  // 9
};

// Print hour:minute:second in 7-segment
void printClockRow(int h1, int h2, int m1, int m2, int s1, int s2, int colonOn, int row) {
    printf("%s %s  ", digits[h1][row], digits[h2][row]);

    // blinking colon
    if (colonOn)
        printf("\033[93m:\033[0m  ");
    else
        printf("   ");

    printf("%s %s  ", digits[m1][row], digits[m2][row]);

    if (colonOn)
        printf("\033[93m:\033[0m  ");
    else
        printf("   ");

    printf("%s %s\n", digits[s1][row], digits[s2][row]);
}

int main() {
    enableANSI();

    int lastMinute = -1;
    int colonBlink = 1;

    while (1) {
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);

        int h1 = tm->tm_hour / 10;
        int h2 = tm->tm_hour % 10;

        int m1 = tm->tm_min / 10;
        int m2 = tm->tm_min % 10;

        int s1 = tm->tm_sec / 10;
        int s2 = tm->tm_sec % 10;

        system("cls");

        printf("\n            \033[96m DIGITAL CLOCK (7-SEGMENT) \033[0m\n\n");

        // 3 rows of 7-segment
        for (int r = 0; r < 3; r++) {
            printClockRow(h1, h2, m1, m2, s1, s2, colonBlink, r);
        }

        printf("\n  \033[94mTime: %02d:%02d:%02d\033[0m\n", tm->tm_hour, tm->tm_min, tm->tm_sec);
        printf("  \033[95mDate: %04d-%02d-%02d (%s)\033[0m\n",
               tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
               (char*[]){"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}[tm->tm_wday]);

        // Beep every new minute
        if (tm->tm_min != lastMinute) {
            Beep(750, 150);   // frequency + duration
            lastMinute = tm->tm_min;
        }

        colonBlink = !colonBlink; // blink colon
        Sleep(1000);
    }

    return 0;
}
