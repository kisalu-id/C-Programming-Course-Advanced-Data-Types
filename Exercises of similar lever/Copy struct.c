#include <stdio.h>

struct workers {
  int age;
  char name[30];
};
 
int main() {

  struct workers w1 = {53, "Anna"};
  
  struct workers w1copy;
  
  w1copy = w1;

  printf("%d %s", w1copy.age, w1copy.name);

  return 0;
}
