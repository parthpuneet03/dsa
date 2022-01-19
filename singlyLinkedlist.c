/*SINGLE LINKED LIST ALL BASIC OPERATIONS, COMPLETE LIST DELETION AND REVERSAL*/
#include <stdio.h>
#include <stdlib.h>
struct node{
    
    int data;
    struct node *link;
};

// function to traverse linked list and print the data of the nodes
void countOfNodes(struct node* head){
    int count=0;
    if(head==NULL){
        printf("Linked list is empty");
    }
    struct node* ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        printf("%d \t",ptr->data);
        //printf("%d \n",ptr);
        ptr=ptr->link;
    }
    printf("%d \n",count);
};
//functions for insertion of node and data
void addAtend(struct node* head, int data){
    struct node *ptr,*temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    while(ptr->link != NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
};

struct node* AddAtBeg(struct node* head,int d){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=d;
    ptr->link=NULL;
    ptr->link=head;
    head=ptr;
    return head;
};

void AddAtpos(struct node* head, int d, int pos){
    struct node* ptr= head;
    struct node* ptr2=(struct node*)malloc(sizeof(struct node));
    ptr2->data=d;
    ptr2->link=NULL;

    for (int i=1; i<pos-1 && ptr!=NULL;i++){
        ptr=ptr->link;
    }
    ptr2->link=ptr->link;
    ptr->link=ptr2;
};

struct node* delFirst(struct node* head){
    if(head==NULL)
        printf("LInked List is empty");
    else{
        struct node* ptr=head;
        head=head->link;
        free(ptr);
        ptr=NULL;
    }
    return head;
};

void DelAtLast1(struct node* head){
    if (head==NULL){
        printf("list is empty");
    }
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node*temp=head;
        while(temp->link->link!=NULL){
            temp=temp->link;
        }
        free(temp->link);
        temp->link=NULL;
    }
};

void DelAtLast2(struct node * head){
    if(head==NULL){
        printf("list is empty ");
    }
    else if(head->link=NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node* ptr1=head;
        struct node* ptr2=head;
        //for traversal to last and second last node
        while(ptr1->link !=NULL){
            ptr2=ptr1;
            ptr1=ptr1->link;
        }
        ptr2->link=NULL;
        free(ptr1);
        ptr1=NULL;
    }
};

void delAtPos(struct node ** head, int pos){
    
    struct node * current= *head ;
    struct node * prev = *head ;
    if(*head==NULL){
        printf("List Is empty");
    }
    else if(pos==1){
        *head=current->link;
        free(current);
        current=NULL;
    }
    else{
        /*while(pos!=1){
            prev=current;
            current=current->link;
            pos--;
        }
        prev->link=current->link;
        free(current);
        current= NULL;
    }
    //both above and below logic work fine its a matter of preference 
    */
    int i=1;
    while(i<pos-1){
        prev=prev->link;
        i++;
    }
    current=prev->link;
    prev->link=current->link;
    free(current);
    current=NULL;
    }
};

struct node* DelList(struct node * head){
    struct node* temp= head;
    while(temp!=NULL){
        temp=temp->link;
        free(head);
        head=temp;
    }
    return head;
}

struct node* RevList(struct node* head){
    struct node* prev= NULL;//temp
    struct node* next= NULL;//temp2
    while(head!=NULL){
        next=head->link;
        head->link= prev;
        prev=head;
        head=next;
    }
    head= prev;
    return head;
};

int main(){
    //CREATION
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *current=(struct node *)malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link=current;

    //int d=22;
    current=malloc(sizeof(struct node));
    current->link=NULL;
    current->data=14;
    head->link->link=current;
    //printf("%d \n",head->data);
    //printf("%d \n",head->link->data);
    //printf("%d",head->link->link->data);
    //addAtend(head,56);
    head= AddAtBeg(head,25);
    AddAtpos(head,50,3);
    //countOfNodes(head);
    //head=delFirst(head);
    //DelAtLast1(head);
    AddAtpos(head,69,4);
    countOfNodes(head);
    delAtPos(&head,3);
    countOfNodes(head);
    //head= DelList(head);
    head= RevList(head);
    countOfNodes(head);
    return 0;
}
