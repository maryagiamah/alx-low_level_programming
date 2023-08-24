// cops.c
#include "cops.h"

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        // Handle division by zero error
        return 0; // You can customize the error handling as needed
    }
}

int mod(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        // Handle modulo by zero error
        return 0; // You can customize the error handling as needed
    }
}

