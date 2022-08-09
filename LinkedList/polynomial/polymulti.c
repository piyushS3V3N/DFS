#include <stdio.h>
#include <stdlib.h>

struct Polynomial{
    int coeff;
    int power;
    struct Polynomial *nextVal;
};
struct Polynomial *First = NULL;
void createPoly(int coeff , int power, struct Polynomial **First){
    struct Polynomial *newPoly;
    struct Polynomial *temp = NULL;
    newPoly = (struct Polynomial *) malloc(sizeof(struct Polynomial));
    newPoly->coeff = coeff;
    newPoly->power = power;
    newPoly->nextVal = NULL;
    if(*First == NULL)
    {
        *First = newPoly;
    }
    else{
        temp = *First;
        while(temp->nextVal!= NULL){
            temp = temp->nextVal;
        }
        temp->nextVal = newPoly;
    }
}
void removeDuplicates(struct Polynomial* start)
{
    struct Polynomial *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    while (ptr1 != NULL && ptr1->nextVal != NULL) {
        ptr2 = ptr1;
 
       
        while (ptr2->nextVal != NULL) {
 
            
            if (ptr1->power == ptr2->nextVal->power) {
 
                
                ptr1->coeff = ptr1->coeff + ptr2->nextVal->coeff;
                dup = ptr2->nextVal;
                ptr2->nextVal = ptr2->nextVal->nextVal;
 
                free(dup);
            }
            else
                ptr2 = ptr2->nextVal;
        }
        ptr1 = ptr1->nextVal;
    }
}
 

struct Polynomial* multiply(struct Polynomial* poly1, struct Polynomial* poly2,
               struct Polynomial* poly3)
{

    struct Polynomial *ptr1, *ptr2;
    ptr1 = poly1;
    ptr2 = poly2;
    while (ptr1 != NULL) {
        while (ptr2 != NULL) {
            int coeff, power;
 
          
            coeff = ptr1->coeff * ptr2->coeff;
 
            power = ptr1->power + ptr2->power;
 
     
            createPoly(coeff, power,&poly3 );
 
   
            ptr2 = ptr2->nextVal;
        }
 
        ptr2 = poly2;
 
        ptr1 = ptr1->nextVal;
    }
    removeDuplicates(poly3);
    return poly3;
}
void printPolynomial(struct Polynomial *First){
    struct Polynomial *temp = First;
    while(temp->nextVal != NULL){
        printf("%dx^%d+",temp->coeff,temp->power);
        temp = temp->nextVal;
    }
    printf("%d\n",temp->coeff);
}
int main(){
    struct Polynomial *First = NULL,*Second =NULL , *polyMulti=NULL;
    createPoly(4,2,&First);
    createPoly(5,1,&First);
    createPoly(5,0,&First);
    printPolynomial(First);
    createPoly(8,2,&Second);
    createPoly(4,1,&Second);
    createPoly(6,0,&Second);
    printPolynomial(Second);
    polyMulti = multiply(First,Second,polyMulti);
    printPolynomial(polyMulti);
    return 0;
}