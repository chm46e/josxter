#include "proc.h"

#include <include/snufklib/sys.h>
#include <include/stdtype.h>
#include <include/stddef.h>
#include <include/stdio.h>

extern void exit(int status)
{
    __sys_exit(status);
}

extern void exit_with_msg(int status, const char *msg)
{
    printf(msg);
    exit(status);
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

extern void abort_with_msg(const char *msg)
{
    printf(msg);
    abort();
}

extern int exec(const char **argv)
{
    char *envp[1];

    printf(argv[0]);
    printf(" exec;\n");

    if (!(fork())) {
        envp[0] = NULL;
        return execve((char **)argv[0], (char **)argv, envp);
    }

    return 0;
}
