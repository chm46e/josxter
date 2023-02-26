#include <syscall.h>
#include <fcntl.h>

unsigned long _syscall(int num, void *a0, void *a1, void *a2, void *a3, void *a4, void *a5);

unsigned long _strlen(char *sz) {
    int count = 0;

    while(*sz++) {
        count++;
    }

    return count;
}

void print_string(char *str) {
    _syscall(SYS_write, (void *)1 /*stdout*/, str, (void *)_strlen(str), 0, 0, 0);
}


int main() {
    print_string((char *)"++++++++++++++++++++++++++#########@@@@@@@@@@It works!!");

    while (1) {

    }
    return 0;
}
