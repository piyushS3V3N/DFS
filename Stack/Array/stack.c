#include <stdio.h>
#include <malloc.h>

int *arr;
int top=-1;
void init_arr(int size){
    arr = (int *)malloc(sizeof(int)*size);
    
}
void push(int item){
    if(top == sizeof(arr)/sizeof(int))
        printf("overflow\n");
    else
    {
        top++;
        arr[top] = item;
        
    }
 }
 void pop(){
     int item = arr[top];
     top--;
     printf("\n Item is deleted \n");
 }
 void display(){
     for(int i = top ; i>=0; i--)
        printf("Data is : %d  \n", arr[i]);
        
 }
 void peek()
 {
     printf("Peek : %d\n",arr[top]);
 }
void handle_menu(int choice){
    int x;
     switch(choice){
		case 0: printf("--[\033[91mExitting !!!\033[00m]--\n");
				break;
		case 1:	
                printf("Enter a item to push into stack\n");
                scanf("%d",&x);
                push(x);
				break;
		case 2: pop();
				break;
		case 3: peek();
				break;
		case 4: display();
				break;
    }
}
int main()
{
    char *banner = "1.Push\n2.Pop\n3.Peek\n4.Display\n0.Exit\n";
    int choice=1;
    int size = 1;
    printf("Enter the size of stack you want to create \n");
    scanf("%d",&size);
    init_arr(size);

    

    while(choice != 0 ){
        printf("%s",banner);
        scanf("%d",&choice);
        handle_menu(choice);
    }
    return 0;
}