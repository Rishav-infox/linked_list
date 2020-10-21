#include <stdio.h>
#include <stdlib.h>

void insert(int,int);
void print();

struct node
{
    int data;
    struct node* next;
};

struct node* head;

int main(void)
{
    head = NULL;

    insert(4,1);
    insert(6,1);
    insert(8,1);
    print();
    return 0;
}

void insert(int input, int position)
{
    struct node* temp = malloc(sizeof(struct node));

    temp->data = input;

    if(position == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        struct node* temp1 = head;
        for(int i = 0; i < position - 2; i++)
        {
            temp1 = temp1->next;
        }
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
}
