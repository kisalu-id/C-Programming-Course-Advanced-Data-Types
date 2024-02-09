#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

void dateScan (struct date *);
void yearsCount (struct date, struct date);

int main () {
    //! showMemory(start=65520)
    printf("This is a program that counts approximate age of a person\n(just for training structures)\n");
    
    struct date today;
    printf("Enter today's date using the format \"day month year\", for example: 09 02 2024\n");
    dateScan(&today);
    
    struct date birthday;
    printf("Enter your date of birth:\n");
    dateScan(&birthday);
    yearsCount(today, birthday);
    return 0;
}

//modify the variable of structure in main function
void dateScan (struct date *dateptr) {
    scanf("%d %d %d", &(*dateptr).day, &(*dateptr).month, &(*dateptr).year);
}

void yearsCount (struct date a, struct date b) {
    printf("Your age is approximately %d\n", (a.year - b.year));
}
