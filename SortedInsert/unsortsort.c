#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct node *start = NULL;
void insert(){
	struct node *newnode;
	struct node *temp;

	printf("\nEnter the data for new node : \n");
	scanf("%d",&newnode->data);

	if(start==NULL)
		start = newnode;
	else{
		temp=start;
		while(temp->next != NULL)
			temp=temp->next;
		temp->next = newnode;
	}
}

void SortMe(struct node** head){
	struct node *current = *head;
	struct node *ptr = *head;
	while(current->next != NULL && current->next->data < ->data)
	{
		current = current->next;
	}
	ptr->next = current->next;
}
