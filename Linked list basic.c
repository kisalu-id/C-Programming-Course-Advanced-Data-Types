//linked list - a list of structures in random place in memory. Each element of the list knows the address of the next element in the list, you can print them one by one

#include <stdio.h>

struct point{
    int x;
    int y;
    struct point *nxt; //to link the list
};

void printPoints(struct point *);

int main(void) {
    struct point ptOne = {5, 6, NULL};
    struct point ptTwo = {7, 8, NULL};
    struct point ptThree = {9, 10, NULL};
    struct point *start, *pt; //to move through the list
    
    start = &ptOne; //beginning
    ptOne.nxt = &ptTwo; //linking together
    ptTwo.nxt = &ptThree; //to move through the list with a while loop
    
    printPoints(start); //pass only the beginning
    return 0;
}
void printPoints(struct point *start) {
    struct point *pt;
        pt = start;
//just take the beginning of list and end at the empty pt.nxt (end)
    while (pt != NULL) {
        printf("x; %d;   y: %d\n\n", pt->x, pt->y);
        pt = pt->nxt;
    }
}
