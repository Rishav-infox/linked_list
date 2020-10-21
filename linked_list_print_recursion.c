#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; 
    struct node* next;
};

struct node* head;

void print();
void insert(int);
void reverse(struct node*);

int main(void)
{
    head = NULL;
    insert(4);
    insert(6);
    insert(9);
    insert(8);
    print();
    reverse(head);
    print();

    return 0;
}


void insert(int input)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = input;

    if(head == NULL)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        struct node* temp1 = head;

        while(temp1->next != NULL)
            temp1 = temp1->next;
        temp->next = temp1->next;
        temp1->next = temp;
    }
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

void reverse(struct node* temp)
{
    if(temp->next == NULL)
    {
        head = temp;
        return;
    }

    reverse(temp->next);
    
    struct node* previous;
    previous = temp->next;
    previous->next = temp;
    temp->next = NULL;
}


