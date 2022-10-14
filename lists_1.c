#include <stdio.h>
#include <stdlib.h>

void InsertAtBegin(int);
void InsertAtEnd(int);
void InsertAtPosition(int, int);
void DeleteAtBegin(void);
void DeleteAtEnd(void);
void DeleteAtPosition(int);
void display(void);

struct node
{
    int data;
    struct node *next;
} * start;

int main()
{
    InsertAtEnd(3);
    InsertAtEnd(6);
    InsertAtEnd(2);
    InsertAtEnd(1);
    display();
    DeleteAtPosition(1);
    display();

    return 0;
}


void InsertAtBegin(int value)
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
        temp->next = start;
        start = temp;
    }
}

void DeleteAtBegin(void)
{
    struct node *current = start;
    if(current == NULL){
        printf("[-] Cannot Delete from an empty list !!\n");
        return;
    }
    start = start->next;
    free(current);
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

void DeleteAtEnd(void)
{
    struct node *current = start;
    struct node *prev;
    if(current == NULL){
        printf("[-] Cannot Delete from an empty list !!\n");
        return;
    }
    while(current->next != NULL){
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
}

void InsertAtPosition(int pos, int value)
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
        struct node *prev, *current = start;

        if (pos == 0)
        {
            InsertAtBegin(value);
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                prev = current;
                current = current->next;
            }
            prev->next = temp;
            temp->next = current;
        }
    }
}

void DeleteAtPosition(int pos)
{
    if(start == NULL){
        printf("[-] Cannot Delete from an empty list !!\n");
        return;
    }
    else{
        struct node *prev, *current = start;
        if(pos == 0){
            DeleteAtBegin();
        }
        else{
            for(int i = 0; i < pos; i++){
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            free(current);
        }
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