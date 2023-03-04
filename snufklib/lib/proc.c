#include "proc.h"

#include <include/snufklib/sys.h>
#include <include/stdtype.h>

extern void exit(int status)
{
    __sys_exit(status);
}

extern int kill(pid_t pid, int sig)
{
    return __sys_kill(pid, sig);
}

extern pid_t getpid(void)
{
    return __sys_getpid();
}

extern void abort(void)
{
    int rc;

    rc = kill(getpid(), SIGABRT);
    if (rc < 0)
        exit(-1);
}
