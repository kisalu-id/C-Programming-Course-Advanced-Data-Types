#include <stdio.h>
#include <stdlib.h>

int main() {
    float *ptr_malloc= (float *)malloc(sizeof(float));
    if (ptr_malloc == NULL) {
        fprintf(stderr, "Memory allocation using malloc failed\n");
        return 0;
    }

    int *ptr_calloc= (int *)calloc(5, sizeof(int));
    if (ptr_calloc == NULL) {
        fprintf(stderr, "Memory allocation using calloc failed\n");
        return 0;
    }
  
    int *ptr_realloc = (int *)realloc(ptr_malloc, 10 * sizeof(int));
    if (ptr_realloc == NULL) {
        fprintf(stderr, "Memory reallocation using realloc failed\n");
        return 0; 
    }

    printf("Values allocated with calloc:\n");
    for (size_t i = 0; i < 5; ++i) {
        printf("%d ",  ptr_calloc[i]);
    }
    printf("\n");

    free(ptr_realloc); //freeing memory in case of success or failure (within if function)
    free(ptr_calloc);

    return 0;
}

/*
size_t specifies the size of memory blocks/arrays when using memory allocating functions;
it's specifically designed to hold sizes of objects in memory, it's the appropriate data type to use whenever I need to specify the size of memory to be allocated or manipulated;
it ensures consistency and compatibility across different platforms and compilers, making rhe code more robust and portable
*/
