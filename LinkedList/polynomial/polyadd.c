#include <stdio.h>
#include <stdlib.h>

struct Polynomial{
    int coeff;
    int power;
    struct Polynomial *nextVal;
};

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
void polyadd(struct Polynomial* poly1, struct Polynomial* poly2,
             struct Polynomial* poly)
{
    while (poly1->nextVal && poly2->nextVal) {
       
        if (poly1->power > poly2->power) {
            poly->power = poly1->power;
            poly->coeff = poly1->coeff;
            poly1 = poly1->nextVal;
        }
  
  
        else if (poly1->power < poly2->power) {
            poly->power = poly2->power;
            poly->coeff = poly2->coeff;
            poly2 = poly2->nextVal;
        }
  

        else {
            poly->power = poly1->power;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->nextVal;
            poly2 = poly2->nextVal;
        }
  
       
        poly->nextVal
            = (struct Polynomial*)malloc(sizeof(struct Polynomial));
        poly = poly->nextVal;
        poly->nextVal = NULL;
    }
    while (poly1->nextVal || poly2->nextVal) {
        if (poly1->nextVal) {
            poly->power = poly1->power;
            poly->coeff = poly1->coeff;
            poly1 = poly1->nextVal;
        }
        if (poly2->nextVal) {
            poly->power = poly2->power;
            poly->coeff = poly2->coeff;
            poly2 = poly2->nextVal;
        }
        poly->nextVal
            = (struct Polynomial*)malloc(sizeof(struct Polynomial));
        poly = poly->nextVal;
        poly->nextVal = NULL;
    }
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
    struct Polynomial *First = NULL,*Second =NULL , *polySum=NULL;
    createPoly(4,2,&First);
    createPoly(5,1,&First);
    createPoly(5,0,&First);
    printPolynomial(First);
    createPoly(8,2,&Second);
    createPoly(4,1,&Second);
    createPoly(6,0,&Second);
    printPolynomial(Second);
    polySum= (struct Polynomial *)malloc(sizeof(struct Polynomial));
    polyadd(First,Second,polySum);
    printPolynomial(polySum);
    return 0;
}