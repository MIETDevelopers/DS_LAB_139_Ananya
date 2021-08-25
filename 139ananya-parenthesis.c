//A C program to check whether a expression is correctly paranthesized or not.                 

#include<stdio.h>
#include<stdlib.h>
int main()
{
    char str[100];                //str[100] is the 99th character of the string.
    int i=0, j, check, count;
    printf("Enter Expression: ");
    gets(str);               //This will read the expression entered by user and store it in the string.
    while(str[i]!='\0')       //'\0'is null character with zero value.(ASCII value)
    {
        check=0;
        if(str[i]=='('||str[i]==')'||str[i]=='{'||str[i]=='}'||str[i]=='['||str[i]==']')
        {
          //This will count the number of times a Parenthesis is entered.      
          count++;
        }
       i++;
    }
    if(count%2==0)     
     
      printf("\nExpression is Valid!");
    else
      printf("\nExpression is Invalid!");
    exit(0);
    return 0;
}



//A Parenthesis is opened and closed like (), i.e., we need a pair of parenthesis
//that is why even number makes a valid/correct expression.