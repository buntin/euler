#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>

#include "util.h"

bool VerifyArgULL(const char* nptr, uint64_t* value, uint64_t lower, uint64_t upper) {
    if (nptr[0] == '-') {
        printf("ERROR: Invalid argument \"%s\", cannot be negative\n", nptr);
        return false;
    }
    
    char *endptr = NULL;
    errno = 0;
    uint64_t num = strtoull(nptr, &endptr, 10);
    
    if (nptr == endptr) {
        printf("ERROR: Invalid argument \"%s\", no digits found\n", nptr);
        return false;
    }
    if (errno == ERANGE && num == ULLONG_MAX) {
        printf("ERROR: Invalid argument \"%s\", overflow occurred\n", nptr);
        return false;
    }
    if (errno != 0 && num == 0) {
        printf("ERROR: Invalid argument \"%s\", unspecified error\n", nptr);
        return false;
    }
    if (errno == 0 && nptr && *endptr != 0) {
        printf("ERROR: Invalid argument \"%s\", invalid characters remain\n", nptr);
        return false;
    }
     if (num < lower || num > upper) {
        printf("ERROR: Invalid value \"%llu\", out of range\n", num);
        return false;
    }
    
    *value = num;
    return true;
}