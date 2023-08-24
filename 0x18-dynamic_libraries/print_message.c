#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <stdarg.h>
// Define the modified printf function
int printf(const char *format, ...) {
    void *libc_printf = dlsym(RTLD_NEXT, "printf");
    if (libc_printf) {
        int result;
        va_list args;
        va_start(args, format);
        if (strstr(format, "Please make me win!") != NULL) {
            result = printf("You win!\n");
        } else {
            result = vprintf(format, args);
        }
        va_end(args);
        return result;
    } else {
        // If libc printf is not available, just return -1
        return -1;
    }
}

