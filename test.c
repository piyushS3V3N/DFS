#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;

void insert(int x){
	struct node *temp;
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->next = NULL;
	if(head == NULL){
		head = newnode;
	}
	else{
		temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newnode ;	
	}
}
void insertionAtPos(){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	struct node *temp =head;
	int pos;
	printf("Enter the position at which you want to enter data : \n");
	scanf("%d",&pos);
	printf("Enter the data for the link list : \n");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	int i = 0 ;
	while(i<pos)
	{
		temp = temp->next;
		i++;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}

void deletionAtEnd(){
	struct node *temp=head;
	struct node *temp1;
	while(temp->next != NULL)
	{ 
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = NULL;
	free(temp);

}

void display(){
	struct node *ptr;
	ptr = head;
	while(ptr->next != NULL)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("%d",ptr->data);
	printf("\n");
}

int main(){
	char *banner=" Select one : \n 1. Insert at a pos \n2. Deletion at end \n3.Display ";
	int choice = 1;
	insert(12);
	insert(14);
	insert(15);
	while(choice != 0){
		printf("%s\n",banner );
		scanf("%d",&choice);
		switch(choice){
		case 0: printf("--[\033[91mExitting !!!\033[00m]--\n");
				break;
		case 1:	insertionAtPos();
				break;
		case 2:	deletionAtEnd();
				break;
		case 3: display();
				break;
		default: printf("Invalid option \n");
		break;
	}
	}
}