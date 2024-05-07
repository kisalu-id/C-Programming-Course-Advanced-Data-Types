//A program that counts how much days and DMY passed between two dates
//inspired by my other program, that counts what day is next

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <math.h>

struct date {
    int day;
    int month;
    int year;
};

int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leapYears = 0;

void printDate(struct date);
void readDate(struct date *);
int daysPassedFunct(struct date *, struct date *);
void daysToYMD(int, float);
int isLeapYear(int);
float averageDays();
int valiDate(struct date *);
void dayOfWeek(int);
void alternativeTimeUnits(int);
void swapDates (struct date *, struct date *);

int main() {
    struct date date1, date2;
    float avgDays = averageDays();
    int a, b;
    struct date *dateX = (struct date *)malloc(sizeof(struct date));
    //1 Jan 2024 is Monday
    dateX->day = 1;
    dateX->month = 1;
    dateX->year = 2024; //I'll be counting: a(date differece between date1 and dateX) + b(date differece between dateX and date2)
    

    printf("Enter the first date (Format: DD MM YYYY): ");
    readDate(&date1);
    if (!valiDate(&date1)) {
        return 0;
    }
    
    printf("Enter the second date (Format: DD MM YYYY): ");
    readDate(&date2);
    
    if (!valiDate(&date2)) {
        return 0;
    }

    //error handling
    //regex positive numbers
    if (valiDate(&date2)) {
        //if user input 33 14 2024
        if (!((date1.day == 29 && date1.month == 2 && isLeapYear(date1.year))
        || (date2.day == 29 && date2.month == 2 && isLeapYear(date2.year)))) {
            if ((date1.day > daysInMonth[date1.month -1]) || (date2.day > daysInMonth[date2.month -1])) {
                fprintf(stderr, "This date doesn't exist\n");
                return 0;
            }
        }
        
        /* //here do swap funct!!! then it will make sense to make a and b positive
        if (date1 > date2)
        swapDates (struct date *date1, struct date *date2) {} */
        
        a = abs(daysPassedFunct(&date1, dateX)); //make it positive
        b = abs(daysPassedFunct(dateX, &date2));

        int daysPassedInt = a + b;



        if (daysPassedInt < 0) {
            fprintf(stderr, "Error: negative number\n");
            return 0;
        }

        printf("\nThe first date: ");
        printDate(date1);
        printf("The second date: ");
        printDate(date2);

        printf("\n\nBetween these dates passed: %d days\n", daysPassedInt);
        
        printDate(date1);
        dayOfWeek(a);
        
        printDate(date2);
        dayOfWeek(b);
        daysToYMD(daysPassedInt, avgDays);
        
        alternativeTimeUnits(daysPassedInt);
    }

    return 0;
}



void readDate(struct date *x) {
    scanf("%d %d %d", &x->day, &x->month, &x->year);
}


void printDate(struct date x) {
    printf("%02d/%02d/%04d\n", x.day, x.month, x.year);
}


