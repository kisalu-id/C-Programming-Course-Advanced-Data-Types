#include <stdio.h>

       //static function limits the scope to this one file, can't access the function from another files
   static int sum (int num) {
       //static var retains its value between function calls
      //static var is allocated once and persists throughout the entire execution of the program
      //general var-s get terminated each time a function is called

       static int sum;
       sum += num;
       return sum;
   }

   int main() {

       printf("%d ",sum(55)); //55
       printf("%d ",sum(45)); //100
       printf("%d ",sum(50)); //150

       return 0;
   }
