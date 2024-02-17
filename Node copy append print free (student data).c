/*
In this task you will continue working on the linked list of students in which you would like to store, for each student, their name and age. As before you are provided with some code that you should not modify:

    A structure definition for the storage of each student's information.
    A main() function to test your code. 
    Prototypes for the functions createStudent(), append(), printStudents (from previous tasks) and freeStudents() (from the current task).

You will need the function definitions that you already wrote (from previous tasks) for createStudent(), append(), printStudents() as well as any other functions you added, such as copyStr() for example.
Warning: You will be graded on your output, so do not include any print statements that prompt a user for input.*/

#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[50], int studentAge);
struct student * append(struct student * end, struct student * newStudptr); 
void printStudents(struct student *start);
void freeStudents(struct student *start);
void copyStr(char *, char *);

int main(void) {
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    freeStudents(start);

    return 0;
}

/* Place your function definitions here. Be sure to include the definitions for 
   createStudent() and append() as well as any other functions you created for 
   the previous tasks. */
   
   struct student *createStudent(char studentName[], int studentAge) {
    struct student *ptr = (struct student *) malloc(sizeof(struct student));
    ptr->age = studentAge;
    copyStr(studentName, ptr->name);
    ptr->next = NULL;
    return ptr;
}

void copyStr(char *a, char *b) {
    int i;
    for (i=0; a[i] != '\0'; i++) {
       b[i] = a[i];
    }
    b[i] = '\0';
}

struct student *append(struct student * end, struct student * newStudptr) {
    end->next = newStudptr;
    return(end->next);
}

void printStudents(struct student *start) {
    struct student *ptr = start;
    while (ptr != '\0') {
        printf("%s is %d years old.\n", ptr->name, ptr->age);
        ptr = ptr->next;
    }
}

void freeStudents(struct student *start) {
    //! heap=showMemory(start=277, cursors=[start,temp])
    struct student *temp = start;
    while (start != '\0') {
        temp = start->next;
        free(start);
        start = temp;
    }
}
