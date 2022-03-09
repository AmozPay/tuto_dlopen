#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "interface.hpp"

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
        void *handle = dlopen(libs[lib - 1], RTLD_LAZY); // dlopen(): open a shared library file (libexample.so). RTLD_LAZY: only load a symbol (function) upon call with dlsym()
        if (!handle) { // handle is a pointer to the loaded library. If dlopen fails, handle is NULL.
            char *err = dlerror(); // Get the error message from failed dlopen or dlsym.
            dprintf(2, "%s\n", err);
            return -1;
        }
        char *(*f)() = reinterpret_cast<char *(*)()>(dlsym(handle, "who_is_the_best_character")); // dlsym loads a symbol as a void *, which you can cast.
        void *(*createCharacter)() = reinterpret_cast<void *(*)()>(dlsym(handle, "createCharacter")); // dlsym loads a symbol as a void *, which you can cast.
        printf("\n\nThe best character is %s !!!!\n\n", f());
        IDisplayModule *character = reinterpret_cast<IDisplayModule *>(createCharacter());
        character->display();
        delete character;
        dlclose(handle); // close the library
    }
}
