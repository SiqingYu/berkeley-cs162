#include <stdio.h>
#include <string.h>

void swap(char *arr, int first, int second)
{
	char temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

int partition(char *arr, int left_bound, int right_bound)
{
	int pivot = arr[left_bound];
	// Initialize to starting bounds we won 't use
	int left_loc = left_bound;
	int right_loc = right_bound + 1;

	while (left_loc < right_loc)
	{
		// Make forward progress on every iteration
		// so use do while loops
		do
		{
			left_loc++;
			// Find the leftmost elem greater than the pivot
		} while (left_loc <= right_bound && arr[left_loc] <= pivot);

		// Make forward progress on every iteration
		// so use do while loops
		do
		{
			right_loc--;
			// Find the rightmost elem less than the pivot
		} while (right_loc > left_loc && arr[right_loc] > pivot);
		// If there are elements to switch swap them
		if (left_loc < right_loc)
		{
			swap(arr, left_loc, right_loc);
		}
	}
	swap(arr, left_bound, right_loc);
	return right_loc;
}

void sort(char *arr, int left_bound, int right_bound)
{
	if (left_bound < right_bound)
	{
		// divide and conquer
		int split_point = partition(arr, left_bound, right_bound);
		sort(arr, left_bound, split_point - 1);
		sort(arr, split_point + 1, right_bound);
	}
}

void main(int argc, char **argv)
{
	const char *no_args = " Asuna is the best char !";
	char *arr = NULL;
	if (argc > 1)
	{
		arr = malloc(strlen(argv[1]) * sizeof(char));
		strcpy(arr, argv[1]);
	}
	else
	{
		arr = malloc(strlen(no_args) * sizeof(char));
		strcpy(arr, no_args);
	}
	printf(" Unsorted : \"%s \"\n", arr);
	sort(arr, 0, strlen(arr) - 1);
	printf(" Sorted : \"%s \"\n", arr);
	// Really not necessary because this is main but
	// might as well free all your mallocs
	free(arr);
}
