#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct{
	int rear;
	int front;
	unsigned size;
	int *array;
}Queue;

Queue *queueInitialize(unsigned size){
	Queue *temp = (Queue *)malloc(sizeof(Queue));
	temp->rear = size-1;
	temp->front = size-1;
	temp->size = size;
	temp->array = (int *)malloc(temp->size * sizeof(int));
	return temp;
}

void enqueue(Queue * queue, int item){
	queue->rear = (queue->rear + 1) % queue->size;
	if(queue->rear == queue->front){
		printf("Queue Overflow!\n");
		queue->rear--;
	}else{
		printf("Item Inserted at index %d: %d\n", queue->rear, item);
		queue->array[queue->rear] = item;	
	}
	 
}

int dequeue(Queue * queue){
	if(queue->front == queue->rear ){
		printf("Queue Underflowy!\n");
		return INT_MIN;
	}
	queue->front = (queue->front + 1) % queue->size;
	return queue->array[queue->front];
		
}

void display(Queue * queue){
	int i;
	for(i = (queue->front + 1) % queue->size; i != queue->rear + 1; i = (i + 1) % queue->size){
		printf("%d ", queue->array[i]);
	}
}
int main(){
	Queue *numbers = queueInitialize(5);
	enqueue(numbers, 1);
	printf("Item Deleted from %d: %d\n",numbers->front, dequeue(numbers));
	enqueue(numbers, 2);
	enqueue(numbers, 3);
	enqueue(numbers, 4);
	enqueue(numbers, 5);
	enqueue(numbers, 9);
	printf("Item Deleted from %d: %d\n",numbers->front, dequeue(numbers));
	printf("Item Deleted from %d: %d\n",numbers->front, dequeue(numbers));
	printf("Item Deleted from %d: %d\n",numbers->front, dequeue(numbers));
	printf("Item Deleted from %d: %d\n",numbers->front, dequeue(numbers));
	enqueue(numbers, 6);
	enqueue(numbers, 7);
	printf("Item Deleted from %d: %d\n",numbers->front, dequeue(numbers));

	display(numbers);
}

