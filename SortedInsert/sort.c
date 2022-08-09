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
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("\nEnter the data for the list : ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	if(start == NULL)
		start = newnode;
	else
	{
		temp = start;
		while(temp->next != NULL)
			temp=temp->next;
		temp->next = newnode;
	}
}
void sortedInsert(struct node** head )
{
    struct node* newNode;
		newNode =(struct node *) malloc(sizeof(struct node));
		printf("Enter the data for node \n");
		scanf("%d",&newNode->data);
    if (*head == NULL || (*head)->data >= newNode->data)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
 
    
    struct node* current = *head;
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
}


void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe List elements are:\n");
                while(ptr!=NULL)
                {
                        printf("%d -> ",ptr->data );
                        ptr=ptr->next ;
                }
								
								printf("NULL \n");
  }
}

int main(){
		int choice = 1;
		while(choice){
			sortedInsert(&start);
			printf("\nWant to enter more ?? ");
			scanf("%d",&choice);
	}
	display();
	return 0;
}

