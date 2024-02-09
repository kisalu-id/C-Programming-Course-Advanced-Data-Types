/* You'd like to implement a date feature in the C programming language. To this end you are provided with a structure definition, a main function, and two function prototypes: "readDate()" and "printDate()". All that is left for you to do is to write these two functions.

The function readDate() should read 3 integers from the user input. The first integer is the year (a 4-digit number), the second integer is the month, and the third integer is the day of the date being read. The function should store these three numbers in the appropriate parts of the structure being passed into it.

The function printDate() should print the date stored in the variable passed into it in the following format: mm/dd/yyyy with a new line afterwards. So the month should be printed with two digits (01, 02, 03, ..., 11, 12), the day should be printed as two digits (01, 02, 03, ..., 30, 31), and the year should be printed as a 4-digit number.

You should not modify the provided code.
Warning: You will be graded on your output, so do not include any additional print statements that, for example, prompt a user for input.

Example
Input:
2018 10 2

Output:
10/02/2018
*/

#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void readDate(struct date *);
void printDate(struct date);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}

void readDate(struct date *dateptr) {
    scanf("%4d %02d %02d", &(*dateptr).year, &(*dateptr).month, &(*dateptr).day);
}
void printDate(struct date a) {
    printf("%02d/%02d/%04d", a.month, a.day, a.year);
}
