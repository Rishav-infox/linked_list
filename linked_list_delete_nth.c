#include <stdio.h>
#include <stdlib.h>

void insert(int);
void print();
void delete(int);

struct node
{
    int data;
    struct node* next;
};

struct node* head;
int main(void)
{
    head = NULL;
    insert(3);
    insert(5);
    insert(6);
    insert(8);
    insert(2);
    print();
    delete(2);
    delete(3);
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
    printf("\n");
}
void delete(int position)
{
    struct node* temp = head;
    if(position == 1)
    {
        head = temp->next;
        free(temp);
    }
    else
    {
        struct node *temp1 = head;

        for(int i = 0; i < position - 2; i++)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
}


