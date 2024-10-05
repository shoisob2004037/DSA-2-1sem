#include<stdio.h>
int main()
{
    int top=6,maxstk,stack[10],item,i;
    printf("Enter max stack: ");
    scanf("%d",&maxstk);

    printf("Enter integers of stack: ");
       for(i=1;i<=top;i++)
    {
        scanf("%d",&stack[i]);
    }
    printf("Enter insert item: ");
    scanf("%d",&item);
    if(top==maxstk)
    {
        printf("Overflow");
    }
    else
    {
        top=top+1;
        stack[top]=item;
        printf("Stack: ");
        for(i=1;i<=top;i++)
    {

        printf("%d\t",stack[i]);
    }
    }
    return 0;
}
