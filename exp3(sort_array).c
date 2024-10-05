#include <stdio.h>
void main (){
   int num[20];
   int i, j, a, n;
   printf("Enter number of elements of array :  ");
   scanf("%d", &n);
   printf("Enter the Elements : ");
   for (i = 0; i < n; ++i)
      scanf("%d", &num[i]);
   for (i = 0; i < n; ++i){
      for (j = i + 1; j < n; ++j){
         if (num[i] > num[j]){
            a = num[i];
            num[i] = num[j];
            num[j] = a;
         }
      }
   }
   printf("The numbers after sorting (Ascending order) is : \n ");
   for (i = 0; i < n; ++i){
      printf("%d ", num[i]);
   }
}
