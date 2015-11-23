#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node {
	int info;
	struct node *left, *right;
	
};
typedef struct node NODE;
NODE *first = NULL;
int ele, key;
void insert_key_front() {
	NODE *nn;
	nn = (NODE*)malloc(sizeof(NODE));
	printf("\nEnter the Value : ");
	scanf("%d", &ele);
	nn->info = ele;
	nn->left = NULL;
	nn->right = NULL;
	if (first == NULL)
	{
		first = nn;
		return;
	}
	nn->right = first;
	first->left = nn;
	first = nn;
}
void insert_lkey()
{
	NODE *nn, *temp, *prev;
	int key;
	nn = (NODE*)malloc(sizeof(NODE));
	printf("\nEnter the Key element : ");
	scanf("%d", &key);
	printf("\nEnter the Value : ");
	scanf("%d", &nn->info);
	if (key == first->info)
	{
		nn->right = first;
		nn->left = NULL;
		first->left = nn;
		first = nn;
		return;
	}
	prev = NULL;
	temp = first;
	while (temp->info!=key&&temp!=NULL)
	{
		prev = temp;
		temp = temp->right;
	}
	if (temp == NULL)
	{
		printf("\nKEY NOT FOUND");
		return;
	}
	nn->left = prev;
	prev->right = nn;
	nn->right = temp;
	temp->left = nn;
}
void delete_info()
{
	NODE *temp, *prev, *temp1;
	int sid;
	if (first == NULL) {
		printf("\nList is empty !!");
		return;
	}
	printf("\nEnter the Value to be deleted : ");
	scanf("%d", &sid);

	temp = first;
	if (first->info == sid) {
		first = first->right;
		free(temp);
		first->left = NULL;
		printf("\nNODE DELETED !!");
		return;
	}
	prev = first;
	temp = first->right;
	temp1 = temp->right;
	while (temp != NULL && temp->info != sid) {
		prev = prev->right;
		temp = temp->right;
		temp1 = temp1->right;
	}
	if (temp == NULL) {
		printf("\n Value not found");
		return;
	}
	prev->right = temp1;
	temp1->left = prev;
	free(temp);
	printf("\n NODE DELETED !! ");
}
void display()
{
	NODE *temp;
	temp=first;
	if (temp == NULL) {
		printf("\nList is empty");
		return;
		}
	while (temp != NULL) {
		printf("%d\t", temp->info);
		temp = temp->right;
	}
}
void main() {
	int ch;
	clrscr();
	printf("\n 1. Insert 2.Insert Left of Key 3.Delete 4.Display");
	while (1) {
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1: insert_key_front(); break;
		case 2: insert_lkey(); break;
		case 3: delete_info(); break;
		case 4: display(); break;
		default:exit(0);
		}
	}

}