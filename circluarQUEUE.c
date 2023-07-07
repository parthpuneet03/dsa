#include <stdio.h>
#include <stdlib.h>

//deletion is done from front end
//insertion is done from the rear end

struct Cqueue{
    int size;
    int f,r;
    int *arr;
};
void Init(struct Cqueue* q){
    int size;
    printf("ENTER size");
    scanf("%d",&size);
    q->size=size;
    q->f=q->r=0;
    q->arr=(int*)malloc(size*sizeof(struct Cqueue));
}
int isFull(struct Cqueue* q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct Cqueue* q){
    if(q->f==q->r){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct Cqueue* q, int val){
    if(isFull(q)){
        printf("Queue is full");
    }
    else{
        q->r= (q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("Element %d is Enqueued\n",val);
    }
}
int dequeue(struct Cqueue* q){
    int a= -999;
    if(isEmpty(q)){
        printf("Queue is Empty");
    }
    else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}
int main(){
    struct Cqueue *q;
    Init(q);
    // Enqueue few elements
    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1); 
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q)); 
    enqueue(q, 45);
    enqueue(q, 45);
    enqueue(q, 45);
 
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    if(isFull(q)){
        printf("Queue is full\n");
    }
 
    return 0;
}
