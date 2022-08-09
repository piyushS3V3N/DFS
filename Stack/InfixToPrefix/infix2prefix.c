#include <stdio.h>
#include <string.h>
#define MAX 20
int top = -1;
char stack[20];
int isEmpty(){
    return top == -1;
}
int isFull(){
    return top == MAX - 1;
}

char peek(){
    return stack[top];
}

char pop(){
    if(isEmpty())
        return -1;

    char ch = stack[top];
    top--;
    return(ch);
}

void push(char oper){
    if(isFull())
        printf("Stack Full!!!!");
   
    else{
        top++;
        stack[top] = oper;
    }
}
 void display(int *arr){
     for(int i = top ; i>=0; i--)
        printf("Data is : %d  \n", arr[i]);
        
 }

int checkIfOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 

    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
} 


int getPostfix(char expression[]) 
{ 
    int i, j;

    for (i = 0, j = -1; expression[i]; ++i) 
    { 
      
        if (checkIfOperand(expression[i])) 
            expression[++j] = expression[i]; 

       
        else if (expression[i] == '(') 
            push(expression[i]); 

       
        else if (expression[i] == ')') 
        { 
            while (!isEmpty(stack) && peek(stack) != '(') 
                expression[++j] = pop(stack); 
            if (!isEmpty(stack) && peek(stack) != '(') 
                return -1;            
            else
                pop(stack); 
        } 
        else
        { 
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack))) 
                expression[++j] = pop(stack); 
            push(expression[i]); 
        } 

    } 

  
    while (!isEmpty(stack)) 
        expression[++j] = pop(stack); 

    expression[++j] = '\0'; 
    
}

void reverse(char exp[]){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}
void brackets(char exp[]){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}
void InfixtoPrefix(char exp[]){

    int size = strlen(exp);
    reverse(exp);
    brackets(exp);
    getPostfix(exp);
    reverse(exp);
}

 int main(){
    char s[] = "A+(B*(C+D))"; 
    InfixtoPrefix(s);
    printf("%s",s);
    return 0;    
}