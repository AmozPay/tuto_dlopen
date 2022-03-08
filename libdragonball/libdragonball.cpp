#include <unistd.h>
#include <stdlib.h>

__attribute__((__constructor__))  void loader()
{
    write(1, "Loading libdragonball\n", 21);
}

/*  __attribute__ is a like decorator, used by compiler to get usefull information.
**  it takes at least 1 parameter, passed into a double parenthesis /!\
** the constructor and destructor attibutes indicate wich functions to call before dlopen() and dlclose() respectively return.
** It can be useful to initialize and clean data, but in this cas, for demo purposes, it only prints a message.
*/

__attribute__((__destructor__))  void unloader()
{
    write(1, "Unloading libdragonball\n", 23);
}


/* This is a cpp file, and as such, function names can be modified by the compiler because of overloads.
** To prevent this, we can add extern "C" to indicate that this must be compatible with C, so it will not modify the name (and can't be overloaded)
*/

extern "C" char *who_is_the_best_character()
{
    char the_best[] = "yamcha";
    char *ret = (char*) malloc(7);
    for (int i = 0; i < 7; i++)
        ret[i] = the_best[i];
    return ret;
}

// Antoher possible syntax

// extern "C" {
//     char *who_is_the_best_character()
//     {
//         char the_best[] = "yamcha";
//         char *ret = (char*) malloc(7);
//         for (int i = 0; i < 7; i++)
//             ret[i] = the_best[i];
//         return ret;
//     }
// }