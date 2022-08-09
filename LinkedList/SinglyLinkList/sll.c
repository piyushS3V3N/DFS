#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;

void insert(){
	struct node *temp;
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data for link list : \n");
	scanf("%d", &newnode->data);
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
void insertionAtBeigning(){
	struct node *temp = head;
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data for link list : \n");
	scanf("%d", &newnode->data);
	
	newnode->next = head;
	head = newnode;
}
void insertionAtEnd(){
	struct node *temp;
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data for link list : \n");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = newnode;

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
void deletionAtBeigining(){
	struct node *temp = head;
	head = head->next;
	free(temp);


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
void deletionAtPos(){
	struct node *nextnode = head;
	struct node *prevnode = head->next;
	int pos;
	printf("Enter the position at which you want to enter data : \n");
	scanf("%d",&pos);
	for(int i= 0; i < pos -1 ; i++ )
	{
		nextnode = nextnode->next;
		prevnode = prevnode->next;
	}
	nextnode->next = prevnode->next;
	free(prevnode);
}
void sizeofNode(){
	int count = 0 ;
	struct node *temp = head;
	while(temp !=NULL)
	{
		count++;
		temp = temp->next;
	}
	printf("\n Size of Link List is : %d\n",count);
	}
void search() {
	int element;
	printf("Enter the element you want to search for : \n");
	scanf("%d",&element); 
	struct node* current = head;  // Initialize current
    while (current != NULL)
    {
        if (current->data == element){
            printf("element found !! \n" );
        	return ;
        }
        current = current->next;
    }
    printf("element not found \n");
    return;
    

}
void sort(){
	   struct node *current = head, *index = NULL;  
        int temp;  
          
        if(head == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                //Node index will point to node next to current  
                index = current->next;  
                  
                while(index != NULL) {  
                    //If current node's data is greater than index's node data, swap the data between them  
                    if(current->data > index->data) {  
                        temp = current->data;  
                        current->data = index->data;  
                        index->data = temp;  
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
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
void handle_menu( int choice){
	switch(choice){
		case 0: printf("--[\033[91mExitting !!!\033[00m]--\n");
				break;
		case 1:	insert();
				break;
		case 2:	insertionAtBeigning();
				break;
		case 3: insertionAtEnd();
				break;
		case 4: insertionAtPos();
				break;
		case 5:	deletionAtBeigining();
				break;
		case 6: deletionAtEnd();
				break;
		case 7: deletionAtPos();
				break;
		case 8: sizeofNode();
				break;
		case 9: search();
				break;
		case 10: sort();
				break;
		case 11: sortedInsert(&head);
				break;
		case 12: reverse(&head);
				break;
		case 13: display();
				break;
		default: printf("Error Invalide choice !! \n");
				break;
	}
}	
int main(){
	char *banner = "Select a choice : \n 1. Create a Link List \n 2. Insert at beiginning \n 3. Insert at end \n 4. Insert at specific postion \n 5. Deletion from beiginning \n 6. Deletion from end \n 7. Deletion from a specific position \n 8. Find length of Linked List/Count no of nodes \n 9. Search \n 10. Sort \n 11. Insert a node in such a way that linked list remains sorted \n 12. Reverse \n 13. Display \n 0. Exit";
	int choice=1;
	while(choice != 0 ){
	printf("%s \n", banner);
	scanf("%d",&choice);

	handle_menu(choice);
	
	}
	return 0;
}