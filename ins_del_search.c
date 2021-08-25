//Author: Ananya gupta

#include<stdio.h>
#include<stdlib.h>
void insert(int []);
int view(int []);
int search(int []);
int del(int []);
int enter(int []);
int main()
{
    int a[40];
    int ch;
    int i, n;
    printf("Enter the size in an array: ");
    scanf("%d",&n);
    printf("\nEnter %d elements in an array:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(1){
        printf("\nEnter 1 to insert element in array.");
        printf("\nEnter 2 to view element in array.");
        printf("\nEnter 3 to search element in array.");
        printf("\nEnter 4 to Delete element in array.");
        printf("\nEnter 5 to re-enter element in array.");
        printf("\nEnter 6 to Exit.");
        printf("\n\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:insert(a);
                        break;
            case 2:view(a);
                        break;
            case 3:search(a);
                        break;
            case 4:del(a);
                        break;
            case 5:enter(a);
                        break;
            case 6:exit(0);
        }
    }
    return 0;
}

void insert(int a[20])
{
    int n,l,x,i;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    printf("\nEnter location to insert an element: ");
    scanf("%d",&l);
    printf("\nEnter element to be inserted: ");
    scanf("%d",&x);
    n=n+1;
    for(i=n-1;i>=l;i--){
        a[i]=a[i-1];
    }

    a[i]=x;
    printf("\nArray After insertion is\n: ");
    for(i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    a[i]='\0';
}

int view(int a[20])
{
    int j;
    for(j=0;a[j];j++)
    {
        printf("\nElement at index %d of array: %d", j, a[j]);
    }
    return 0;
}

int search(int a[40])
{
    int n, i, j;
    printf("Enter element to search: "); 
    scanf("%d",&j);
     
    for(i=0;i<n;++i)
        if(a[i]==j)
            break;
     
if(i<n){
        printf("Element %d found at index %d", j, i);
    }     
    else{
        printf("Element not found"); 
    }
    return 0;
}

int del(int a[40])
{
    int c,k,posi;
    for(k=0;a[k];k++)
    {
    }
    printf("\nEnter the position to delete element: ");
    scanf("%d",&posi);
    if(posi<=k)
    {
        for(c=posi-1;c<k-1;c++)
        {
            a[c]=a[c+1];
        }
        printf("\nArray after Deletion");
        for(c=0;c<k-1;c++)
        {
            printf("\n%d",a[c]);
        }
    }
    a[c]='\0';
    return 0;
}

int enter(int a[40])
{
    int i, n;
    printf("Enter the size in an array: ");
    scanf("%d",&n);
    printf("\nEnter %d elements in an array:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    a[i]='\0';
    return 0;
}