#include<iostream.h>
#include<conio.h>
#include<process.h>
typedef struct node
{
int info;
struct node*link;
}
NODE;
class LIST
{
NODE *f;
public:LIST()
{
f=NULL;
}
void insert(int n);
void delete_node();
void display();
};
void LIST::insert(int n)
{
NODE *nn;
nn=new node;
nn->info=n;
nn->link=f;
f=nn;
}
void LIST::delete_node()
{
NODE *temp=f;

if(temp==NULL)
{
cout<<"\nEMPTY "<<endl;
}
else
{
cout<<"\nElement delete is : "<<temp->info;
f=temp->link;
delete(temp);
}
}
void LIST::display()
{
NODE *temp=f;
if(temp==NULL)
{
cout<<"\nEMPTY"<<endl;
return;
}
cout<<"\nContents are : ";
while(temp!=NULL)
{
cout<<temp->info<<"\t";
temp=temp->link;
}
}
void main()
{
LIST L;
int option;
clrscr();
cout<<"\n1:insert 2:delete 3:display 4:exit";
while(1)
{
cout<<"\nEnter the option : ";

cin>>option;
switch(option)
{
case 1:cout<<"\nEnter the element to be inserted : ";
int n;
cin>>n;
L.insert(n);
break;
case 2:L.delete_node();
break;
case 3:L.display();
break;
default:exit(0);
}
}
getch();
}