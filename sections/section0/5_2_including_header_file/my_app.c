#include <stdio.h>
#include "my_lib.h"

int main(int argc, char **argv)
{
	// correct calling
	// char *result = my_helper_function(argv[0]);

	// calling with the wrong function declaration
	char *result = my_helper_function();

	printf("%s\n", result);
	return 0;
}
