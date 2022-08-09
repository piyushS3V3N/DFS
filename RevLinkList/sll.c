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
void reverse(struct node** head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;

   while (current != NULL) {
      next  = current->next;
      current->next = prev;
      prev = current;
      current = next;
   }

   *head_ref = prev;
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
			insert();
			printf("\nWant to enter more ?? ");
			scanf("%d",&choice);
	}
	display();
	reverse(&start);
	display();
	return 0;
}
