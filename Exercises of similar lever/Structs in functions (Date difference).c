
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
struct date* daysToYMD(struct date *, struct date *);//very unsure about structs as arguments and return value :/ we'll see
int isLeapYear(int);

int main() {
    struct date date1, date2;
    
    printf("Enter the first date (Format: DD MM YYYY): ");
    readDate(&date1);
    printf("Enter the second date (Format: DD MM YYYY): ");
    readDate(&date2);
    
    printf("the first date: ");
    printDate(date1);
    printf("the second date: ");
    printDate(date2);
    
    int daysPassedInt = daysPassedFunct(&date1, &date2);
    printf(" Between these dates passed: %d days\n", daysPassedInt);
    
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
    } //diff day, same month, same year
    
    else if (date1->day != date2->day && date1->month == date2->month && date1->year == date2->year) {
        daysPassed = date2->day - date1->day;  
    } //diff month, same year
    else if (date1->month != date2->month && date1->year == date2->year) {
        daysPassed = daysInMonth[date1->month -1] - date1->day + date2->day;
        for (int monthi = (date1->month + 1); monthi < date2->month; monthi++) { //if month difference is >1
        	    daysPassed += daysInMonth[monthi - 1];
        	}
    }
    	    
   
	   
	   for (int yeari = date1->year; yeari < date2->year; yeari++) { //for each year
        //check for each year, if that's a leap year, if yes, add a leap day
        daysPassed += isLeapYear(yeari) ? 366 : 365;     
    }
    
    printf("daysPassed, counted years: %d\n", daysPassed);
    return daysPassed;
}
    
    /*
    if (date1->year < date2->year) {
    //add days and monthsfor the incomplete year of date1; -1 everywhere for daysInMonth
    for (int month = date1->month; month < date2->month; month++) {
    	     printf("daysPassed, will count month%d: current counter %d\n", month, daysPassed);
     
        	daysPassed -= daysInMonth[month - 1];
        	if (month == 2 && isLeapYear(date1->year)) {//account for leap years 
            	daysPassed--;
        	}
     }
     
     printf("daysPassed, counted months: %d\n", daysPassed);
     
         //adjusting for the incomplete month.
         
         daysPassed = daysPassed - (daysInMonth[(date1->month) - 1] - date1->day); 
    }
    
    
    
    //the problem is: I need to make a coherent plan to handle days, moths and years. to not do bs if there's no difference in months/years
    
    
    
    
    
   //  daysPassed = daysPassed - (daysInMonth[date1->month - 1] - date1->day); 
    printf("daysPassed days: %d\n", daysPassed);
    
    //add days for incomplete year of date2
    for (int month = date1->month; date1->month < date2->month; month++) {
    	    daysPassed += daysInMonth[month -1]; //-1 here and earlier bc array starts at index 0
    	    if (month == 2 && isLeapYear(date2->year)) {//account for leap years 
            	daysPassed++;
        	}
    	   
    	}
    	daysPassed = daysPassed - date1->day;
    	printf("date 2 daysPassed months: %d\n", daysPassed);
    daysPassed += date2->day;
    printf("date 2 daysPassed days: %d\n", daysPassed);
    
    return daysPassed;
}


struct date* daysToYMD(struct date *date1, struct date *date2) {
    
//return
}
*/

int isLeapYear(int x) {
	   int answer = (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0); 
    return answer;}
    /*ternary conditional operator again
    According to the Gregorian calendar, most years divisible by 4 are leap years,
    but not all. Years that are divisible by 100 are not leap years, except for years
    that are also divisible by 400. */
    




// Language:C 
// Copy the full code and open the CCoder APP to run it. 
// CCoder APP download link：https://play.google.com/store/apps/details?id=com.ikou.ccoding 
