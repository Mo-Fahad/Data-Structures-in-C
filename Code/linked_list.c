#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

int display(struct Node*);

struct Node *insert_at_head(struct Node*,int);
struct Node *insert_at_end(struct Node*,int);

int main() {

    struct Node* head = NULL;

    //head = insert_at_head(head,10);

    display(head);

    return 1;
}

int display( struct Node* head ) {
    if (head==NULL)
    {
        return -1;
    }
    struct Node *temp = head;
    while(temp!=NULL) {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    return 1;
}

struct Node *insert_at_head( struct Node* head, int data ) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if(head==NULL) {
        return temp;
    }
    temp->next = head;
    head = temp;
    return head;
}

struct Node *insert_at_end(struct Node* head,int data) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if(head==NULL) {
        return temp;
    }
    struct Node *ptr = head;
    while(ptr->next!=NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}