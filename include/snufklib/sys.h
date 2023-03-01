#pragma once

#include <syscall.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t sys_read(unsigned int fd, char *buf, size_t count);
ssize_t sys_write(unsigned int fd, const char *buf, size_t count);
int sys_open(const char *filename, int flags, mode_t mode);
int sys_close(unsigned int fd);
int sys_stat(const char *filename, struct stat *statbuf);
int sys_fstat(unsigned int fd, struct stat *statbuf);
int sys_lstat(const char *filename, struct stat *statbuf);
off_t sys_lseek(unsigned int fd, off_t offset, unsigned int whence);
void *sys_mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
int sys_mprotect(unsigned long start, size_t len, unsigned long prot);
int sys_munmap(unsigned long addr, size_t len);
int sys_brk(unsigned long brk);
int sys_ioctl(unsigned int fd, unsigned int cmd, unsigned long arg);
int sys_access(const char *filename, int mode);
int sys_pipe(int *fildes);
void *sys_mremap(unsigned long addr, unsigned long old_len, unsigned long new_len, unsigned long flags, unsigned long new_addr);
int sys_msync(unsigned long start, size_t len, unsigned char *vec);
int sys_nanosleep(const struct timespec *rqtp, struct timespec *rmtp);
pid_t sys_fork(void);
int sys_execve(const char *filename, const char *const *argv, const char *const *envp);
void sys_exit(int error_code);
