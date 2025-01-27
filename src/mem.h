#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>


void read_mem(pid_t pid, void *address, void *buffer, size_t nbytes);
void write_mem(pid_t pid, void *address, void *buffer, size_t nbytes);
