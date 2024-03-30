#include <stdio.h>
#include <string.h>

int calculateLength(char[]);

typedef struct {
    char let;
    int val;
} LetValPair;

LetValPair pairs[] = {
    {'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1}, {'F', 4}, {'G', 2}, {'H', 4}, {'I', 1}, {'J', 8}, {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1}, {'O', 1}, {'P', 3}, {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 4}, {'W', 4}, {'X', 8},  {'Y', 4}, {'Z', 10}
};


int main(){
  char p1Word[101], p2Word[101];
  int p1Score, p2Score;
  printf("Player 1, enter your word:\n");
  scanf("%s", p1Word);
  printf("Player 2, enter your word:\n");
  scanf("%s", p2Word);
  
  p1Score = calculateLength(p1Word);
  p2Score = calculateLength(p2Word);
  
  printf("Score of player 1: %d\n", p1Score);
  printf("Score of player 2: %d\n", p2Score);
  
  return 0;
}
  
  
int calculateLength (char word[])  {
  int counter = 0;
  int wLength = strlen(word);
  
  for (int j= 0; j< wLength; j++) {
    for (int i=0;i<26; i++) {
      if (pairs[i].let == word[j]) {
        counter += pairs[i].val;
        break; //value found
      }
    } 
  }
  return counter; 
 }
