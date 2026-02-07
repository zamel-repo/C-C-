#include <stdio.h>

enum Day {
    SUNDAY = 1,
    MONDAY = 2,
    TUSDAY = 3,
    WEDNSDAY = 4,
    THURSDAY = 5,
    FRIDAY = 6,
    SATURDAY = 7
};

typedef enum __Action {
    START = 10,
    STOP = 20,
    PAUSE = 30,
    RESUME = 40
}__Action;


enum Day getNextDay(enum Day currentDay) {
    if (currentDay == SATURDAY) {
        return SUNDAY;
    } else {
        return (enum Day)(currentDay + 1);
    }
};

// enum Day getPreviousDay(enum Day currentDay) {
//     if(currentDay == SATURDAY) {
//         return SUNDAY;
//     }
//     else {
//         return (enum Day) (currentDay - 1);
//     }
// }

// enum Day getPreviousDay(enum Day currentDay) {
//     return (currentDay == SATURDAY) ? SUNDAY : (currentDay - 1);
// }

// enum Day getPreviousDay(enum Day currentDay) {
//     return (currentDay % 7) + 1
// }

typedef enum Types {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_DOUBLE
}Types;

typedef enum Status {
    SUCCESS = 1,
    FAILURE = 2,
    PENDING = 3
}Status;

int main() {
    // enum Day today = SUNDAY;
    // types type = TYPE_INT;

    // printf("Day number: %d\n", today);

    printf("Today is day number: %d\n", SUNDAY);
    enum Day tomorrow = getNextDay(SUNDAY);
    printf("Tomorrow is day number: %d\n", tomorrow);
    return 0;
}

void connectionStatus(enum Status status) {
    switch (status) {
        case SUCCESS:
            printf("Connection Successful\n");
            break;
        case FAILURE:
            printf("Connection Failed\n");
            break;
        case PENDING:
            printf("Connection Pending\n");
            break;      
        default:
            printf("Unknown Status\n");
    }
}

void whatIsAction(__Action action) {
    switch (action) {
        case START:
            printf("ACTION: START\n");
            break;
        case STOP:
            printf("ACTION: STOP\n");
            break;
        case PAUSE:
            printf("ACTION: PAUSE\n");
            break;
        case RESUME:
            printf("ACTION: RESUME\n");
            break;
        default:
            printf("Unknown Action\n");
    }
}