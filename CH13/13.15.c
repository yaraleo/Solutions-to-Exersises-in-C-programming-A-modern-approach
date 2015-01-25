#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 100

char contents[N];
int top;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int num);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);
void operation(char);

int evaluate_RPN_expression(const char *expression);

int main()
{
	char expression[32];

	make_empty();

	printf("Enter an RPN expression: ");
	gets(expression);
	
	for(;;)
	{
		int result = evaluate_RPN_expression(expression);
		
		printf("Value of expression: %d\n", result);
		make_empty();
		printf("Enter another RPN expression: ");
		gets(expression);
	}
	
	
	return 0;
}

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == N;
}

void push(int num)
{
	if(is_full())
		stack_overflow();
	else
	{
		contents[top++] = num;
		//printf("%d is pushed\n", num);
	}
}

int pop(void)
{
	int num;
	if(is_empty())
		stack_underflow();

	num = contents[--top];
	//printf("%d is poped\n", num);
	return num ;

}

void stack_overflow(void)
{
	printf("Expression is too complex\n");
	exit (0);
}

void stack_underflow(void)
{
	printf("Not enough operands in expression\n");
	exit (0);
}

void operation(char ch)
{
	int first_num, second_num;
	first_num = pop();
	second_num = pop();

	switch(ch)
	{
		case '+': push(second_num + first_num);	break;
		case '-': push(second_num - first_num);	break;
		case '*': push(second_num * first_num); break;
		case '/': push(second_num / first_num);	break;
	}
}

int evaluate_RPN_expression(const char *expression)
{
	for(;;)
	{
			switch(*expression)
			{
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				case '0':		push(*expression++ - '0'); break;

				case '+':
				case '-':
				case '*':
				case '/':		operation(*expression++); break;

				case '=': 		return pop();
				
				default: {
			 		 		printf("\n\nBad operand/operator\nprogram terminated\n");
					 		exit (0);
					     }
			}

	}

}
