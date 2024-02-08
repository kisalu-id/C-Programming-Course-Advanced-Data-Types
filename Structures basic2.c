#include <stdio.h>

struct date {
    int year;
    int month;
    int day;
};

//void yearsCount (struct date, struct date);

int main () {
    //! showMemory(start=65520)
    printf("This is a program that counts approximate age of a person (just for training structures)\n");
    struct date today;
    printf("Enter today's date in the format \"year month day\", for example: 2024 08 29\n");
    scanf("%d %d %d", &today.year, &today.month, &today.day);
    struct date dateBirth;
    printf("Enter your date of birth: ");
    scanf("%d %d %d", &dateBirth.year, &dateBirth.month, &dateBirth.day);
    //yearsCount(today.year, dateBirth.year);
    printf("Your age is approximately %d\n", (today.year - dateBirth.year));
    return 0;
}

/*
void yearsCount (struct date a, struct date b) {
    printf("Your age is approximately %d\n", (date.a - date.b));
}
*/