//do a scheme that covers for different cases
int daysPassedFunct(struct date *date1, struct date *date2) {
    int daysPassed = 0;
     printf("115\n");
     printf("checking years 1: %d\n", date1->year);
     printf("checking years 2: %d\n", date2->year);

    //case 1: same date
    if (date1->day == date2->day && date1->month == date2->month && date1->year == date2->year) {
        return daysPassed;
    }

    //diff day, same month, same year
    if (date1->day != date2->day && date1->month == date2->month && date1->year == date2->year) {
        daysPassed += date2->day - date1->day;
        printf("daysPassed, counted days (if same m same d): %d\n", daysPassed);
    }

     printf("130!!!!!!test: %d\n", daysPassed);
     printf("checking years 1: %d\n", date1->year);
     printf("checking years 2: %d\n", date2->year);



    //diff month, 1<2
    if (date1->month < date2->month && date1->year <= date2->year) {
        daysPassed += daysInMonth[date1->month -1] - date1->day + date2->day;
        for (int monthi = (date1->month + 1); monthi < date2->month; monthi++) { //if month difference is >1
            daysPassed += daysInMonth[monthi - 1];
         }


        printf("daysPassed, counted months, entered loop 1: %d\n", daysPassed);
        printf("145checking years 1: %d\n", date1->year);
        printf("checking years 2: %d\n", date2->year);



        /*
        if (date1->year = date2->year) {
            daysPassed -= 365;
        } else {
            daysPassed += 365;
        }
        */
        printf("daysPassed, counted months, entered loop 1, dealt with years!!!: %d\n", daysPassed);
    }


    printf("161checking years 1: %d\n", date1->year);
    printf("checking years 2: %d\n", date2->year);


    if (date1->year < date2->year) {
        daysPassed += 365;
    }


    printf("170!!!!!!test: %d\n", daysPassed);

    //diff month, 1>2
    if (date1->month > date2->month && date1->year < date2->year) { //year1 is strictly more than year2
        daysPassed += daysInMonth[date1->month -1] - date1->day + date2->day;
       //count i times
        for (int i = date1->month; i < 12; i++) { //if month difference is >1
            daysPassed += daysInMonth[i];         //count until dec
            //printf("daysPassed, loop2 count1: %d\n", daysPassed);
        }

        for (int i = 1; i < date2->month; i++) { //count up to date
            daysPassed += daysInMonth[i - 1];
            //printf("daysPassed, loop2 count2: %d\n", daysPassed);
        }

        printf("daysPassed,counted months, entered loop 2 where m1>m2: %d\n", daysPassed);


        //daysPassed -= 365; //temporary crutch
        printf("daysPassed,counted months + crutch; %d\n", daysPassed) ;
    }

    for (int yeari = (date1->year + 1); yeari <= (date2->year - 1); yeari++) { //for each year
        //check for each year, if that's a leap year, if yes, add a leap day
        if (isLeapYear(yeari)) {
            daysPassed ++;
            leapYears++;
        }
        daysPassed += 365;
        printf("!!!!!!Leapyears: %d\n", leapYears);
    }
    printf("202!!!!!!test: %d\n", daysPassed);
    //daysPassed += 365;



     printf("checking years 1: %d\n", date1->year);
    printf("checking years 2: %d\n", date2->year);


    //account for 29th Feb
    if (isLeapYear(date1->year)) {
        if ((date1->day <= 29 && date1->month == 2) || (date1->month ==1)) { //if start date is before or equal to 29th Feb
            daysPassed++;
            leapYears++;
        } printf("216!!!!!!test: %d\n", daysPassed);
    }
    
    
    
printf("221!!!!!!test: %d\n", daysPassed);
    if (isLeapYear (date1->year) && (date1->year == date2->year) &&	((date2->day < 29 && date1->month == 2) || (date2->month == 1))     ) {//crutch for cases like 1.1.2024 - 1.2.2024
        daysPassed--;
        printf("224!!!!!!SUBSTRACTED 1: %d\n", daysPassed);  
    }
printf("225!!!!!!test: %d\n", daysPassed);    
    
    
    if (isLeapYear(date2->year) && (date1->year != date2->year)) {
        if ((date2->day == 29 && date2->month == 2) || (date2->month > 2)) { //if end date is equal or after 29th Feb
            daysPassed++;
            leapYears++;
        }
    }


    printf("daysPassed, counted years: %d\n", daysPassed);
    return daysPassed;
}


int isLeapYear(int x) {
    int answer = (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0); //ternary conditional operator again
    printf("isLeapYear: %d\n", answer);
    return answer;
}
    /* According to the Gregorian calendar, most years divisible by 4 are leap years,
    but not all. Years that are divisible by 100 are not leap years, except for years
    that are also divisible by 400. */


