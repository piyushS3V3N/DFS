#include <stdio.h>
#include <stdlib.h>
#define SIZE  20
struct Data_Item{
	int key;
	int data;
};
struct Data_Item* hashArray[SIZE];

int hashing_Function(int key){
	return key%SIZE;
}

int insert(int key ,int data){
	struct Data_Item *item = (struct Data_Item*) malloc(sizeof(struct Data_Item));
	item->key = key;
	item->data = data;
	int hashIndex = hashing_Function(key);
	while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){
		++hashIndex;
		hashIndex%=SIZE;
	}

	hashArray[hashIndex] = item;

}
struct Data_Item* delete(struct Data_Item* item){
	int key = item->key;
	int hashIndex = hashing_Function(key);
	while(hashArray[hashIndex]!=NULL){
		if(hashArray[hashIndex]->key == key){
			struct Data_Item *temp = hashArray[hashIndex];
			hashArray[hashIndex]=0;
			return temp; 
		}
		++hashIndex;
		hashIndex%=SIZE;
	}
	return NULL;
}

void display() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%d)\n",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~~ \n");
   }
	
   printf("\n");
}

int main(){
   
   insert(1, 20);
   insert(2, 70);
   insert(42, 80);
   insert(4, 25);
   insert(12, 44);
   insert(14, 32);
   insert(17, 11);
   insert(13, 78);
   insert(37, 97);

   display();
	return 0;
}