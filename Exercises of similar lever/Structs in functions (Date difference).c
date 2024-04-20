//A program that counts how much days and DMY passed between two dates
//inspired by my other program, that counts what day is next

#include <stdio.h>
#include <stdlib.h>

struct date {
    int day;
    int month;
    int year;
};

int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

void printDate(struct date);
void readDate(struct date *);
int daysPassedFunct(struct date *, struct date *);
void daysToYMD(int);
int isLeapYear(int);
float averageDays();

int main() {
    struct date date1, date2;
    
    averageDays();
    
    printf("Enter the first date (Format: DD MM YYYY): ");
    readDate(&date1);
    printf("Enter the second date (Format: DD MM YYYY): ");
    readDate(&date2);
    
    printf("the first date: ");
    printDate(date1);
    printf("the second date: ");
    printDate(date2);
    
    int daysPassedInt = daysPassedFunct(&date1, &date2);
    printf("Between these dates passed: %d days\n", daysPassedInt);
    
    daysToYMD(daysPassedInt);
    
    
   // struct date *difference = daysToYMD(&date1, &date2);
  //  printf(" Between these dates passed: %d years, %d months, %d days./n", difference->year, difference->month, difference->day);
    
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
	   
	   //case 1: same date
	   if (date1->day == date2->day && date1->month == date2->month && date1->year == date2->year) {
        return daysPassed;
    } 
    
    //diff day, same month, //same year
    if (date1->day != date2->day && date1->month ==date2->month && date1->year == date2->year) {  //maybe say if m=m y=y? 
        daysPassed += date2->day - date1->day;  
        printf("daysPassed, counted days (if same m same d): %d\n", daysPassed);
    }
    
    //diff month, 1<2
    if (date1->month < date2->month && date1->year <= date2->year) {
        daysPassed += daysInMonth[date1->month -1] - date1->day + date2->day;
        for (int monthi = (date1->month + 1); monthi < date2->month; monthi++) { //if month difference is >1
        	    daysPassed += daysInMonth[monthi - 1];
       	}
        printf("daysPassed, counted months, entered loop 1: %d\n", daysPassed);
    }
    
    
    //diff month, 1>2
    if (date1->month > date2->month && date1->year < date2->year) { //year1 is strictly more than year2
        daysPassed += daysInMonth[date1->month -1] - date1->day + date2->day;
       //count I times
       // int j = 12 - date1->month + date2->month;
        
        for (int i = date1->month; i < 12; i++) { //if month difference is >1
        	    daysPassed += daysInMonth[i];        //count until dec
             printf("daysPassed, loop2 count1: %d\n", daysPassed);
        }
        for (int i = 1; i < date2->month; i++) { //count up to date
        	    daysPassed += daysInMonth[i - 1];
        	    printf("daysPassed, loop2 count2: %d\n", daysPassed);
        	}
        printf("daysPassed,counted months, entered loop 2 where m1>m2: %d\n", daysPassed); 	
        daysPassed -= 365; //temporary crutch
        printf("daysPassed,counted months + crutch; %d\n", daysPassed) ;
    } 
    
    
	   
	   for (int yeari = date1->year; yeari <= (date2->year - 1); yeari++) { //for each year
        //check for each year, if that's a leap year, if yes, add a leap day
        daysPassed += (isLeapYear(yeari) && date1->month<=2)? 366 : 365;     
    } //or here loop through the daysInMonth?? seems more reliable
    
    printf("daysPassed, counted years: %d\n", daysPassed);
    return daysPassed;
}

int isLeapYear(int x) {
	   int answer = (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0); //ternary conditional operator again
    printf("isLeapYear    : %d\n", answer);
    return answer;
}
    /*
    According to the Gregorian calendar, most years divisible by 4 are leap years,
    but not all. Years that are divisible by 100 are not leap years, except for years
    that are also divisible by 400. */
    

void daysToYMD(int daysPassed) {
    struct date *difference = (struct date *)malloc(sizeof(struct date *));
    if (difference == NULL) {
        printf ("Memory allocation error\n");
         
    }
    
    difference->year = daysPassed / 365;
    daysPassed %= 365;
    printf("Years: %d\n", difference->year);
    
    difference->month = daysPassed / 30;
    daysPassed %= 30;
    printf("Months: %d\n", difference->month);
    
    difference->day = daysPassed;
    printf("Days: %d\n", difference->day);
    free(difference);
}

float averageDays () {
	   int x = 0;
	   float y = 0.0;
	   for (int i=0; i<4; i++) {
	   	   x += 365;
    }
    x++; //29 Feb
    y = ((float)x/48.0); //48 = 12 months * 4 years
    printf("Average days in month, including leap year: %f\n", y);
    return y;
}
