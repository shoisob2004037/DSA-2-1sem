#include<stdio.h>

int main()
{
	int arr[100];
	int i, x, pos, n=10;
    for (i = 0; i<10; i++)
    arr[i] = i + 1;
    for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
	printf("\n");
	printf("Enter the position where to insert number : ");
	scanf("%d",&pos);
    printf("Enter the number which want to insert : ");
	scanf("%d",&x);
    n++;
	for (i = n - 1; i >= pos; i--)
    arr[i] = arr[i - 1];
    arr[pos - 1] = x;
    for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
	printf("\n");
    return 0;
}
