#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>


void read_mem(int pid, void *address, void *buffer, ssize_t nbytes);
void write_mem(int pid, void *address, void *buffer, ssize_t nbytes);
