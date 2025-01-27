#include "mem.h"
#include "proc.h"

int main(int argc, char **argv) {
  // int pid = 8858;
  //
  // void *arrChar = (void *)0x7fff61277540;
  // char charToWrite[] = "hehehehaw";

  // write_mem(pid, arrChar, &charToWrite, sizeof(char) * 9);

  // printf("Overwritten successfully\n");
  // printf("Press Enter to quit.\n");
  // getchar();
  if (argc != 2) {
    printf("Usage: ./hack <process name>");
    return EXIT_FAILURE;
  }

  // Wait for program to start
  pid_t pid = -1;
  while ((pid = get_pid_by_name(argv[1])) == -1) {
    sleep(1);
  }
  printf("PID: %d\n", pid);

  return EXIT_SUCCESS;
}
