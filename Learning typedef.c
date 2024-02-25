//it's not from this course, but fits the topic

/*
#include <stdio.h>

typedef struct employee { 
    int age;
    double salary;
} emp; //alias


int main () {
    //! showMemory(start=65520)
    emp a1;
    a1.salary = 3987.23;
    emp a2 = {.age = 45, .salary = 4276.08};
    printf("Salary given to for workers a1 and a2 is: %.2lf\n", a1.salary + a2.salary);
    
    return 0;
}
*/

//OR 

#include <stdio.h>

struct employee { 
    int age;
    double salary;
} a1, a2; //create variables

typedef struct employee emp; //alias

int main () {
    //! showMemory(start=65520)
    a1.salary = 3987.23;
    //for some reason copypasting line 16 here isn't working
    a2.salary = 4276.08;
    printf("Salary given to for workers a1 and a2 is: %.2lf\n", a1.salary + a2.salary);
    
    return 0;
}
