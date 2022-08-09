#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(int x , struct Node **head){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
	newnode->data = x;
	newnode->next = *head;
	*head = newnode;
}
void pop(struct Node **head){
    struct Node *temp = *head;
	*head = temp->next;
	free(temp);
    printf("One Item Popped \n");
}
void peek(struct Node *head){
    printf("%d\n",head->data);
}
void display(struct Node *head){
    struct Node *ptr;
	ptr = head;
	printf("Data in Stack is : \n");
    while(ptr->next != NULL)
	{
		printf("\t[ %d ]\n", ptr->data);
		ptr = ptr->next;
	}
	printf("\t[ %d ]",ptr->data);
	printf("\n");
}


int main(){
    char *banner = "1.Push\n2.Pop\n3.Peek\n4.Display\n0.Exit\n";
    int x,choice=1;
    struct Node *head = NULL;
    while(choice != 0 ){
        printf("%s",banner);
        scanf("%d",&choice);
        switch(choice){
		case 0: printf("--[\033[91mExitting !!!\033[00m]--\n");
				break;
		case 1:	
                printf("Enter a item to push into stack\n");
                scanf("%d",&x);
                push(x,&head);
				break;
		case 2: pop(&head);
				break;
		case 3: peek(head);
				break;
		case 4: display(head);
				break;
    }
    }
    return 0;
}