#include <stdio.h>
#include <stdlib.h>

// Stack
struct node
{
    int data;
    struct node *next;
};

// Top
struct node *top;

// Push
int push(int data)
{
    // Stack is empty
    if (top == NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        top = new;
    }

    // Stack is not empty
    else
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = top;
        top = new;
    }

    return 1;
}

// Display
int display()
{
    // Stack is empty
    if (top == NULL)
    {
        printf("Stack is empty");
        return 1;
    }

    struct node *index = top;
    while (index != NULL)
    {
        printf("%d - ", index->data);
        index = index->next;
    }

    printf("\n");

    return 1;
}

// Pop
int pop()
{
    // Stack is empty
    if (top == NULL)
    {
        printf("Stack is empty \n");
        return 1;
    }

    struct node *tmp = top;
    top = top->next;
    free(tmp);

    return 1;
}

int main()
{

    push(1);
    push(4);
    push(15);

    display();

    pop();
    display();

    return 1;
}