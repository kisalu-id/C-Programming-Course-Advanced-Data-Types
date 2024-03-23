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
    
    return 0; 
}
