#include <stdio.h>
void trArr(int* arr, int n)
{
	int i;

	printf("Transversed Array is: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {10,-2,30,-5,-3,0,100};
	int n = sizeof(arr) / sizeof(arr[0]);

	trArr(arr, n);

	return 0;
}

