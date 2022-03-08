#include <unistd.h>
#include <stdlib.h>

__attribute__((__constructor__))  void loader()
{
    write(1, "Loading libdragonball\n", 21);
}

__attribute__((__destructor__))  void unloader()
{
    write(1, "Unloading libdragonball\n", 23);
}


char *who_is_the_best_character()
{
    char the_best[] = "yamcha";
    char *ret = malloc(7);
    for (int i = 0; i < 7; i++)
        ret[i] = the_best[i];
    return ret;
}