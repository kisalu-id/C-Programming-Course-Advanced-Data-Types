#include <stdio.h>
 
int main() {
    char myString[50];
    int a = 10;
    int b = 5;
    int c = 2;
    int x;

    //sprintf prints the string into a character array
    sprintf(myString, "%d = %d * %d\n", a, b, c);
    
    printf("%s", myString);

    //sscanf reads data from the string or character array
    sscanf(myString, "b = %d", &x); 
    printf("Copied value from the string myString that's now stored in x is: %d\n", x);

    //Unformatted
    char a, b, c;
//getch() reads a single character, doesn’t display that character on the console screen and immediately returnes without pressing enter key
//declared in conio.h(header file), like others
//also used to hold the screen.
    printf("Enter any character, it will not be printed out:\n");
    getch(); 


//getche() reads a single character from the keyboard by the user and displays it on the console screen and immediately returns without pressing the enter key
    printf("\nEnter any character, it will be printed out:\n");
    getche();

//getchar() used to read only a first single character, whether multiple characters are typed
//reads one character at one time until and unless the enter key is pressed
printf("\nEnter any character(s), it will be printed out:\n");
    a = getchar();
    printf("\nThe character you've entered is: %c\n", a);
    return 0; 
}
