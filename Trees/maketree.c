#include <stdio.h>
#include <stdlib.h>
#define COUNT 2 
struct node {
	int data;
	struct node *left;
	struct node *right;
};


struct node * create(){
	struct node *newnode;
	int choice = 0;
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("Enter the data for node : \n");
	scanf("%d",&newnode->data);
	newnode->left = NULL;
	newnode->right = NULL;
	printf("Do you want to enter on right side of node : ");
	scanf("%d",&choice);
	if(choice==1){
		newnode->right=create(); 
	}
	printf("Do you want to enter on left side of node : ");
	scanf("%d",&choice);
	if(choice ==1){
		newnode->left=create(); 
	}
	return newnode;
}

void display(struct node *root, int space){
	if(root == NULL)
		return;
	space += COUNT;
	display(root->right,space);
	for (int i=COUNT ; i< space;i++)
		printf("\t");
	printf("%d\n",root->data);
	display(root->left,space);
}

int main(){
	struct node *root;
	root = create();
	display(root,COUNT);

	return 0;
}
