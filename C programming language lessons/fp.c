#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

// Enable ANSI Colors
void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= 0x0004;  // ENABLE_VIRTUAL_TERMINAL_PROCESSING
    SetConsoleMode(hOut, dwMode);
}

// Move cursor
void setCursorPos(int x,int y){
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

// 7-segment digits
char *digits[10][3]={
    {"\033[92m _ \033[0m","\033[92m| |\033[0m","\033[92m|_|\033[0m"},
    {"\033[92m   \033[0m","\033[92m  |\033[0m","\033[92m  |\033[0m"},
    {"\033[92m _ \033[0m","\033[92m _|\033[0m","\033[92m|_ \033[0m"},
    {"\033[92m _ \033[0m","\033[92m _|\033[0m","\033[92m _|\033[0m"},
    {"\033[92m   \033[0m","\033[92m|_|\033[0m","\033[92m  |\033[0m"},
    {"\033[92m _ \033[0m","\033[92m|_ \033[0m","\033[92m _|\033[0m"},
    {"\033[92m _ \033[0m","\033[92m|_ \033[0m","\033[92m|_|\033[0m"},
    {"\033[92m _ \033[0m","\033[92m  |\033[0m","\033[92m  |\033[0m"},
    {"\033[92m _ \033[0m","\033[92m|_|\033[0m","\033[92m|_|\033[0m"},
    {"\033[92m _ \033[0m","\033[92m|_|\033[0m","\033[92m _|\033[0m"}
};

// Print one row
void printClockRow(int h1,int h2,int m1,int m2,int s1,int s2,int colon,int row){
    printf("%s %s  ",digits[h1][row],digits[h2][row]);
    if(colon) printf("\033[93m:\033[0m  "); else printf("   ");
    printf("%s %s  ",digits[m1][row],digits[m2][row]);
    if(colon) printf("\033[93m:\033[0m  "); else printf("   ");
    printf("%s %s",digits[s1][row],digits[s2][row]);
}

// Print menu
void printMenu(){
    printf("\033[94mOptions Menu:\033[0m\n");
    printf("1) Toggle Seconds\n");
    printf("2) Change Color\n");
    printf("3) 12/24 Hour Format\n");
    printf("4) Exit\n");
}

int main(){
    enableANSI();

    int lastMinute=-1;
    int colonBlink=1;
    int showSeconds=1;
    int hour24=1;
    int color=92;
    char message[50]="";
    char input[10]="";

    system("cls");

    // Static layout
    setCursorPos(0,0);
    printf("\033[96mDIGITAL CLOCK (7-SEGMENT)\033[0m\n");
    setCursorPos(0,4);
    printf("\033[91m_______________________________________\033[0m\n");
    setCursorPos(0,6);
    printMenu();
    setCursorPos(0,12);
    printf("Enter choice: ");

    int running=1;
    int inputPos=0;

    while(running){
        time_t t=time(NULL);
        struct tm *tm=localtime(&t);

        int hour=tm->tm_hour;
        if(!hour24 && hour>12) hour-=12;

        int h1=hour/10,h2=hour%10;
        int m1=tm->tm_min/10,m2=tm->tm_min%10;
        int s1=tm->tm_sec/10,s2=tm->tm_sec%10;

        // Print clock
        setCursorPos(0,1);
        for(int r=0;r<3;r++){
            printClockRow(h1,h2,m1,m2,s1,s2,colonBlink,r);
            printf("\n");
        }

        // Time & Date
        setCursorPos(0,10);
        printf("                                        ");
        setCursorPos(0,10);
        if(showSeconds)
            printf("\033[%dmTime: %02d:%02d:%02d\033[0m\n",color,hour,tm->tm_min,tm->tm_sec);
        else
            printf("\033[%dmTime: %02d:%02d\033[0m\n",color,hour,tm->tm_min);

        setCursorPos(0,11);
        printf("  \033[95mDate: %04d-%02d-%02d (%s)\033[0m\n",
            tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,
            (char*[]){"Sun","Mon","Tue","Wed","Thu","Fri","Sat"}[tm->tm_wday]);

        // Print message
        setCursorPos(0,13);
        printf("                                        ");
        setCursorPos(0,13);
        if(message[0]!='\0') printf("\033[93m%s\033[0m",message);

        // Input handling without blocking
        setCursorPos(14,12); // after "Enter choice: "
        while(_kbhit()){
            char ch=_getch();
            if(ch=='\r'){ // Enter
                input[inputPos]='\0';
                int choice=atoi(input);
                switch(choice){
                    case 1: showSeconds=!showSeconds; strcpy(message,"Seconds toggled!"); break;
                    case 2: color=(color==92)?96:92; strcpy(message,"Color changed!"); break;
                    case 3: hour24=!hour24; strcpy(message,"Hour format toggled!"); break;
                    case 4: strcpy(message,"Exiting program..."); running=0; break;
                    default: strcpy(message,"Invalid choice!"); break;
                }
                inputPos=0;
                input[0]='\0';
            } else if(ch=='\b'){ // Backspace
                if(inputPos>0) inputPos--;
                input[inputPos]='\0';
            } else if(ch>='0' && ch<='9'){ // Numbers
                input[inputPos++]=ch;
                input[inputPos]='\0';
            }
            setCursorPos(14,12);
            printf("          "); // clear old input
            setCursorPos(14,12);
            printf("%s",input);
        }

        // Colon blink & beep
        colonBlink=!colonBlink;
        if(tm->tm_min!=lastMinute){
            Beep(750,150);
            lastMinute=tm->tm_min;
        }

        Sleep(200);
    }

    return 0;
}
