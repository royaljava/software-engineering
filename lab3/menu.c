#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

#define CMD_MAX_LEN 128;
#define DESC_LEN    1024;
#define CMD_NUM     10;

void help()
{
	printf("---------------------------------------------\n");
	printf("---------------------------------------------\n");
	printf("|help   + cmd tips                           \n");
	printf("|add    + addition of two numbers.           \n");
	printf("|sub    + subtraction of two numbers.        \n");
	printf("|mul    + Multiplication of two numbers.     \n");
	printf("|div    + Division of two numbers.           \n");
	printf("|squ    + suqare of a number.                \n");
	printf("|rem    + remainder of two numbers.          \n");
	printf("|quit   + exit cmd.                          \n");
	printf("---------------------------------------------\n");
}

void quit()
{
	exit(0);
}

void add()
{
	double num1, num2, sum;
	printf("please input two numbers to add!\n");
	scanf("%lf %lf", &num1, &num2);
	sum = num1 + num2;
	printf("%lf + %lf = %lf\n", num1, num2, sum);
}

void mul()
{
	double num1, num2;
	double result;
	printf("Please input two numbers to multiple\n");
	scanf("%lf %lf", &num1, &num2);
	result = num1 * num2;
	printf("%lf - %lf = %lf\n", num1, num2, result);
}

void sub()
{
	double num1, num2;
	double result;
	printf("Please input two numbers to subtract!\n");
	scanf("%lf %lf", &num1, &num2);
	result = num1 - num2;
	printf("%lf - %lf = %lf\n", num1, num2, result);
}

void Div()
{
	double num1, num2;
	double result;
	printf("Please input two numbers to get the quotient!\n");
	scanf("%lf %lf", &num1, &num2);
	if (num2 == 0)
	{
		printf("Error: divisor can not be zero!\n");
	}
	else
	{
		result = num1 / num2;
		printf("%lf / %lf = %lf\n", num1, num2, result);
	}
}

void squ()
{
	double num1;
	double result;
	printf("Please input a number to get its square!\n");
	scanf("%lf", &num1);
	result = num1 * num1;
	printf("%lf ^2 = %lf\n", num1, result);
}

void rem()
{
	int num1, num2;
	int result;
	printf("Please input two numbers to calculate the remainder!\n");
	scanf("%d %d", &num1, &num2);
	result = num1 % num2;
	printf("%d %% %d = %d\n", num1, num2, result);
}

void errorinform()
{
	printf("wrong command!\n");
}

static tDataNode head[] =
{
	{"help", "this is help cmd!", help,&head[1]},
	{"add", "this is add cmd!", add, &head[2]},
	{"sub", "this is sub cmd!", sub, &head[3]},
	{"mul", "this is mul cmd!", mul, &head[4]},
	{"div", "this is div cmd!", Div, &head[5]},
	{"squ", "this is squ cmd!", squ, &head[6]},
	{"rem", "this is rem cmd!", rem, &head[7]},
	{"quit", "this is quit cmd!", quit, NULL}
};

int main()
{
	/*cmd line begins */
	while(1)
	{
		char cmd[128];
		printf("Input a cmd number > ");
		scanf("%s", cmd);
		tDataNode *p = head;
		while(p != NULL)
		{
			if(strcmp(p->cmd, cmd) == 0)
			{
				printf("%s - %s\n", p->cmd, p->desc);
				if(p->handler != NULL)
				{
					p->handler();
				}
				break;
			}
			p = p->next;
		}
		if(p == NULL)
		{
			printf("This is a wrong cmd!\n ");
		}


	}

}
