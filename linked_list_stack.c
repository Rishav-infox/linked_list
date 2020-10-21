#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node* next;
};

struct node* top;



void push(int);
int pop();
bool is_empty();
struct node* getnode(int input);

int main(void)
{

    push(5);
    push(6);
    push(7);
    printf("%d ", pop());
    printf("%d ", pop());
    printf("%d ", pop());
    return 0;
}


bool is_empty()
{
    if(top == NULL)
        return true;
    return false;
}
struct node* getnode(int input)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = input;
    temp->next = NULL;
}

void push(int input)
{
    struct node* temp = getnode(input);

    if(is_empty())
    {
        top = temp;
        return;
    }

    temp->next = top;
    top = temp;
}

int pop()
{
    int popped;
    struct node* temp = top;
    if(is_empty())
    {
        printf("Underflow \n");
        return 0;
    }
    popped = temp->data;
    top = temp->next;
    free(temp);
    return popped;
}


