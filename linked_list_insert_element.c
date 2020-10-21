#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head;

void insert(int);
void print();
void add(int);

int main(void)
{
    head = NULL;
    insert(2);
    insert(3);
    insert(4);
    insert(6);
    insert(8);
    insert(10);
    print();
    add(1);

    return 0;
}

void add(int input)
{
    struct node* temp1 = head, temp = malloc(sizeof(struct node));
    int index = 0;
    temp->data = input;

    while(temp->data <= input && temp->next != NULL)
    {
        temp = temp->next;
        ++index;
    }
    if(index == 0)
    {
        temp-next = head;
        head = temp;
        return;
    }
    struct node* temp2 = head;
    printf("index: %d\n", index);

    /*
    for(int i = 1; i < index; i++)
        temp1 = temp1->next;

        */
    printf("%d", temp2->data);
}


void insert(int input)
{
    struct node* temp = malloc(sizeof(struct node));

    temp->data = input;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        return;
    }
    struct node* temp1 = head;

    while(temp1->next != NULL)
        temp1 = temp1->next;

    temp1->next = temp;
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
