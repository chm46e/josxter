#pragma once

/* mostly "reverse engineered" with this command */
/* echo '#include <libraryname.h>' | gcc -xc -E - */

typedef long unsigned int size_t;
typedef long signed int ssize_t;
typedef int wchar_t;

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int int16_t;
typedef unsigned short int uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef signed long int int64_t;
typedef unsigned long int uint64_t;

typedef long int time_t;
typedef int pid_t;

struct timespec
{
    time_t tv_sec; 
    time_t tv_nsec;
};

typedef long int off_t;
typedef unsigned int mode_t;

struct stat
{
    unsigned long int st_dev;
    unsigned long int st_ino;

    unsigned long int st_nlink;
    mode_t st_mode;

    unsigned int st_uid;
    unsigned int st_gid;
    int __pad0;

    unsigned long int st_rdev;
    off_t st_size;
    long int st_blksize;
    long int st_blocks;

    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;

};

typedef unsigned int bool;