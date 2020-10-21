#include <stdio.h>
#include <stdlib.h>
void insert(int);
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
    insert(4);
    insert(6);
    insert(8);
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
