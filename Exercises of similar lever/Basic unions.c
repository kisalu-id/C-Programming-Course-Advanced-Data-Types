#include <stdio.h>
union intPieces {
    int num;
    char size[sizeof(int)];
};

int main()
{
    union intPieces pieces;
    pieces.num = 987456321;
    printf("The number is %i\n The bytes are [%i, %i, %i, %i]\n", pieces.num, pieces.size[0], pieces.size[1], pieces.size[2], pieces.size[3]);
    return 0;
}
