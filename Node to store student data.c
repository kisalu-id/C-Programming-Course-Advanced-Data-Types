/*
You would like to store student data (for each student, their name and age) in a linked list of students. You are given the following structure to store each student's information. Please do not modify this structure

Your first task is to write a function createStudent() that takes as inputs a string (namely a student's name) and an integer (their age) and that returns a pointer to a struct student which stores this information. Your function should dynamically allocate the memory required for this struct student and then write the student's name and age into this newly allocated memory. 

Examples
Input:
Petra 25

Output:
New student created: Petra is 25 years old.   

Input:
Remi 18
Output:
New student created: Remi is 18 years old.   

Warning: You will be graded on your output, so do not include any print statements that prompt a user for input.*/

#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
void copyStr(char studentName[50], struct student *ptr);

int main(void) {
    struct student *studptr;
    int myAge;
    char myName[50];
    scanf("%s %d", myName, &myAge);
    studptr = createStudent(myName, myAge);
    printf("New student created: %s is %d years old.\n", studptr->name, studptr->age);
    free(studptr);
    return 0;
}


struct student *createStudent(char studentName[], int studentAge) {
    struct student *ptr;
    ptr = (struct student *) malloc(sizeof(struct student));
    ptr->age = studentAge;
    copyStr(&studentName[50], ptr);
    //ptr->name = studentName[50];
    ptr->next = NULL;
    return ptr;
}

//
void copyStr(char studentName[50], struct student *ptr) {
    for (int i=0; i<50; i++) {
       ptr->name[i] = studentName[i];
    }
}
