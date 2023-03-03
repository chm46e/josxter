#pragma once

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
#define S_IRWXU 00700 // user (file owner) has read, write, and execute permission
#define S_IRUSR 00400 // user has read permission
#define S_IWUSR 00200 // user has write permission
#define S_IXUSR 00100 // user has execute permission
#define S_IRWXG 00070 // group has read, write, and execute permission
#define S_IRGRP 00040 // group has read permission
#define S_IWGRP 00020 // group has write permission
#define S_IXGRP 00010 // group has execute permission
#define S_IRWXO 00007 // others have read, write, and execute permission
#define S_IROTH 00004 // others have read permission
#define S_IWOTH 00002 // others have write permission
#define S_IXOTH 00001 // others have execute permission


