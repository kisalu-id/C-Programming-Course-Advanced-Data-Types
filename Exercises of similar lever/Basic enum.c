#include <stdio.h>

enum year {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

int main() {
    int i;
    printf("Printing out all months as numbers:\n");
    
    for (i=Jan; i<=Dec; i++)      
        printf("%d ", i);

   return 0;
}
