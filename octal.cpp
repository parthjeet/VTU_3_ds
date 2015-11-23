#include<iostream.h>
#include<conio.h>
#include<math.h>
class octal
{
	int octnum;
	int convert(int n);
	public:
		octal(int x);
		int operator + (int x);
		friend ostream & operator << (ostream &dout, octal &ob1);
};
octal :: octal(int n)
{
	octnum = convert(n);
}
int octal::convert(int x)
{
	int sum=0, i=0;
	while(x!=0)
	{
		int num = x%8;
		sum += num*pow(10,i);
		i++;
		x=x/8;
	}
	return sum;
}
int octal :: operator +(int x)
{
	int sum = 0, i=0;
	while(octnum!=0)
	{
		int num = octnum%10;
		sum+=num*pow(8,i);
		i++;
		octnum = octnum/10;
	}
	return(sum+x);
}
ostream & operator << (ostream &dout, octal &ob1)
{
	dout<<ob1.octnum;
	return(dout);
}
void main()
{
	int x;
	clrscr();
	cout<<"\n Enter the integer(y) in decimal to be converted to octal : ";
	cin>>x;
	octal h = x;
	cout<<"\n Equivalent octal number of "<<x<<" is "<<h;
	cout<<"\n Enter an integer to be added : ";
	int k;
	cin>>k;
	int y = h+k;
	cout<<"\n After ading the integer to the octal number, the value of y : "<<y;
	getch();
}