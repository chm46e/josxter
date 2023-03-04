#pragma once

#include <include/stdtype.h>

#define SIGABRT 6

extern void exit(int status);
extern int kill(pid_t pid, int sig);
extern pid_t getpid(void);
extern void abort(void);
