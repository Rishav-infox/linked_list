#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head;
void insert_head(int);
void insert_tail(int);
struct node* getnode(int);
void print();
void print_reverse();

int main(void)
{
    head = NULL;
    insert_head(5);
    insert_head(6);
    insert_head(7);
    insert_head(9);
    insert_head(8);
    print();
    printf("Adding elements on tail: ");
    insert_tail(10);
    insert_tail(11);
    insert_tail(16);

    print();


    printf("In reverse: ");
    print_reverse();
    return 0;
}

void insert_head(int input)
{
    struct node* mynode = getnode(input);

    if(head == NULL)
    {
        head = mynode;
        return;
    }

    mynode->next = head;
    head->prev = mynode;
    head = mynode;
}
void insert_tail(int input)
{
    struct node* mynode = getnode(input);

    if(head == NULL)
    {
        head = mynode;
        return;
    }

    struct node* myonode = head;

    while(myonode->next != NULL)
        myonode = myonode->next;
    myonode->next = mynode;
    mynode->prev = myonode;
}

struct node* getnode(int input)
{
    struct node* newnode = malloc(sizeof(struct node));

    newnode->data = input;
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

void print()
{
    struct node* temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void print_reverse()
{
    struct node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;


    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}


