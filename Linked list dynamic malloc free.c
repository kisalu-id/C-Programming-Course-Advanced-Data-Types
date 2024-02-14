#include <stdio.h>
#include <stdlib.h> 

struct point{
    int x;
    int y;
    struct point *nxt; //to link the list
};

void printPts(struct point *);
struct point * append (struct point *, struct point *);
struct point * createNewpt(int, int);
void freePt(struct point * start);

int main(void) {
    //! showMemory(start=65520)
    int num, x, y;
    struct point *start, *end, *newpt; //to move through the list; "end" points to current end of the list
    
    printf("How many points you want to store? ");
    scanf("%d", &num);
    for (int i=0; i<num; i++) {
        printf("\nPlease input x and y values: ");
        scanf("%d %d", &x, &y);
        newpt = createNewpt(x, y);
        if (i==0) { //if 1st element in a list
            start = end = newpt; //start = end, bc end is the last element with the address in it's nxt
        } else  { //if we can assign the previous(end) pointer an address of the next element
            end = append (end, newpt);
        }
    }
    /*
    start = end = &ptOne; //beginning
    //linking together to move through the list with a while loop
    //instead of ptOne.nxt = &ptTwo;
    end = append (end, &ptTwo);
    end = append (end, &ptThree);
    */

    printf("\nPrinted values:\n");
    printPts(start); //pass only the beginning
    
    freePt(start);
    return 0;
}

void printPts(struct point *start) { //pass only the start
     //! showMemory(start = 65520, cursors=[pt])
    struct point *pt;
        pt = start;
    //just take the beginning of a list and end at the empty pt.nxt
    while (pt != NULL) {
        printf("x; %d;   y: %d\n\n", pt->x, pt->y);
        pt = pt->nxt;
    }
}

/* "end" here refers to the last element of the array, which, at this given moment,
has a value (pointer) in its .nxt., so here it is: ptOne, ptTwo (not the last one, ptThree).
ptThree doesn't have anything in it's .nxt */
struct point * append (struct point *end, struct point *newpt) {
    end->nxt = newpt; //end and newpt are pointers (addresses)
    return (end->nxt);
}

struct point * createNewpt(int x, int y) {
    struct point *pt;
    pt = (struct point *)malloc(sizeof(struct point)); //reserve space for this point
    pt->x = x;
    pt->y = y;
    //if this is the last component in the list, NULL will remain there as an indicator of the end of the list
    //if it's not the last component, it will be given a value in the next function call append (in the main loop)
    pt->nxt = NULL; 
    return(pt);
}

void freePt(struct point *start) {
    struct point *pt = start; //I can't just free the 1st element in a list
    while (pt != NULL) {
        start = pt; //I need an additional variable pt
        pt = pt->nxt; //adress of the last element will be NULL
        free(start);
    }
}
