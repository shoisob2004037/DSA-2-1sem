#include <stdio.h>
 int main ()
{

int size[100], c, beg, end, mid, num, s;
printf("Enter number of elements: \n");
scanf ("%d", &num);
printf("Enter %d integer numbers: \n",num);
for(int c=0;c<num; c++)
{
scanf("%d", &size[c]);
}
printf ("Enter a number to search: \n");
scanf ("%d", &s) ;
beg = 0;
end = num - 1;
mid = (beg+end) / 2;
while (beg <= end) {
if (size[mid] < s)
beg = mid + 1;
else if (size[mid] == s) {
printf ("%d found at location %d.\n", s, mid+1);
break;
}
else
end = mid - 1;
mid = (beg + end) /2;
}
if (beg > end)
printf ("%d Not found! \n", s);
return 0;
}
