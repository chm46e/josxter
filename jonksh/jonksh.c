#include <include/stdlib.h>
#include <include/stdio.h>

static bool running = true;

static void loop(void)
{
    char *input;

    input = calloc(sizeof(char), 256);

    while (running) {
        //printf("> ");
        //get_stdin(input, 256);

        //execute(input);
        //printf("\n");
    }

    free(input);
}

int main()
{
    loop();

    return 0;
}
