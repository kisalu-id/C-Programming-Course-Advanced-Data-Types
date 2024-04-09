//A program that counts how much days and DMY passed between two dates
//inspired by my other program, that counts what day is next

#include <stdio.h>
#include <stdlib.h>

struct date {
    int day;
    int month;
    int year;
};

void printDate(struct date);
void readDate(struct date *);
int daysPassedFunct(struct date *, struct date *);
struct date* daysToYMD(struct date *, struct date *);//very unsure about structs as arguments and return value :/ we'll see
int isLeapYear(int);

int main() {
    struct date date1, date2;
    
    printf("Enter the first date (Format: DD MM YYYY): ");
    readDate(&date1);
    printf("Enter the second date (Format: DD MM YYYY): ");
    readDate(&date2);
    
    int daysPassedInt = daysPassedFunct(date1, date2);
    printf(" Between these dates passed: %d days/n", daysPassedInt);
    
    struct date *difference = daysToYMD(date1, date2);
    printf(" Between these dates passed: %d years, %d months, %d days./n", difference->year, difference->month, difference->day);
    
    return 0;
}

void readDate(struct date *x) {
    scanf("%d %d %d", &x->day, &x->month, &x->year);
}

void printDate(struct date x) {
    printf("%02d/%02d/%04d\n", x.day, x.month, x.year);
}

int daysPassedFunct(struct date *date1, struct date *date2) {
	   int daysPassed = 0;
	   int yearsPassed = date2->year - date1->year; //count how much years passed
	   for (int yeari = date1->year; yeari < date2->year; yeari++) { //for each year
        //check for each year, if that's a leap year, if yes, add a leap day
        daysPassed += isLeapYear(yeari) ? 366 : 365;
            
    }
    
    //add days and monthsfor the incomplete year
    //array for month that has the amount of days? 
    
    return daysPassed;
}


struct date* daysToYMD(struct date *date1, struct date *date2) {

return
}

int isLeapYear(int x) { //!! read how leap years are counted
    return (x % 4 == 0) ? 1 : 0; //ternary conditional operator again
            
}


// Language:C 
// Copy the full code and open the CCoder APP to run it. 
// CCoder APP download link：https://play.google.com/store/apps/details?id=com.ikou.ccoding 
