#include<stdio.h>
#include<conio.h>
#include<process.h>
#define max 3
int q[max],ele,i;
int front=0,rear=-1;
void qinsert()
{
if(rear==max-1)
{
printf("\nQueue is full");
return;
}
printf("\nEnter the ele to be inserted : ");
scanf("%d",&ele);
rear++;
q[rear]=ele;
}
void qdelete()
{
if(front>rear)
{
printf("\nQUEUE is empty");
rear=-1;
front=0;
return;
}
printf("\nElement deleted is : %d",q[front]);
q[front]=q[front+1];
q[rear-1]=q[rear];
rear--;
}
void qdisplay()
{
if(front>rear)
{
printf("\nQUEUE is empty");
return;
}
printf("\nContent of the q are : ");
for(i=front;i<=rear;i++)
printf("%d \t",q[i]);
}
void main()
{
int ch;
clrscr();
printf("1:insert 2:delete 3:display 4:exit");
do
{
printf("\nEnter choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1:qinsert();
break;
case 2:qdelete();
break;
case 3:qdisplay();
break;
case 4:exit(0);
}
}while(ch<=4);
getch();
}