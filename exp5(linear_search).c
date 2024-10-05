#include<stdio.h>
int main ()
{

int size[100], s, a, num;
printf ("Enter number of elements: ");
scanf("%d",&num);
printf ("Enter %d integer numbers: \n", num);
for (a=0; a<num; a++)
{

scanf("%d",&size[a]);
}
printf ("Enter a number to search: \n");
scanf ("%d",&s) ;
for (a = 0; a<num; a++)
if (size[a] == s)
{

printf("%d is found at location %d.\n",s, a+1);
break;
}

if (a == num)
printf("%d isn't found in the array.\n", s);
return 0;
}
