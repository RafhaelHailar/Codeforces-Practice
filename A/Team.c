#include <stdio.h>
#include <stdbool.h>

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

int totalSolutions(int n, int problems[n][3]) {
    int total = 0;
    for (int i = 0;i < n;i++) {
        // since for the friends to write a solution to a problem
        // more than one in the friend group must know the solution.
        int solvable = problems[i][0] + problems[i][1] + problems[i][2];
        if (solvable > 1) total++;
    }

    return total;
}

int main() {
    int test1 = totalSolutions(3, (int[3][3]) {
        {1,1,0},
        {1,1,1},
        {1,0,0}
    });
    int test1CorrectOutput = 2;

    printf("----TEST 1----\n");
    isEqual(&test1, &test1CorrectOutput, 'i');

    int test2 = totalSolutions(2, (int[3][3]) {
        {1,0,0},
        {0,1,1}
    });
    int test2CorrectOutput = 1;


    printf("----TEST 2----\n");
    isEqual(&test2, &test2CorrectOutput, 'i');

    return 0;
}
