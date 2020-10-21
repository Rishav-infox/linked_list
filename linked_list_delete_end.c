#include <stdio.h>
#include <stdlib.h>

void insert(int);
void print();
void delete();

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
    print();
    delete();
    delete();
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
void delete()
{
    struct node* temp = head;
    if(head->next == NULL)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        struct node* temp1 = head;
        while(temp1->next != temp)
            temp1 = temp1->next;

        temp1->next = temp->next;
        free(temp);
    }
}







