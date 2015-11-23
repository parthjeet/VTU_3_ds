#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>
char infx[25],pofx[25];
char s[10]; int top=-1;

int pr(char c)
{
	switch(c)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
		case '(':
		case '#': return 0;
	}
}
void push(char c)
{
	top++;
	s[top]=c;
}
char pop()
{
return(s[top--]);
}
void main()
{
	char ch;
	int i,j=0;
	clrscr();
	printf("\nEnter infix Expression : ");
	scanf("%s", &infx);
	push('#');
	for(i=0;infx[i]!='\0';i++)
	{
		ch = infx[i];
		if(isalnum(ch))
			pofx[j++]=ch;
		else if(ch=='(')
			push('(');
		else if(ch==')')
			{
			while(s[top]!='(')
				pofx[i++]=pop();
			}
		else
		{
			while(pr(s[top])>=pr(ch))
				pofx[j++]=pop();
			push(ch);
		}
	}
	while(s[top]!='#')
		pofx[j++]=pop();
	pofx[j++]='\0';
	printf("\n Postfix is : %s",pofx);
	getch();
}


