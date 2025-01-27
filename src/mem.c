#define _GNU_SOURCE

#include "mem.h"

/* Read memory from external process using `process_vm_readv`
 * @param pid_t   pid     The target process id
 * @param void *  address The address to read from in target process
 * @param void *  buffer  The buffer to store read data into
 * @param ssize_t nbytes  The number of bytes to read
 * @see process_vm_readv()
 */
void read_mem(pid_t pid, void *address, void *buffer, size_t nbytes) {
  struct iovec local[1];
  struct iovec remote[1];

  local[0].iov_base = buffer;
  local[0].iov_len = nbytes;

  remote[0].iov_base = address;
  remote[0].iov_len = nbytes;

  ssize_t nread = process_vm_readv(pid, local, 1, remote, 1, 0);
  if (nread != nbytes) {
    perror("[read_mem] Failed to read bytes: ");
    exit(EXIT_FAILURE);
  }
}

/* Write memory to external process using `process_vm_writev`
 * @param pid_t   pid     The target process id
 * @param void *  address The address to write to in target process
 * @param void *  buffer  The buffer to write out
 * @param ssize_t nbytes  The number of bytes to write
 * @see process_vm_writev()
 */
void write_mem(pid_t pid, void *address, void *buffer, size_t nbytes) {
  struct iovec local[1];
  struct iovec remote[1];

  local[0].iov_base = buffer;
  local[0].iov_len = nbytes;

  remote[0].iov_base = address;
  remote[0].iov_len = nbytes;

  ssize_t nwrote = process_vm_writev(pid, local, 1, remote, 1, 0);
  if (nwrote != nbytes) {
    perror("[write_mem] Failed to write bytes: ");
    exit(EXIT_FAILURE);
  }
}
