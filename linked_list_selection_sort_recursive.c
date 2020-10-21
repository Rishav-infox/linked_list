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
int calElem(struct node* temp);
void selection_sort(struct node*);
void ops(struct node* min);
void swap(struct node* s, struct node* min);

int main(void)
{
    int input;
    head = NULL;

    while(1)
    {
        scanf("%d", &input);
        if(input > -1)
        {
            insert(input);
        }
        else 
            break;
    }
    print();
    selection_sort(head);
    print();
    return 0;
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

void selection_sort(struct node* min)
{
    if(min != NULL)
    {
        ops(min);
        selection_sort(min->next);
    }
}

void ops(struct node* min)
{
    struct node *small = min, *track = min;


    while(track)
    {
        if(track->data < small->data)
        {
            small = track;
        }
        track = track->next;
    }
    swap(small,min);
}



void swap(struct node* s, struct node* min)
{
    int temp = s->data;

    printf("swapping %d with %d\n", s->data, min->data);
    s->data = min->data;
    min->data = temp;
}


int calElem(struct node* temp)
{
    int size = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}
    

