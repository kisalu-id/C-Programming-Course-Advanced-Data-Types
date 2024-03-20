//preprocessor parses the program, makes sure that the compiler gets everything needs before going on;
//it looks up all the header files I include with the #include directive.
//it looks at every constant defined using #define and substitutes it with its actual value


#include <stdio.h>

typedef enum {
  pervious, 
  current, 
  past
} YEAR;

#define PI 3.14159265359 //symbolic constant, it's a value

#define POWER(x) ((x) * (x)) //macro, can accept an argument

int main() {

#ifdef PI
printf("Pi is: %f\n", PI);
printf("Pi * Pi is: %f\n", POWER(PI));
#else
printf("Pi is not defined\n");
#endif

printf("5 * 5 is: %d\n", POWER(5));

YEAR current = 2024;

printf("Current year is: %d", current);

return 0;
}
