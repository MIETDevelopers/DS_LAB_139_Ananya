//A C Program to Implement a Singly Linked List and develop functions to perform insertion, deletion and linear search operations.

#include<stdlib.h>
#include <stdio.h>

//function prototype
void insert();
void delete();
void display();

int count=0; 
 
//creating node
struct node
{
        int data;
        struct node *next;
};

//creating head
struct node *head=NULL;
int main()     
{
        int choice;
        while(1){
               
                printf("\n~Singly Linked List Operation~");
                printf("\n 1. Insert a node.");
                printf("\n 2. Delete a node");
                printf("\n 3. Display all nodes");
                printf("\n 4. Exit the program.");
                printf("\n Enter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                            printf("\n~Implementing insert function!~\n");
                            printf("Number of nodes available: %d", count);
                            insert();
                            count++;
                            break;
                    case 2:
                            printf("\n~Implementing delete function!~\n");
                            printf("Number of nodes available: %d", count);
                            delete();
                            count--;
                            break;
                    case 3:
                            printf("\n~Implementing display function!~\n");
                            printf("\nNumber of nodes available: %d", count);
                            display();
                            break;    
                    case 4:
                            printf("Exiting the program!");
                            exit(0);
                            break;
                    default:
                            printf("n Wrong Choice:n");
                            break;
                }
        }
        return 0;
}

void insert()                                                           //creating two pointer variables to hold adresses for nodes, 
                                                                        //first node (*ptr) to hold data and 
                                                                        //second node (*temp) for address traversal 
{
        struct node *ptr,*temp;                 //struct: temporary var.....local var: temp & ptr
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));                //to allocate memory, stored in temp, temp contains node address
        if(temp==NULL)  
        {
                printf("\nOut of Memory Space! :/ ");
                return;
        }
        printf("\nEnter the index value for the new node to be inserted: ");
        scanf("%d",&pos);
        printf("\nEnter the value of the node: ");
        scanf("%d",&temp->data) ;                       //temp to data address (location to read d value)
  
        temp->next=NULL;                        //reading info: null value is being stored in the next.
        if(pos==0)              //list is empty
        {
                temp->next=head;
                head=temp;              //temp value is being assigned to head
        }
        else
        {
                for(i=0,ptr=head;i<pos-1;i++) 
                        { 
                        ptr=ptr->next;
                        if(ptr==NULL)           //ptr=null...it will stop
                        {
                                printf("\nPosition not found! :/");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}

void delete()
{
        int i,pos;                      //POS=POSITION
        struct node *temp,*ptr;
        if(head==NULL)
        {
                printf("\nThe List is Empty! :/");
                exit(0);
        }
        else
        {
                printf("\nEnter the index value of the node to be deleted: ");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=head;
                        head=head->next ;
                        printf("\nThe deleted node is: %d",ptr->data );
                        free(ptr);
                }
                else
                {
                        ptr=head;
                        for(i=0;i<pos;i++) { 
                            temp=ptr; 
                            ptr=ptr->next;
                                if(ptr==NULL)
                                {
                                        printf("\nNode not found :/");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted node is: %d",ptr->data);
                        free(ptr);
                }
        }
}

void display()
{
        struct node *ptr;
        if(head==NULL)
        {
                printf("\nList is empty! :/");
                return;
        }
        else
        {
                ptr=head;
                printf("The nodes in the elements are: ");
                while(ptr!=NULL)
                {
                        printf(" %d,",ptr->data );
                        ptr=ptr->next ;
                }
        }
}

