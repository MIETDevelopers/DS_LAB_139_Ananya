#include <stdio.h>
#include <stdlib.h>         //malloc and exit(0) means successful exit exit(1) means unsuccessful exit 
void enqueue(); // functions
void dequeue();
void display();
//creating node
struct node   //pointer stores address (user defined data)
{
    int data; 
    struct node *next; //*next means it stores address of next node
};
//creating head
typedef struct node node; //typedef helps to make new datatype

node *front = NULL; //front= delete
node *rear = NULL;  //rear = insert
int main()
{
    int ch;
    while (1) //infinite loop
    {
     printf("please choice from the following:\n");
        printf("1.Enqueue\n2.Dequeue\n3.display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
}
void enqueue()
{
    node *new; //pointer helps to store address and datatype
    int num;   
    new = (node *)malloc(sizeof(node));         // malloc allocate memory,memory always store in address form
    if (new == NULL)  
        printf("Unable to allocate the memory\n");  //node * typecasting = float= int example
    else
    {
        printf("Please Enter The Value\n");
        scanf("%d", &num);
        new->data = num;  //
        new->next = NULL;
        if (front == NULL && rear == NULL) //if case runs for 1st case only
        {
            front = rear = new;  // (front=head,rear=temp)front and rear stores the address of 1stnode
        }
        else
            rear->next = new;
        rear = new; // enters to second node (rear points last node) 
    }
}
void dequeue()//delete from first
{
    node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("Queue Is Empty\n");
    }
    else
    {
        printf("Dequeued Element:%d\n", front->data);
        front = front->next;//move to next
      free(temp);
    }
}
void display()
{
    node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("Queue Is Empty\n");
    }
    else
    {
        printf("Elements are:\n");
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}