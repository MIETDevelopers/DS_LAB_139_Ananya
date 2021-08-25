#include<stdio.h>
#include<ctype.h>			//task is to check if a character is uppercase, lowercase, hexadecimal digit and more...
#include<stdlib.h>

#define MAX_operand 20		//#define creates a macro.
#define MAX_operator 20		//macro to define MAX OPERAND and OPERATOR resp.

int top_operand=-1;
int top_operator=-1;

int operand_stack[20];
char operator_stack[10];

void push_operand(int);			//push operator and operand
void push_operator(char);

int pop_operand();				//pop operator and operand
char pop_operator();

void operand_display();			//display operator and operand
void operator_display();

int evaluation();
int main()
{
int number;
char expr[20],digit;
printf("Enter any expression");			//expression= (1+2[7*4])   ex
scanf("%[^\n]s",expr);
printf("Expression  = %s\n",expr);		//it will show the expression we've printed
for(int i=0;expr[i]!='\0';i++)
{
digit=expr[i];
if(isdigit(digit))				//isdigit= It is used to check whether the entered character is a numeric character [0 – 9] or not.
{
number=digit-'0'; 		//1+2*3
push_operand(number);				//push OPERAND= NUMBER
}
else
{
push_operator(digit);				//push OPERATOR= DIGIT
}



}
operand_display();
operator_display();
printf("\nexpression after evaluation = %d\n\n",evaluation());
}
void push_operand(int operand)			//push OPERAND
{
if(top_operand==MAX_operand-1)			//if   top=max-1
{
printf("Stack Overflow");									//stack overflow
}
else									//else   top=top+1
{
top_operand=top_operand+1;
operand_stack[top_operand]=operand;		
}
}
void push_operator(char digit)			//push OPERATOR
{
if(top_operator==MAX_operator-1)		//top=max-1
{
printf("Stack Overflow");									//stack overflow
}
else									//top=top+1
{
top_operator=top_operator+1;
operator_stack[top_operator]=digit;
}



}
int pop_operand()				//pop OPERAND
{
int operand;
if(top_operand==-1)					// TOP==-1
{
printf("No operand in stack\n");					//NO OPERAND IN THE STACK
exit(0);
}
else								//OPRND=OPRND*TOP
{
operand=operand_stack[top_operand];
top_operand--;
}
return operand;
}


char pop_operator()				//pop OPERATOR
{
char operator;
if(top_operator==-1)				//TOP==-1
{
printf("No operator in stack\n");				//NO OPERATOR IN THE STACK
exit(0);
}
else								//OPRTR=OPRTR*TOP
{
operator=operator_stack[top_operator];
top_operator--;
}
return operator;



}
void operand_display()				//display OPERAND
{
if(top_operand==-1)						//TOP==-1
{
printf("No operand in Stack\n");						//NO OPERAND IN THE STACK
}
else
{
printf("Operands in the stack are\n");		//OPERAND IN STACK
for(int i=top_operand;i>-1;i--)
{											//TOP>-1
printf("%d\t",operand_stack[i]);
}
printf("\n");
}


}
void operator_display()				//display OPERATOR
{
if(top_operator==-1)					//TOP==-1
{
printf("No operator in Stack\n");						//NO OPERATOR IN THE STACK
}
else
{
printf("Operator in the stack are\n");		//OPERATOR IN STACK
for(int i=top_operator;i>-1;i--)
{												//TOP>-1
printf("%c\t",operator_stack[i]);
}
printf("\n");
}



}
int evaluation()											//EVALUATION
{
int operand_1, operand_2,result;
char operator;
if(top_operand==-1)										//IF  TOP==-1
{														//THEN,  NO MORE OPERATOR IN STACK
printf("no more operator in stack");
exit(0);
}
else
{														//ELSE   TOP>-1
for (int i = top_operator; top_operator > -1; i++)
{
operator=pop_operator();
operand_1=pop_operand();
operand_2=pop_operand();
if(operator=='+')							//   +
{										    // OP1  +  OP2
result=operand_1+operand_2;					
}
else if(operator=='-')						//  -
{											// OP1  -  OP2
result=operand_1-operand_2;
}
else if(operator=='*')						// * 
{											// OP1  *  OP2
result=operand_1*operand_2;
}
else if(operator=='/')						//  /
{											// OP2  /  OP1
result=operand_2/operand_1;
}
else
{
printf("Undefined Operator\n");				//UNDEFINED OPERATOR
}
push_operand(result);
}
}
return operand_stack[0];
}