#include <stdio.h>

// omitting this my_helper_function declaration results in segment fault error
// char *my_helper_function(char *string);

int main(int argc, char **argv)
{
	char *result = my_helper_function(argv[0]);
	printf("%s\n", result);
	return 0;
}
