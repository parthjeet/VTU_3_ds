#include<iostream.h>
#include<conio.h>
#include<process.h>
class date
{
int d,m,y,a[15];
public : date()
{
a[4]=a[6]=a[9]=a[11]=30;
a[1]=a[3]=a[7]=a[8]=a[10]=a[12]=31;
a[2]=28;
}
void read();
date operator+(int x);
int operator-(date);
friend ostream & operator<<(ostream &out,date);
};
ostream & operator<<(ostream &out,date x)
{
out<<x.d<<"/"<<x.m<<"/"<<x.y;
return out;
}
void date::read()
{
l1:cin>>d>>m>>y;
if(y%4==0||y%400==0)
a[2]=29;
if(((d>31||m>12)||(m==4||m==6||m==9||m==11)&&d>30)||((y%4==0||y%400)&&m==2&&d>29))
{
cout<<"\n invalid date \n please re-enter the date ";
goto l1;
}
}
date date::operator+(int n)
{
for(int i=1;i<=n;i++)
{
d++;
if(y%4==0||y%400==0)
{
a[2]=29;
}
else
{
a[2]=28;
}
if(d>a[m])
{
d=1;
m++;
}
if(m>12)
{
y++;
m=1;
}
}
return *this;
}
int date::operator-(date x)
{
int count=0;
if(y==x.y&&m==x.m)
count=d-x.d;
else if(y==x.y)
{
while(m!=x.m)
{
count++;
x.d++;
if(x.d>a[x.m])
{
x.d=1;
x.m++;
}
}
count=count-d-1;
}
else
{
while(1)
{
if(y==x.y&&m==x.m)
break;
if((x.y%4==0)||(x.y%400==0))
a[2]=29;
count++;
x.d++;
if(x.d>a[x.m])
{
x.d=1;
x.m++;
}
if(x.m>12)
{
x.y++;
x.m=1;
}
}
count-1==d-1;
}
return count;
}
void main()
{
date d1,d2;
clrscr();
cout<<"\nenter date 1 :";
d1.read();
cout<<"\nenter date 2 (should be earlier to date 1) :";
d2.read();
cout<<"\n date2 is : "<<d2;
cout<<"\n date1 is : "<<d1;
cout<<"\n("<<d1<<")-("<<d2<<") = "<<d1-d2;
cout<<"\n enter no. of days to add : ";
int n;
cin>>n;
date temp=d1;
temp+n;
cout<<"date 1 +"<<n<<" = "<<temp;
getch();
}
