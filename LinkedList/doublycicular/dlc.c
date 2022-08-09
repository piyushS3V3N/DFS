#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
    struct node *prev;
};
struct node *head , * node , * tail = NULL;
 //global pointers.
int size = 0;
struct node *getNode (int location);
struct node *getNode (int location)
{
    struct node *temp = head;
    for (int i = 1; i < location; i++)
    {
        temp = temp -> next;
    }
    return temp;

}
void display()
{
    struct node *temp = head;
    printf("TAIL <-> ");
    do {
        printf("%d <-> ", temp->value);
        temp = temp -> next;
    }while (temp != head);
    printf("HEAD\nSize of list =  %d \n\n" , size);
}

void insertAtBeginning(int value){
    node = (struct node*) malloc(sizeof(struct node));
    node->value = value;
    head->prev = node;
    node->next = head;
    tail->next = node;
    node->prev = tail;
    head = node;
    size++;
}


void insertAtLast(int value){
    node = (struct node*) malloc(sizeof(struct node));
    node->value = value;
    tail->next = node;
    node->prev = tail;
    tail = node;
    tail->next = head;
    head->prev = tail;
    size++;
}

void insertAtPosition(int position , int value){
    if(position == 1){
        insertAtBeginning(value);
        return;
    } 
    if(position == size){
        insertAtLast(value);
        return;
    }
    node = (struct node*) malloc(sizeof(struct node));
    node->value = value;
    struct node *temp = getNode(position);
    node->prev = temp->prev;
    temp->prev->next = node;
    node->next = temp;
    temp->prev = node;
    size++;
}

void deleteAtBeginning(){
    tail -> next = head -> next;
    free(getNode(1));
    head = tail->next;
    head->prev = tail;
    size--;
}

void deleteAtLast(){
    free(tail);
    tail = getNode(size - 1);
    tail->next = head;
    head->prev = tail;
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

int search(int value){
    struct node *temp = head;
    int position = 1;
    do
    {
        if(temp -> value == value){
            return position;
        }
        position++;
        temp = temp -> next;
    }while (temp != head);
    return -1;
}


void reverse(){
    if (size < 2) {
            return;
        }
    
    struct node * previous  = tail;
    struct node *present = head;
    struct node *nextnode = present->next;
    // struct node *last = nextnode;
        do {
        present->next = previous;
        present->prev = present;
        previous = present;
        present = nextnode;
        nextnode = nextnode -> next;
    }while(previous != tail);
    tail = present;
    head = previous;
    display();
}


void bubbleSort(int row , int col){
struct node *left , *right , *prev;
    if(row == 0){
        printf("\n New Sorted list is\n");
        display();
        return;
    }
    if(col <= row){
        left = getNode(col);
        right = getNode(col + 1);
        if(left -> value > right -> value){
            if(left == head){
                left->next = right->next;
                right->next->prev = left;
                right->next = left;
                left -> prev = right;
                right->prev = tail;
                head = right;
                tail -> next = head;
            }else if(right == tail){
                head->prev = left;
                left->next = head;
                prev = getNode(col - 1);
                prev->next = right;
                right->prev = prev;
                right->next = left;
                left->prev = right;
                tail = left;
            }
            else{
                prev = getNode(col - 1);
                prev->next = right;
                right->prev = prev;
                left->next = right->next;
                right->next -> prev = left;
                right->next = left;
                left->prev = right;
            }
        }
        bubbleSort(row, col + 1);
    }else{
        bubbleSort(row - 1, 0);
    }
   
}






int main(){
    int choiceOfUser = 1;
    int valueToSearch = -1;
    int nextChoice = 0;
    int position = 0;
    int value;
    printf("Creating the first node...\nEnter the value for the first node. ->  ");
    node = (struct node*) malloc(sizeof(struct node));
    scanf("%d" , &node->value);
    node->next = NULL;
    node->prev = NULL;
    head = node;
    tail = head;
    size++;
    printf("What do you want to do?\n1 -> Insertion\n2 -> Deletion\n3 -> Display\n4 -> Search\n5 -> Reverse\n6 -> Sort list\n7 -> Quit\n");
    scanf("%d" , &choiceOfUser);
    while(choiceOfUser <= 7){
    if(choiceOfUser == 7){
        return;
    }else if(choiceOfUser == 6){
        bubbleSort(size - 1  , 0); 
        printf("Would you like to insert an element in a sorted list in a way that keeps it sorted?\nyes -> 1\nno -> 0\n");
        scanf("%d" , &nextChoice);
        while(nextChoice < 2){
        if(nextChoice == 0){
            break;
        } else{
            printf("Enter the value for the new node");
            scanf("%d" , &value);
            if(value <= head->value){
                insertAtBeginning(value);
                printf("\nnode inserted!\n");
                        printf("\nNew list : \n");
                        display();
            }else if(value >= tail->value){
                insertAtLast(value);
                printf("\nnode inserted!\n");
                        printf("\nNew list : \n");
                        display();
                        
            }else{
                struct node *temp = head->next;
                int pos = 1;
                while(temp != NULL){
                    if(value >= temp->value){
                        temp = temp->next;
                        pos++;
                    }else{
                        break;
                    }
                }
                insertAtPosition(pos + 1, value);
                printf("\nnode inserted!\n");
                printf("\nNew list : \n");
                display();
                }
            }
            printf("Would you like to insert an element in a sorted list in a way that keeps it sorted?\nyes -> 1\nno -> 0\n");
            scanf("%d" , &nextChoice);
        }
    }
    else if (choiceOfUser == 5){
        reverse();
      
        display();
    }
    else if(choiceOfUser == 4){
        printf("What is the value that you want to search? ->  ");
        scanf("%d" , &valueToSearch);
        if(search(valueToSearch) != -1){
        printf("The value %d was found at position number %d\n\n" , valueToSearch , search(valueToSearch));
        }else{
            printf("Element not found in the linked list!!!\n\n");
        }

    }
    else if(choiceOfUser == 3){
        display();
    }
    else if(choiceOfUser == 1){
        printf("Press 1 for inserting a node at beginning\nPress 2 for inserting a node at ending\nPress 3 for inserting a node at a particular index  ");
        scanf("%d" , &nextChoice);
        if(nextChoice == 1){
            printf("Enter the value for the node.");
            scanf("%d" , &value);
            insertAtBeginning(value);
        }
        else if(nextChoice == 2){
            printf("Enter the value for the node.");
            scanf("%d" , &value);
            insertAtLast(value);
        }
        else{
            printf("Enter the position where you want to insert the node.");
            scanf("%d" , &position);
            printf("Enter the value for the node.");
            scanf("%d" , &value);
            insertAtPosition(position , value);
        }
    }
    else{
        printf("Press 1 for deleting a node at beginning\nPress 2 for deleting a node at ending\nPress 3 for deleting a node at a particular index  ");
        scanf("%d" , &nextChoice);
        if(nextChoice == 1){
            deleteAtBeginning();
        }
        else if(nextChoice == 2){
            deleteAtLast();
        }
        else{
            printf("Enter the position where you want to delete the node. ");
            scanf("%d" , &position);
            deleteAtPosition(position);
        }
    }

    printf("What do you want to do?\n1 -> Insertion\n2 -> Deletion\n3 -> Display\n4 -> Search\n5 -> Reverse\n6 -> Sort list\n7 -> Quit\n\n");
    scanf("%d" , &choiceOfUser);

    }
    return 0;
}
