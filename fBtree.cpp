#include<iostream.h>
#include<conio.h>
class btree{
	int t[50];
	int p,q;
	public:
		btree(){
			
			for(int i=0;i<50;i++)
				t[i]=0;
			}
		void create();
		void inorder(int);
		void preorder(int);
		void postorder(int);
	};
	
void btree::create(){
	int num;
	cout<<"\nEnter the number of Elements : ";
	cin>>num;
	for(int i=0;i<num;i++){
		cout<<"\nEnter the element number "<<i+1<<" : ";
		cin>>t[i];
		}
	}
void btree::inorder(int pos){
	
	p = 2*pos + 1;         
	if(t[p] != 0)
	inorder(p);

	cout<<"\t"<<t[pos];

	q = 2*pos +2;
	if(t[q] != 0)
	inorder(q);

}
void btree::preorder(int pos){
	cout<<"\t"<<t[pos];
	
	p = 2*pos + 1;
	if(t[p] != 0)
	preorder(p);
	
	q = 2*pos +2;
	if(t[q] != 0)
	preorder(q);
}
void btree::postorder(int pos)
{
	p = 2*pos + 1;
	if(t[p] != 0)
	postorder(p);
	
	q = 2*pos +2;
	if(t[q] != 0)
	postorder(q);
	
	cout<<"\t"<<t[pos];
}
void main()
{	
	clrscr();
	cout<<"\t IMPLEMENTATION OF BINARY TREE \n\n";
	btree t1;
	t1.create();
	cout<<"\nPREORDER : \n";
	t1.preorder(0);
	cout<<"\nINORDER : \n";
	t1.inorder(0);
	cout<<"\nPOSTORDER : \n";
	t1.postorder(0);
    getch();
}	
