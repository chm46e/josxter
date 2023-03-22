#pragma once

#include <include/snufklib/sys.h>
#include <include/stdtype.h>

#define SIGABRT 6

#define fork __sys_fork
#define execve __sys_execve

extern void exit(int status);
extern void exit_with_msg(int status, const char *msg);
extern int kill(pid_t pid, int sig);
extern pid_t getpid(void);
extern void abort(void);
extern void abort_with_msg(const char *msg);
extern int exec(const char **argv);
