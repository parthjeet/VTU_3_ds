#include<stdio.h>
#include<conio.h>
#include<process.h>
#define MAX 8
int a[MAX],c,i,p,n=0,ele;
void insert()
{
if(n==MAX)
{
printf("heap is full\n");
return;
}
printf("enter elements \n");
scanf("%d",&ele);
c=n;
p=(c-1)/2;
while(c!=0&&ele>a[p])
{
a[c]=a[p];
c=p;
p=(c-1)/2;
}
a[c]=ele;
n++;
}
void print()
{
if(n==0)
{
printf("heap is empty\n");
return;
}
printf("contents of heap are\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
}
void main()
{
int ch;
clrscr();
while(1)
{
printf("enter your chice\n");
printf("1:insert 2:print 3:exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:insert();
break;
case 2:print();
break;
default:exit(0);
}
}
getch();
}