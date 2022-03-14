#include<stdlib.h>
#include <stdio.h>

//queue using array

struct queue{
    int size;
    int f,r;
    int *arr;
};

void init(struct queue *q){
    int size;
    printf("ENTER size of queue:\t");
    scanf("%d",&size);
    q->size=size;
    q->r=q->f=-1;
    q->arr=(int*)malloc(size*sizeof(int));
}

int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue is OverFlow");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}

int dequeue(struct queue* q){
    int a=-999;
    if(isEmpty(q)){
        printf("Queue is underflow");
        exit(0);
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue *q;
    init(q);
    enqueue(q,100);
    enqueue(q,110);
    enqueue(q,120);
    printf("Dequeuing ELement %d\n", dequeue(q));
    printf("Dequeuing ELement %d\n", dequeue(q));
    printf("Dequeuing ELement %d\n", dequeue(q));
    printf("Dequeuing ELement %d\n", dequeue(q));
}
