#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

int size=0;
struct node *head=NULL;
struct node *tail=NULL;

void display()
{   printf("NULL <-> ");
    struct node *temp = head;
 while (temp != NULL){
        printf("%d <-> ", temp -> data);
        temp = temp->next;
    }
    printf("NULL\nSize of list =  %d \n\n" , size);
    
}

void insertAtBeginning(int data){
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    size++;
}


void insertAtLast(int data){
	struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    newnode->next = NULL;
    size++;
}

void insertAtPosition(int position , int data){
    if(position == 1){
        insertAtBeginning(data);
        return;
    } 
    if(position == size){
        insertAtLast(data);
        return;
    }
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    struct node *temp = getNode(position);
    newnode->prev = temp->prev;
    temp->prev->next = newnode;
    newnode->next = temp;
    temp->prev = newnode;
    size++;
}

void deleteAtBeginning(){
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
    head->prev = NULL;
    size--;
}

void deleteAtLast(){
    struct node *temp;
    temp = tail;
    free(temp->next);
    tail = temp;
    tail->next = NULL;
    size--;
}

void deleteAtPosition(int position){
    if(position == 1){
        deleteAtBeginning();
        return;
    } 
    if(position == size){
        deleteAtLast();
        return;
    }
    struct node *temp = getNode(position);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    size--;
}

int search(){
	int element;
	printf("Enter the element you want to search for : \n");
	scanf("%d",&element); 
    struct node *temp = head;
    int position = 1;
    while (temp != NULL)
    {
        if(temp->data == element){
            return position;
        }
        position++;
        temp = temp->next;
    }
    return -1;
}


void reverse(){
    if (size < 2) {
            return;
        }
    struct node *present = head;
    struct node * previous  = NULL;
    struct node *nextnode = present->next;
    while(present != NULL){
        present->next = previous;
        present->prev = nextnode;
        previous = present;
        present = nextnode;
        if(nextnode != NULL){
            nextnode = nextnode -> next;
        }
    }
    head = previous;
    // display();
}

void recursiveReverse(struct node *currnode){
    if (size < 2) {
            return;
        }
    if(currnode == tail){
        head = tail;
        tail->prev = NULL;
        return;
    }
    recursiveReverse(currnode -> next);
    tail->next = currnode;
    currnode->prev = tail;
    
    tail = currnode;
    tail->next = NULL;
}


void Sort(int row , int col){
struct node *left , *right , *prev;
    if(row == 0 ){
         printf("\n New Sorted list is\n");
        display();
        return;
    }
    if(col < row){
        left = getNode(col);
        right = getNode(col + 1);
        if(left->data > right ->data){
            if(left == head){
                right->prev = NULL;
                left->next = right->next;
                right->next->prev = left;
                right->next = left;
                left->prev = right;
                head = right;
            }else if(right == tail){
                left->next = NULL;
                left->prev->next = right;
                tail = left;
                right->prev = left->prev;
                right->next = left;
                left->prev = right;
            }
            else{
                left->next = right->next;
                right->next->prev = left;
                left->prev->next = right;
                right->prev = left->prev;
                left->prev = right;
                right->next = left;
            }
        }
        Sort(row, col + 1);
        
    }else{
        Sort(row - 1, 0);
        
    }
   
    }

struct node* getNode(int location){
    struct node *temp = head;
    for (int i = 1 ; i < location ; i++)
    {
        temp = temp->next;
    }
    return temp;

}

void sortedInsert(){}

void handle_menu( int choice){
	switch(choice){
		case 0: printf("--[\033[91mExitting !!!\033[00m]--\n");
				break;
		case 1:	insert();
				break;
		case 2:	insertAtBeginning();
				break;
		case 3: insertAtLast();
				break;
		case 4: insertAtPosition();
				break;
		case 5:	deleteAtBeginning();
				break;
		case 6: deleteAtLast();
				break;
		case 7: deleteAtPosition();
				break;
		case 8: sizeofNode();
				break;
		case 9: if(search != -1)
					printf("Found at %d \n",search());
				else
					printf("Not Found \n")
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