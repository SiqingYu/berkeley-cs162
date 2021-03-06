#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcpy_staff(char *dest, const char *src) {
    if (src == NULL) {
        return NULL;
    }
    char *ptr = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    // Note: in my GCC output, the malloc automatically initialize each str1 character as \0
    // therefore adding trailing \0 isn't necessary below
    *dest = '\0';
    return ptr;
}


int main() {
    char *str = "hello world";
    char *str1 = malloc(strlen(str) + 1);
    char *str2 = strcpy_staff(str1, str);
    printf("%s\n",str1);
    printf("%s\n",str2);
    return 0;
}
