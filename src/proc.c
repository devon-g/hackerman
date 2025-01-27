#include "proc.h"

/* Get PID from process name
 * @param char *name The name of the process
 */
pid_t get_pid_by_name(char *name) {
  pid_t pid = 0;

  // open directory stream at /proc/
  DIR *proc_dir = opendir("/proc/");
  if (!proc_dir) {
    perror("Could not open /proc/: ");
    exit(EXIT_FAILURE);
  }

  // Step through process folders looking for name
  struct dirent *proc = {0};
  while ((proc = readdir(proc_dir))) {
    char sym_path[512] = "";
    char exe_path[512] = "";

    // Get this /proc/{pid}/
    pid = strtol(proc->d_name, NULL, 10);

    // Construct file path (/proc/{pid}/exe)
    snprintf(sym_path, sizeof(sym_path), "/proc/%i/exe", pid);

    // Follow exe symlink to see name of executable
    ssize_t result = readlink(sym_path, exe_path, sizeof(exe_path));
    if (result >= 0) {
      // Extract exe name from path
      char *exe_name = basename(exe_path);
      // If exe name matches provided name we've found the pid!
      if (!strcmp(name, exe_name)) {
	closedir(proc_dir);
	return pid;
      }
    }
  }

  closedir(proc_dir);
  return -1;
}
