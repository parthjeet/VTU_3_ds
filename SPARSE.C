#include<stdio.h>
#include<conio.h>
#include<process.h>

int a[10][10],s[10][3],i,j,key,nr,nc,nt;
void read()
{
	nt = 0;
printf("\nEnter the order of matrix : ");
scanf("%d %d",&nr,&nc);
printf("\nEnter the sparse matrix : ");
for(i=0;i<nr;i++)
{
for(j=0;j<nc;j++)
{
scanf("%d",&a[i][j]);
if(a[i][j]!=0)
{
nt++;
s[nt][0]=i;
s[nt][1]=j;
s[nt][2]=a[i][j];
}
}
}
s[0][0]=nr;
s[0][1]=nc;
s[0][2]=nt;
}
void print()
{
printf(" \n sparse matrix representation is : \n");
for(i=0;i<=nt;i++)
printf("%d \t %d\t %d\n",s[i][0],s[i][1],s[i][2]);
}
void search()
{
printf("\nEnter key to be searched :");
scanf("%d",&key);
for(i=1;i<=nt;i++)
{
if(key==s[i][2])
{
printf("\nkey found!!");
return ;
}
}
printf("\nKey not found!!");
}
void main()
{
int ch;
clrscr();
while(1)
{
printf("\n1:read 2:print 3:search 4:exit \n enter your choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1:read();
break;
case 2:print();
break;
case 3:search();
break;
default:exit(0);
}
}
getch();
}