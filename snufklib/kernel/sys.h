#pragma once

#include <syscall.h>
#include <include/stdtype.h>

ssize_t __sys_read(unsigned int fd, char *buf, size_t count);
ssize_t __sys_write(unsigned int fd, const char *buf, size_t count);
int __sys_open(const char *filename, int flags, mode_t mode);
int __sys_close(unsigned int fd);
int __sys_stat(const char *filename, struct stat *statbuf);
int __sys_fstat(unsigned int fd, struct stat *statbuf);
int __sys_lstat(const char *filename, struct stat *statbuf);
off_t __sys_lseek(unsigned int fd, off_t offset, unsigned int whence);
void *__sys_mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
int __sys_mprotect(unsigned long start, size_t len, unsigned long prot);
int __sys_munmap(void *addr, size_t len);
int __sys_brk(unsigned long brk);
int __sys_ioctl(unsigned int fd, unsigned int cmd, unsigned long arg);
int __sys_access(const char *filename, int mode);
int __sys_pipe(int *fildes);
void *__sys_mremap(unsigned long addr, unsigned long old_len, unsigned long new_len, unsigned long flags, unsigned long new_addr);
int __sys_msync(unsigned long start, size_t len, unsigned char *vec);
int __sys_nanosleep(const struct timespec *rqtp, struct timespec *rmtp);
int __sys_fork(void);
int __sys_execve(const char *filename, const char *const *argv, const char *const *envp);
void __sys_exit(int error_code);
int __sys_kill(pid_t pid, int sig);
pid_t __sys_getpid(void);
