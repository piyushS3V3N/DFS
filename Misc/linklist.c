#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};
struct Node *start = NULL;

void display()
{
        struct Node *ptr;
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
void insert(){
		struct Node *one ;
		struct Node *temp;
		one = (struct Node *) malloc(sizeof(struct Node));
		printf("\nEnter the data for list : ");
		scanf("%d",&one->data);
		one->next= NULL;
		if(start == NULL)
		{
				start = one;
			}
		else
		{	
			temp = start;
			while(one->next != NULL)
				temp=one->next;
			temp->next = one;  
			
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
}	
