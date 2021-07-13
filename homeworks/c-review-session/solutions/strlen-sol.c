#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int strlen_staff(const char *src) {
    long int count = 0;
    // My mistake was comparing: src == NULL, which is false all the time
    // the right way to determine the string null terminator is below
    while(*src != '\0') {
        count++;
        src += 1;
    }
    return count;
}


int main() {
    char *str = "hello world";
    printf("The length of string '%s' is: %ld\n", str, strlen(str));
    return 0;
}
