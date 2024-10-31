#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* genderCheck(char username[]) {
   // Boolean array for letter 'a' - 'z'.
   bool seen[26] = { false };  
   int uniqueCount = 0;

   // we will check if a letter is already seen or not and count,
   // how many unique letter we have seen.
   for (int i = 0;username[i] != '\0';i++) {
      // get index from ASCII number representation.
      int index = username[i] - 'a';
      if (!seen[index]) {
          seen[index] = true;
          uniqueCount++;
      }
   }

   return uniqueCount % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!";
}

void isEqual(void* result, void* expected, char type) {
   bool testSuccess = false;
   switch (type) {
      case 's': {
          char* resultStr = (char*) result;
          char* expectedStr = (char*) expected;

          if (resultStr == NULL || expectedStr == NULL) {
              printf("FAILED! (NULL input)\n\n");
              return;
          }

          unsigned long resultLen = strlen(resultStr);
          bool isSimilar = true;

          if (resultLen == strlen(expectedStr)) {
              for (int i = 0;i < resultLen;i++) { 
                  if (resultStr[i] != expectedStr[i]) {
                      isSimilar = false;
                      break;
                  }
              }
          } else {
             isSimilar = false;
          }

          testSuccess = isSimilar;
      } break;

   }

   if (testSuccess) {
      printf("SUCCESS!\n\n");
   } else {
      printf("FAILED!\n\n");
   }
}

int main() {
    char* test1 = genderCheck("wjmzbmr");
    char test1CorrectOutput[] = "CHAT WITH HER!";

    printf("----TEST 1----\n");
    printf("%s\n",test1);
    isEqual(test1, test1CorrectOutput, 's');

    char*  test2 = genderCheck("xiaodao");
    char test2CorrectOutput[] = "IGNORE HIM!";

    printf("----TEST 2----\n");
    printf("%s\n",test2);
    isEqual(test2, test2CorrectOutput, 's');

    char*  test3 = genderCheck("sevenkplus");
    char test3CorrectOutput[] = "CHAT WITH HER!";

    printf("----TEST 3----\n");
    printf("%s\n",test3);
    isEqual(test3, test3CorrectOutput, 's');

    char*  test4 = genderCheck("ursweetkitty");
    char test4CorrectOutput[] = "IGNORE HIM!";

    printf("----TEST 4----\n");
    printf("%s\n",test4);
    isEqual(test4, test4CorrectOutput, 's');
    return 0;
}
