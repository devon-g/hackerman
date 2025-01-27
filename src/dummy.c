#include <stdio.h>
#include <unistd.h>

int main() {
  int varInt = 123456;
  char arrChar[128] = "Long char array right there ->";
  int* ptr2int = &varInt;
  int** ptr2ptr = &ptr2int;
  int*** ptr2ptr2 = &ptr2ptr;

  while (1) {
    printf("Process ID: %d\n\n", getpid());
    printf("varInt (%p) = %d\n", &varInt, varInt);
    printf("arrChar (%p) = %s\n", arrChar, arrChar);
    printf("ptr2int (%p) = %p\n", &ptr2int, ptr2int);
    printf("ptr2ptr (%p) = %p\n", &ptr2ptr, ptr2ptr);
    printf("ptr2ptr2 (%p) = %p\n\n", &ptr2ptr2, ptr2ptr2);

    printf("Press ENTER to print again.\n");
    getchar();

    printf("----------------------------------------\n\n");
  }

  return 0;
}
