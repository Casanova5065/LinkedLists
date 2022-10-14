#include <stdio.h>
#include <malloc.h>

void InsertAtEnd(int);
void display(void);
// void PrintReverse(struct node *s);

struct node
{
    int data;
    struct node *next;
} * start;

void PrintReverse(struct node *s)
{
    struct node *current = s;
    if (current == NULL){
        return;
    }

    PrintReverse(s->next);
    printf("%d ", s->data);
}
int main(int argc, char const *argv[])
{
    InsertAtEnd(5);
    InsertAtEnd(4);
    InsertAtEnd(3);
    InsertAtEnd(2);
    InsertAtEnd(1);
    display();
    PrintReverse(start);
    return 0;
}

void InsertAtEnd(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node *current = start;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void display(void)
{
    struct node *current = start;
    while (current)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}