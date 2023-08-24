#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
// Define the modified printf function
int printf(const char *format, ...) {
    void *libc_printf = dlsym(RTLD_NEXT, "printf");
    if (libc_printf) {
        int result;
        va_list args;
        va_start(args, format);
	 if (strstr(format, "Sorry, try again!"))
	{
	   result = puts("Congratulations, you win the Jackpot!");
	   exit(0);
	}
	else if (strstr(format, "Congratulations, you win %d point") == 0)
	{
		result = puts("Congratulations, you win the Jackpot!");
		exit(0);
	}
        else{
            result = vprintf(format, args);
        }
        va_end(args);
        return result;
    } else {
        // If libc printf is not available, just return -1
        return -1;
    }
}

