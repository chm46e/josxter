#include <include/stdlib.h>
#include <include/stdio.h>

static bool running = true;
static FILE console;

static void console_open(void)
{
    console = open("/dev/console", O_RDWR | O_NDELAY, 0);
}

static char console_read_char(void)
{
    char c = 0;

    while(!read(console, &c, 1)) {
        struct timespec ts;
        ts.tv_sec = 0;
        ts.tv_nsec = 10000;
        __sys_nanosleep(&ts, NULL);
    }

    return c;
}

static void console_write_char(char c)
{
    write(console, &c, 1);
}

static int get_stdin_line(char *input, size_t size)
{
    size_t i = 0;

    for (; i < size; i++) {
        char c = console_read_char();

        if (c == 0) {
            i--;
            continue;
        }

        input[i] = c;

        if (c == '\b') {
            i--;
            input[i] = '\0';
        }
        if (c == '\n') {
            input[i] = '\0';
            return i;
        }
    }

    return i;
}

static void execute()
{
    char *token, *cmd[1024];    

    token = strtok(NULL, " ");
    if (token == NULL)
        return;

    printf("fexec");

    int i = 0;
    strcpy(cmd[i], token);
    while ((token = strtok(NULL, " ")) != NULL) {
        i++;

        strcpy(cmd[i], token);
    }
    cmd[i+1] = "\0";

    exec((const char **)cmd);
}

static void local_exec()
{

}

/*
 * Format of the shell commands:
 * > [handler] [command]
 */

static void parse(char *input)
{
    char *token;

    token = strtok(input, " ");
    if (token == NULL)
        return;

    if (strcmp(token, "x")) {
        execute();
    } else if (strcmp(token, "@")) {
        local_exec();
    }
}

static void loop(void)
{
    char input[1024];

    while (running) {
        printf("> ");
        get_stdin_line(input, 1024);

        parse(input);
    }
}

int main()
{
    console_open();

    loop();

    return 0;
}
