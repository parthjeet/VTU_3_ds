#include<iostream.h>
#include<conio.h>
#include<string.h>
class string
{ char x[40];
public:
	string(){}
	string(char s[]){
		strcpy(x,s);
	}
	string(string &s){
		strcpy(x,s.x);
	}
	string operator +(string s2){
		string res;
		strcpy(res.x, x);
		strcat(res.x,s2.x);
		return(res);
	}
	friend ostream & operator << (ostream &n, string &s);
	
};
ostream & operator << (ostream &d, string &s){
	d<<s.x;
	return d;
}
void main()
{
	clrscr();
	string s1 = "VTU";
	string s2 = "BELGAUN";
	string s3 = s1+s2;
	cout<<"\n s1 = "<<s1;
	cout<<"\n s3 = "<<s2;
	cout<<"\n s2 = "<<s3;
	getch();
}