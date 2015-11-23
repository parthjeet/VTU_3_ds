#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<alloc.h>


typedef struct node
{
int cf,ex;
struct node *link;
}NODE;
NODE *p3=NULL;
NODE *insert(NODE *last,int n)
{
int i;
NODE *nn;
for(i=1;i<=n;i++)
{
nn=(NODE *)malloc(sizeof(NODE));
printf("\nEnter the coefficient and exponents : ");
scanf("%d%d",&nn->cf,&nn->ex);
if(last==NULL)
{
nn->link=nn;
last=nn;
}
else
{
nn->link=last->link;
last->link=nn;
last=nn;
}
}
return last;
}
void add(NODE *p1,NODE *p2,int n1,int n2)
{
int i=0,j=0;
NODE *nn,*a,*b;
a=p1->link;
b=p2->link;
while(i<n1 && j<n2)
{
nn=(NODE *)malloc(sizeof(NODE));
if(p3==NULL)
{
nn->link=nn;
p3=nn;
}
else
{
nn->link=p3->link;
p3->link=nn;
p3=nn;
}
if(a->ex==b->ex)
{
nn->ex=a->ex;
nn->cf=a->cf+b->cf;
a=a->link;
b=b->link;
i++;
j++;
}
else if(a->cf>b->ex)
{
nn->ex=a->ex;
nn->cf=a->cf;
a=a->link;
i++;
}
else
{
nn->ex=b->ex;
nn->cf=b->cf;
b=b->link;
j++;
}
}
while(i<n1)
{
nn=(NODE *)malloc(sizeof(NODE));
nn->link=p3->link;
p3->link=nn;
p3=nn;
nn->ex=a->ex;
nn->cf=a->cf;
a=a->link;
i++;
}
while(j<n2)
{
nn=(NODE *)malloc(sizeof(NODE));
nn->link=p3->link;
p3->link=nn;
p3=nn;
nn->ex=b->ex;
nn->cf=b->cf;
b=b->link;
j++;
}
}
void display(NODE *last)
{
NODE *temp;
if(last==NULL)
{
printf("list is empty");
return;
}
temp=last->link;
while(temp!=last)
{
printf("(%d*^%d)+",temp->cf,temp->ex);
temp=temp->link;
}
printf("(%d*^%d)",temp->cf,temp->ex);
}
void main()
{
NODE *p1=NULL,*p2=NULL;
int n1,n2;
printf("\nEnter the number of terms of first polynomial : ");
scanf("%d",&n1);
p1=insert(p1,n1);
printf("enter the number of terms of the second polynomial");
scanf("%d",&n2);
p2=insert(p2,n2);
add(p1,p2,n1,n2);
printf("\nfirst polynomial is : ");
display(p1);
printf("\nsecond polynomial is : ");
display(p2);
printf("\nresultant polynomial is : ");
display(p3);
getch();
}
