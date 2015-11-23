#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
char postfix[20],symb;
int s[20],top=-1;
int op1,op2,res;
void push(int c)
{
top++;
s[top]=c;
}
int pop()
{
int c;
c=s[top];
top--;
return c;
}
void main()
{
int i;
clrscr();
printf("enter the postfix expression\n");
scanf("%s",postfix);
for(i=0;postfix[i]!='\0';i++)
{
symb=postfix[i];
if(isdigit(symb))
push(symb-'0');
else
{
op2=pop();
op1=pop();
switch(symb)
{
case'+':res=op1+op2;
break;
case'-':res=op1-op2;
break;
case'*':res=op1*op2;
break;
case'/':res=op1/op2;
break;
default:printf("invalid operator");
exit(0);
}
push(res);
}
}
printf("result is %d",res);
getch();
}