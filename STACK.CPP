#include<iostream.h>
#include<conio.h>
const int size=4;
class stack
{
int top;
int stk[size];
public:stack()
{
top=-1;
}
void operator+(int x);
int operator-();
int topvalue()
{
return top;
}
friend ostream &operator<<(ostream &dout,stack &s);
};
void stack::operator+(int x)
{
if(top==size=-1)
cout<<"\n stack overflow";
else
stk[++top]=x;
}
int stack::operator-()
{
return(stk[top--]);
}
ostream &operator<<(ostream &dout,stack &s)
{
if(s.topvalue()==-1)
cout<<"\n empty \n";
for(int i=s.topvalue();i>=0;i--)
dout<<s.stk[i]<<"\n";
return(dout);
}
void main()
{
clrscr();
int ch;
stack s;
do
{
cout<<"\n 1:insert 2:pop 3:exit\n";
cin>>ch;
switch(ch)
{
case 1:if(s.topvalue()!=size-1)
{
cout<<"enter the elements\n";
int x;
cin>>x;
s+x;
cout<<"contents are\n";
cout<<s;
break;
}
else
cout<<"\n stack overflow\n";
break;
case 2:if(s.topvalue()!=-1)
{
cout<<"popped element is\n"<<-s;
break;
}
else
{
cout<<"stack empty\n";
break;
}
default:cout<<"\n exiting\n";
break;
}
}
while(ch<3);
getch();
}
