// Doubly Linked list with all individual operations
#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};

void printNodes(struct node* head){
    printf("\n");
    while(head!=NULL){
        printf("%d \t", head->data);
        head=head->next;
    }
}

struct node* addToEmpty(struct node* head, int data ){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    temp->data=data;
    head=temp;
    return head;
}

struct node* AddAtBeg(struct node* head, int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->prev=NULL;
    temp->data=data;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}

void AddAtEnd(struct node* head, int data){
    struct node *tmp, *tp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->next=NULL;
    tmp->prev=NULL;
    tmp->data=data;
    tp=head;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=tmp;
    tmp->prev=tp;
}
/*doesnt work*/struct node* AddAtpos(struct node* head, int data, int pos){
    struct node* new=NULL;
    struct node* temp= head;
    struct node* temp2=NULL;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    while(pos!=1){
        temp=temp->next;
        pos--;
    }
    if(temp->next=NULL){
        temp->next=new;
        new->prev=temp;
    }
    else{
        temp2=temp->next;
        temp->next=new;
        new->prev=temp;
        new->next=temp2;
        temp2->prev=new;
    }
    return head;
}/*doesnt work*/

struct node* createlist(struct node* head){
    int n,data,i;
    printf("enter the no. of nodes: ");
    scanf("%d",&n);
    if(n==0){
        return head;
    }
    printf("Enter the element for node 1: ");
    scanf("%d",&data);
    head=addToEmpty(head,data);
    for(i=1;i<n;i++){
        printf("Enter the element for Node %d: ", i+1);
        scanf("%d",&data);
        AddAtEnd(head,data);
    }
    return head;
}

struct node* DelFirst(struct node* head){
    head=head->next;
    free(head->prev);
    head->prev=NULL;
    return head;
}

void DelLast(struct node* head){
    struct node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
    ptr=NULL;
};
struct node* DelPos(struct node* head){
    struct node* ptr=head;
    int pos;
    printf("\nEnter position of node to be deleted");
    scanf("%d",&pos);
    if(pos==1){
        struct node*ptr=head;
        head=head->next;
        free(ptr);
        head->prev=NULL;    
        return head;
    }
    while(pos>1){
        ptr=ptr->next;
        pos--;
    }
    if(ptr->next==NULL){
        DelLast(head);
    }
    else{
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        free(ptr);
        ptr=NULL;
    }
    return head;
}

int main(){
    /*struct node* head=NULL;
    struct node* ptr;
    int d;
    int pos=2;
    scanf("%d",&d);
    head=addToEmpty(head,d);
    scanf("%d",&d);
    head=AddAtBeg(head,d);
    scanf("%d",&d);
    AddAtEnd(head,d);
    scanf("%d",&d);
    //head=AddAtpos(head,d,pos);
    printNodes(head);
    ptr=head;
    while(ptr!=NULL){
        printf("%d \n", ptr->data);
        ptr=ptr->next;
    }*/
    struct node* head=NULL;
    head=createlist(head);
    printf("before del:");
    printNodes(head);
    
    head=DelFirst(head);
    printf("\nafter del 1:");
    printNodes(head);
    
    DelLast(head);
    printf("\nafter del 2:");
    printNodes(head);
    
    head=DelPos(head);
    printf("\nafter del 3:");
    printNodes(head);
return 0;
}
