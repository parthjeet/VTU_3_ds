#include<iostream.h>
#include<conio.h>
class employee{
	int emp_no,bsc_sal,allw,gross,net,tax;
	char name[20];
public:
	void read();
	void calc();
	void get();
};

void employee::read(){
	cout<<"\nEnter the employee number : ";
	cin>>emp_no;
	cout<<"\nEnter the employee name : ";
	cin>>name;
	cout<<"\nEnter the basic salary : ";
	cin>>bsc_sal;
}
void employee::get(){
	cout<<"\nEmployee number : "<<emp_no;
	cout<<"\nEmployee name : "<<name;
	cout<<"\nGross salary  : "<<gross;
	cout<<"\nTax : "<<tax;
	cout<<"\nNet Salary : "<<net;
}
void employee::calc(){
	allw=1.23*bsc_sal;
	gross=bsc_sal+allw;
	tax=0.3*gross;
	net = gross - tax;
}
void main(){
	clrscr();
	employee ob1;
	ob1.read();
	ob1.calc();
	ob1.get();
	getch();
}