void daysToYMD(int daysPassed, float averageDays) {

    //pass date1 date 2, loop isLeapYear



    struct date *difference = (struct date *)malloc(sizeof(struct date));
    if (difference == NULL) {
        printf ("Memory allocation error\n");
    }

    difference->year = (daysPassed - leapYears) / 365;
    daysPassed %= 365;
    printf("Years: %d\n", difference->year);


    //difference->month = round((float)daysPassed / averageDays);
    //printf("daystoYMD diff months rounded typecasting : %d\n", difference->month);

    /*attempt to tame months
    fdaysPassed = (float)daysPassed
    difference->month = fdaysPassed / averageDays;

    (float)daysPassed %= averageDays;
    (int)daysPassed;
    */

    //prev code
    difference->month = daysPassed / 30;
    daysPassed %= 30;
    printf("Months: %d\n", difference->month);

    difference->day = daysPassed;
    printf("Days: %d\n\n", difference->day);

    if (difference->year > 0) {
        printf("It is %d years, %d months and %d days\n", difference->year, difference->month, difference->day);
        printf("It is %d months and %d days\n", (difference->month + (difference->year *12)), difference->day);
    }
    else if (difference->year == 0) {
        printf("It is %d months and %d days\n", difference->month, difference->day);
    }

    free(difference);
}


float averageDays () {
    int x = 0;
    float y = 0.0;
    for (int i=0; i<4; i++) {
        x += 365;
    }
    x++; //29 Feb
    y = ((float)x/48.0); //48 = 12 months * 4 years from the for loop
    printf("Average days in month, including leap year: %f\n\n", y);
    return y;
}


int valiDate(struct date *x) {
    char xStr[11]; //lets say max 10 characters
    regex_t regex;
    int regexCompilation;
    int regexExecution;

    //sprintf to format the date components into a string buff
    sprintf(xStr, "%02d %02d %04d", x->day, x->month, x->year);

    regexCompilation = regcomp(&regex, "^(0[1-9]|[1-2][0-9]|3[0-1]) (0[1-9]|1[0-2]) [0-9]{4}$", REG_EXTENDED); //check if regex is correct

    if (regexCompilation) {
        fprintf(stderr, "Regex compilation failed\n");
        return 0;
    }

    //commpare the date input with the regex pattern
    regexExecution = regexec(&regex, xStr, 0, NULL, 0); //only works with strings
    regfree(&regex);

    if (regexExecution == 0){
        return 1;
    }
    else if (regexExecution == REG_NOMATCH) {
        fprintf(stderr, "Invalid date format.\n");
    } else {
        fprintf(stderr, "Regex error...\n");
    }

    return 0;
}


void dayOfWeek (int x) {
     printf("365 x =: %d\n", x);  
    if (x < 0) {
        x--;
        x = abs(x);
    }
    x %= 7;
    
    printf("372 x =: %d\n", x);  

    //switch if 1 - mon, etc.
    switch (x) {
        case 0:
            printf(" is Sunday.\n");
            break;
        case 1:
            printf(" is Monday.\n");
            break;
        case 2:
            printf(" is Tuesday.\n");
            break;
        case 3:
            printf(" is Wednesday.\n");
            break;
        case 4:
            printf(" is Thursday.\n");
            break;
         case 5:
            printf(" is Friday.\n");
            break;
         case 6:
            printf(" is Saturday.\n");
            break;
        default:
            fprintf(stderr, "Error in detecting dayOfWeek2\n");
            //return -1; warning here, for now comment oput
    }
}

void alternativeTimeUnits(int daysPassed) {
    long long int daysPassedLong = (long long int)daysPassed * 24;
    printf("\n\nIt is %lld hours\n", daysPassedLong);
    daysPassedLong *= 60;
    printf("It is %lld minutes\n", daysPassedLong);
    daysPassedLong *= 60;
    printf("It is %lld seconds\n", daysPassedLong);
}



void swapDates (struct date *date1, struct date *date2) {
struct date temp = *date1;  // Create a temporary struct date to hold the values of date1
*date1 = *date2;            // Assign the values of date2 to date1
*date2 = temp; 
    

    printf("\nSWAPDATES The first date: ");
    printDate(*date1);
    printf("\nSWAPDATESThe second date: ");
    printDate(*date2);

}

    /* add feature of swapping?
    struct date *temp = date1;
    date1 = date2;
    date2 = temp;
    */


//!!! add fgets

//add count only workdays?

//daystoymd divide dayspassed / 365*4+1

/*
Solve sub-problem first:
in daysPassedFunct count how much days passed between date1 and dateX (1 Jan 2024, Mon)
and between 1 Jan 2024 and date2
return sum for the main function, handle negative nums differently?
use same results to count which date of week both dates are
edit pointers to daysPassed1 and daysPassed2
do sum
= daysPassed
*/
