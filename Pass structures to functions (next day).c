/*In this problem you will continue developing the data feature which you started implementing in the previous problem. You will implement a "tomorrow" feature in the C programming language via a function called "advanceDay()". The function advanceDay() should take as input a date (stored in a struct date) and return the date of the following day. You do not have to take into account leap years (although you may if you wish to). That is, it is okay for your function to always return March 1 as the day following February 28, no matter the year.

You are provided with a familiar date structure definition, a main function as well as the function prototypes for the readDate(), printDate(), and advanceDay() functions. Do not modify any of the given code. Simply add your function definitions underneath the main() function. For the readDate() and printDate() functions you may simply copy and paste the code you developed in the previous task.
 
Examples
Input:
2018 10 2
Output:
10/02/2018                                                                      
10/03/2018
 
Input:
2018 10 31
Output:
10/31/2018                                                                      
11/01/2018

Input:
2018 11 30
Output:
11/30/2018                                                                      
12/01/2018                                                                      
 
Input:
2018 12 31
Output:
12/31/2018                                                                      
01/01/2019 */

#include <stdio.h>
#include <stdlib.h>

struct date {
    int day;
    int month;
    int year;
};

void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 
void errorMsg();

int main(void) {
 struct date today, tomorrow;
 
 printf("What is the date today? (Format is DD MM YYYY)\n");
 readDate(&today);
 tomorrow = advanceDay(today);
 printf("Tomorrow is:\n");
 printDate(tomorrow);
 printf("Today is:\n");
 printDate(today);
 return 0;
}

/* add your function definitions here */

void readDate(struct date *dateptr) {
    //changed format from what asked in exercise to more traditional for me: DD/MM/YYYY
    scanf("%d %d %d", &dateptr->day, &dateptr->month, &dateptr->year); //same as &(*dateptr).month
}

void printDate(struct date x) {
    printf("%02d/%02d/%04d\n", x.day, x.month, x.year);
}

struct date advanceDay(struct date today) {
    int monthMax = -10;
    //for typing faster and saving today's values:
    int d = today.day;
    int m = today.month;
    int y = today.year;
    struct date tomorrow;
    
    //no negative ints allowed here >:(
    if ( (m<1) || (d<1) || (y<1) ) {
        printf("You cant't count dates with negative integers.");
        errorMsg();
    }
    
    //define max days in month
    else if (m == 2) {
            if ((y % 4) != 0) {
                monthMax = 28;
            } else {
                monthMax = 29;
            }
    }
    else if ( (m==4) || (m== 6) || (m==9) || (m==11) ) {
        monthMax = 30;
    }
    else if ( (m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12) ) {
        monthMax = 31;
    } else {
    printf("Incorrect month.");
        errorMsg();
    }
    
    //upd day, take care of day exceeding monthMax
    if (d < monthMax && d > 0) {
        d++;
    }
    else if (d == monthMax) {
        d = 1;
        if (m==12) {
            m = 1;
            y++;
        } else {
            m++;
        }
    } else {
        printf("Incorrect day.");
        errorMsg();
    }
    
    if (y>9999) {
        printf("C'mon\nI'm just a compooter, I can't deal with 5-digit years TwT");
        errorMsg();
    }
    
    //assign result to other structure element so initial values from today will stay    
    tomorrow.day = d;
    tomorrow.month = m;
    tomorrow.year = y;
    return tomorrow;
}

//to not copypaste
void errorMsg() {
    printf("\nTerminating the program.");
    exit(0);
}
