#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char naruto[] = "./libnaruto/libnaruto.so";
    char dragonball[] = "./libdragonball/libdragonball.so";
    char onepiece[] = "./libonepiece/libonepiece.so";
    char *libs[] = {naruto, dragonball, onepiece};
    int lib;
    while (1) {
        printf("\nEnter a lib number\nlib naruto: 1\nlib dragonball: 2\nlib onepiece: 3\nquit: 0\n\n");
        scanf("%d", &lib);
        if (lib == 0)
            break;
        void *handle = dlopen(libs[lib - 1], RTLD_LAZY); // RTLD_LAZY: only load a symbol (function) upon call with dlsym()
        if (!handle) {
            char *err = dlerror(); // check if there is an error message
            dprintf(2, err);
            return -1;
        }
        char *(*f)() = dlsym(handle, "who_is_the_best_character"); // dlsym loads a symbol as a void *, which you can cast.
        char *s = f();
        printf("\n\nThe best character is %s !!!!\n\n", s);
        free(s);
        dlclose(handle);
    }
}