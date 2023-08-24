#!/bin/bash

# Compile all .c files in the current directory into a dynamic library
gcc -shared -o liball.so *.c
