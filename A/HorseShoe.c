#include <stdio.h>
#include <stdbool.h>

int totalHorseShoeToBuy(int n,int shoes[n]) {
   // we remove identical colors and only store unique one. 
   int uniqueColors[4] = {0};
   int uniqueCount = 0;
   
   for (int i = 0;i < n;i++) {
       int currColor = shoes[i];

       int found = 0;
       for (int j = 0;j < uniqueCount;j++) {
           if (currColor == shoes[j]) {
               found = 1;
               break;
           }
       }
       if (!found) {
          uniqueColors[uniqueCount++] = currColor;
       }
   }
   
   // we subtract how many unique color we have to the total
   // of shoes to get how many shoe we have to buy.
   return n - uniqueCount;
}

void isEqual(void* result, void* expected, char type) {
   bool testSuccess = false;
   switch (type) {
      case 'i':
         if (*(int*) result == *(int*) expected) {
             testSuccess = true;
         }
         break;
   }

   if (testSuccess) {
      printf("SUCCESS!\n\n");
   } else {
      printf("FAILED!\n\n");
   }
}

int main() {
    int test1 = totalHorseShoeToBuy(4, (int[4]) {1, 7, 3, 3});
    int test1CorrectOutput = 1;

    printf("----TEST 1----\n");
    isEqual(&test1, &test1CorrectOutput, 'i');

    int test2 = totalHorseShoeToBuy(4, (int[4]) {7, 7, 7, 7});
    int test2CorrectOutput = 3;


    printf("----TEST 2----\n");
    isEqual(&test2, &test2CorrectOutput, 'i');

    return 0;
}

