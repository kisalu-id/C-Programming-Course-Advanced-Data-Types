#include <stdio.h>

struct point{
    int x;
    int y;
    struct point *nxt; //to link the list
};

void printPoints(struct point *);
struct point * append (struct point *, struct point *);

int main(void) {
    //! showMemory(start=65520)
    struct point ptOne = {5, 6, NULL};
    struct point ptTwo = {7, 8, NULL};
    struct point ptThree = {9, 10, NULL};
    int num, x, y;
    struct point *start, *end, *newpt; //to move through the list
    //"end" points to current end of the list
    
    printf("How many points you want to store?");
    scanf("%d", num);
    for (int i=0; i<num; i++) {
        printf("\nPlease input x and y values: ");
        scanf("%d %d", &x, &y);
        
        
        
    }
    /*
    start = end = &ptOne; //beginning
    //linking together to move through the list with a while loop
    //instead of ptOne.nxt = &ptTwo;
    end = append (end, &ptTwo);
    end = append (end, &ptThree);
    */

    printf("\nPrinted values:\n");
    printPoints(start); //pass only the beginning
    //free
    return 0;
}
void printPoints(struct point *start) { //pass only the start
     //! showMemory(start = 65520, cursors=[pt])
    struct point *pt;
        pt = start;
//just take the beginning of list and end at the empty pt.nxt (end)
    while (pt != NULL) {
        printf("x; %d;   y: %d\n\n", pt->x, pt->y);
        pt = pt->nxt;
    }
}

/* "end" here is the last element of the array, that at this given moment 
got a value (pointer) it's .nxt, so here it is: ptOne, ptTwo.
ptThree doesn't have anything at it's .nxt */
struct point * append (struct point *end, struct point *newpt) {
    end->nxt = newpt; //end and newpt are pointers (addresses)
    return (end->nxt);
}
