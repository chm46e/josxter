#pragma once

#include <include/snufklib/sys.h>
#include <include/stdtype.h>

typedef unsigned int FILE;

#define open __sys_open
#define read __sys_read
#define write __sys_write
#define close __sys_close

/* access modes */
#define O_RDONLY 0
#define O_WRONLY 1
/* O_RDWR is not the same as O_RDONLY | O_WRONLY */
#define O_RDWR 2 

/* additional flags */
#define O_CREAT 64
#define O_TRUNC 512
#define O_APPEND 1024
#define O_NDELAY 2048

/* modes for O_CREAT */
#define S_IRWXU 700 // user (file owner) has read, write, and execute permission
#define S_IRUSR 400 // user has read permission
#define S_IWUSR 200 // user has write permission
#define S_IXUSR 100 // user has execute permission
#define S_IRWXG 70 // group has read, write, and execute permission
#define S_IRGRP 40 // group has read permission
#define S_IWGRP 20 // group has write permission
#define S_IXGRP 10 // group has execute permission
#define S_IRWXO 7 // others have read, write, and execute permission
#define S_IROTH 4 // others have read permission
#define S_IWOTH 2 // others have write permission
#define S_IXOTH 1 // others have execute permission


