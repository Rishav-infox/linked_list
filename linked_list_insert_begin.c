#include <stdio.h>
#include <stdlib.h>

void insert(int);
void print();
struct node
{
    int data;
    struct node* next;
};

struct node *head;
int main(void)
{
    head = NULL;

    insert(4);
    insert(3);
    insert(5);
    print();

    return 0;
}

void insert(int input)
{
    struct node* temp = malloc(sizeof(struct node));

    temp->data = input;
    temp->next = head;
    head = temp;
}

void print()
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}



