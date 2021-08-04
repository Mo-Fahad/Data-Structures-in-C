#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

int display(struct Node*);

struct Node *insert_at_head(struct Node*,int);
struct Node *insert_at_tail(struct Node*,int);
struct Node *insert_at_pos(struct Node*,int,int);

struct Node *delete_at_head(struct Node*);
struct Node *delete_at_tail(struct Node*);
struct Node *delete_at_pos(struct Node*,int);

struct Node *reverse_list(struct Node*);

int main() {

    struct Node* head = NULL;

    head = insert_at_head(head,30);
    head = insert_at_head(head,10);
    head = insert_at_pos(head,20,2);
    head = insert_at_tail(head,40);
    head = insert_at_tail(head,50);

    display(head);
    head=reverse_list(head);
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

struct Node *insert_at_tail(struct Node* head,int data) {
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

struct Node *insert_at_pos(struct Node* head,int data,int pos) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL) {
        temp->next=head;
        return temp;
    }
    struct Node *ptr =  head;
    struct Node *prev;
    while (pos-1 && ptr)
    {
        prev = ptr;
        ptr = ptr->next;
        pos--;
    }
    prev->next = temp;
    temp->next = ptr;
    return head;
}

struct Node *delete_at_head(struct Node* head) {
    if (head==NULL)
    {
        return NULL;
    }
    
    struct Node *temp;
    temp = head;
    head = head->next;
    temp = NULL;
    free(temp);
    return head;
}

struct Node *delete_at_tail(struct Node* head) {
    if (head==NULL || head->next==NULL)
    {
        return NULL;
    }

    struct Node *temp;
    temp = head;
    while ((temp->next)->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

struct Node *delete_at_pos(struct Node* head, int pos) {
    if (head==NULL)
    {
        return NULL;
    }
    
    struct Node *temp=head,*prev;
    if (pos==1)
    {
        temp = head->next;
        head = NULL;
        free(head);
        return temp;
    }
    

    while (temp!=NULL && pos-1)
    {
        prev = temp;
        temp = temp->next;
        pos--;
    }
    if (temp==NULL)
    {
        return head;
    }
    

    prev->next = temp->next;
    temp = NULL;
    free(temp);
    return head;
}

struct Node *reverse_list(struct Node *head) {
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    
    struct Node *cur,*prev,*next;
    cur = head;
    next = cur->next;
    prev = NULL;
    while (next!=NULL)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;
    return cur;
}