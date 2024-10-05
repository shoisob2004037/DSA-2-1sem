#include<stdio.h>
int main()
{
    int s[100], position, c, n;
    printf("Enter number of elements in array : ");
    scanf("%d", &n);
    printf("Enter %d elements : ", n);
    for ( c = 0 ; c < n ; c++ )
    scanf("%d", &s[c]);
    printf("Enter the position where you want to delete element : ");
    scanf("%d", &position);
    if ( position >= n+1 )
    printf("Deletion not possible! \n");
    else
    {
        for ( c = position - 1 ; c < n - 1 ; c++ )
        s[c] = s[c+1];
        printf("After deletion the array is : \n");
        for( c = 0 ; c < n - 1 ; c++ )
        printf("%d\n", s[c]);
    }
    return 0;
}
