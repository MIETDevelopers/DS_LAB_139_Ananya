#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

typedef struct node NODE;
NODE *top = NULL;

void push()
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data that you want to insert in the stack --> ");
    scanf("%d", &newnode->data);
    newnode->link = top;
    top = newnode;
}

void display()
{
    NODE *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("The elements in the stack are :-\n");
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
}

void pop()
{
    NODE *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Popped element is %d\n", temp->data);
        top = temp->link;
        free(temp);
    }
}

int main()
{
    int choice;
    do
    {
        printf("PLEASE SELECT ANY OF THE STACK OPERATION\n");
        printf("1.Push an element in the Stack \n");
        printf("2.Pop an element from the Stack\n");
        printf("3.Display the Elements of the Stack\n");
        printf("4.Exit the program\n");
        printf("Enter your choice --> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("INVALID CHOICE.....PLEASE TRY AGAIN\n");
            break;
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}