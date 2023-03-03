/*
 * Simpler bindings to linux kernel syscalls
 * (only included more useful ones)
 * docs: https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md
 */

#include "sys.h"

#include <syscall.h>

#include <include/stdtype.h>


unsigned long __syscall(int num, void *a0, void *a1, void *a2, void *a3, void *a4, void *a5);

/* read from a file descriptor */
ssize_t __sys_read(unsigned int fd, char *buf, size_t count)
{
    return __syscall(SYS_read, (void *)(long)fd, (void *)buf, (void *)(long)count, 0, 0, 0);
}

/* write to a file descriptor */
ssize_t __sys_write(unsigned int fd, const char *buf, size_t count)
{
    return __syscall(SYS_write, (void *)(long)fd, (void *)buf, (void *)count, 0, 0, 0);
}

/* open and possibly create a file */
int __sys_open(const char *filename, int flags, mode_t mode)
{
    return __syscall(SYS_open, (void *)filename, (void *)(long)flags, (void *)(long)mode, 0, 0, 0);
}

/* close a file descriptor */
int __sys_close(unsigned int fd)
{
    return __syscall(SYS_close, (void *)(long)fd, 0, 0, 0, 0, 0);
}

/* get file status from filename */
int __sys_stat(const char *filename, struct stat *statbuf)
{
    return __syscall(SYS_stat, (void *)filename, (void *)statbuf, 0, 0, 0, 0);
}

/* get file status from file descriptor */
int __sys_fstat(unsigned int fd, struct stat *statbuf)
{
    return __syscall(SYS_fstat, (void *)(long)fd, (void *)statbuf, 0, 0, 0, 0);
}

/* get file status from filename (identical, except gets link status) */
int __sys_lstat(const char *filename, struct stat *statbuf)
{
    return __syscall(SYS_lstat, (void *)filename, (void *)statbuf, 0, 0, 0, 0);
}

/* reposition read/write file offset */
off_t __sys_lseek(unsigned int fd, off_t offset, unsigned int whence)
{
    return __syscall(SYS_poll, (void *)(long)fd, (void *)(long)offset, (void *)(long)whence, 0, 0, 0);
}

/* map files or devices into memory */
void *__sys_mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    return (void *)__syscall(SYS_mmap, (void *)addr, (void *)length, (void *)(long)prot, (void *)(long)flags, (void *)(long)fd, (void *)(long)offset);
}

/* set protection on a region of memory */
int __sys_mprotect(unsigned long start, size_t len, unsigned long prot)
{
    return __syscall(SYS_mprotect, (void *)start, (void *)len, (void *)prot, 0, 0, 0);
}

/* unmap files or devices into memory */
int __sys_munmap(void *addr, size_t len)
{
    return __syscall(SYS_munmap, addr, (void *)len, 0, 0, 0, 0);
}

/* change data segment size */
int __sys_brk(unsigned long brk)
{
    return __syscall(SYS_brk, (void *)brk, 0, 0, 0, 0, 0);
}

/* control device */
int __sys_ioctl(unsigned int fd, unsigned int cmd, unsigned long arg)
{
    return __syscall(SYS_ioctl, (void *)(long)fd, (void *)(long)cmd, (void *)arg, 0, 0, 0);
}

/* check user's permissions for a file */
int __sys_access(const char *filename, int mode)
{
    return __syscall(SYS_access, (void *)filename, (void *)(long)mode, 0, 0, 0, 0);
}

/* create pipe */
int __sys_pipe(int *fildes)
{
    return __syscall(SYS_pipe, (void *)fildes, 0, 0, 0, 0, 0);
}

/* remap a virtual memory address */
void *__sys_mremap(unsigned long addr, unsigned long old_len, unsigned long new_len, unsigned long flags, unsigned long new_addr)
{
    return (void *)__syscall(SYS_mremap, (void *)addr, (void *)old_len, (void *)new_len, (void *)flags, (void *)new_addr, 0);
}

/* synchronize a file with a memory map */
int __sys_msync(unsigned long start, size_t len, unsigned char *vec)
{
    return __syscall(SYS_msync, (void *)start, (void *)len, (void *)vec, 0, 0, 0);
}

/* high-resolution sleep */
int __sys_nanosleep(const struct timespec *rqtp, struct timespec *rmtp)
{
    return __syscall(SYS_nanosleep, (void *)rqtp, (void *)rmtp, 0, 0, 0, 0);
}

/* create a child process */
int __sys_fork(void)
{
    return __syscall(SYS_fork, 0, 0, 0, 0, 0, 0);
}

/* execute program */
int __sys_execve(const char *filename, const char *const *argv, const char *const *envp)
{
    return __syscall(SYS_execve, (void *)filename, (void *)argv, (void *)envp, 0, 0, 0);
}

/* terminate the calling process */
void __sys_exit(int error_code)
{
    __syscall(SYS_exit, (void *)(long)error_code, 0, 0, 0, 0, 0);
}


