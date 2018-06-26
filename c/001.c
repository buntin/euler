#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "util.h"

int main(int argc, const char* argv[]) {
    uint64_t max = 0;
    
    if (argc != 2) {
        printf("ERROR: Invalid number of arguments");
        exit(1);
    }
    if (!VerifyArgULL(argv[1], &max, 0, ULLONG_MAX)) {
        exit(1);
    }
    
    uint64_t sum = 0;
    for (uint64_t i = 0; i < max; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }    
    printf("%llu", sum);
    
    exit(0);
}