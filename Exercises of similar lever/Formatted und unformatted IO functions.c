#include <stdio.h>
//#include <conio.h> //header file specific to some DOS and Windows compilers, it's not part of the standard C library, not portable across different systems - rather avoid
//will comment out parts with conio.h functiins
 
int main() {
    char myString[50];
    int k = 10;
    int l = 5;
    int m = 2;
    int x;

    //formatted
    //sprintf prints the string into a character array
    sprintf(myString, "%d = %d * %d\n", k, l, m);
    printf("%s", myString);

    //sscanf reads data from the string or character array
    sscanf(myString, "%*d = %d", &x); 
    printf("Copied value from the string myString that's now stored in x is: %d\n", x);


    //unformatted
    char a, str[100];

//getch() reads a single character, doesn’t display that character on the console screen and immediately returnes without pressing enter key
//declared in conio.h(header file), like some other functions
//also used to hold the screen.
    //printf("Enter any character, it will not be printed out:\n");
    //getch(); //conio.h

//getche() reads a single character from the keyboard by the user and displays it on the console screen and immediately returns without pressing the enter key
    //printf("\nEnter any character, it will be printed out:\n");
    //getche(); //conio.h

//getchar() used to read only a first single character, whether multiple characters are typed
//reads one character at one time until and unless the enter key is pressed
    printf("\nEnter any character(s), only the first one will be read:\n");
    a = getchar();
    printf("\nThe character you've entered is:\n");
    putchar(a);

    printf("\nEnter a sentence, it's possible to include white spaces:\n");
//gets() considered unsafe because it does not perform bounds checking, which can lead to buffer overflow vulnerabilities; rather use fgets
    //gets(str);
    //puts(str);

//fgets(), "file get string", allows to specify the maximum number of characters to read
//reads until a new line, maximum number of characters or EOF condition
//returns the pointer to the destination string (str), or NULL if an error occurs, if the end-of-file EOF is reached
    printf("\nEnter another sentence, it's possible to include white spaces:\n");
    fgets(str, sizeof(str), stdin);
    printf("You entered (fgets): %s", str);

   //putch() used to display a single character which is given by the user and that character prints at the current cursor location
    //putch(a); //conio.h

//%[^\n] edit conversion code, can be used to read a line containing characters like variables and even whitespaces until a new line
//in general scanf() function with format specification like %s and specification with the field width in the form of %ws can read-only strings till the non-whitespace part - it means they can't be used for reading a text containing more than one word, especially with whitespaces
    printf("\nEnter another sentence, it's possible to include white spaces:\n");
    scanf("%99[^\n]%*c", str); //reads a line of text until 99% , then it will stop before buffer overflow, %*c to consume a newline
    printf("You entered (scanf): %s\n", str);
    
    printf("Testing puts() function:\n");
    puts(str);

    return 0;
}
