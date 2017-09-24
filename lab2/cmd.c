#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

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
	int num1, num2;
	double result;
	printf("Please input two numbers to get the quotient!\n");
	scanf("%d %d", &num1, &num2);
	if (num2 == 0)
	{
		printf("Error: divisor can not be zero!\n");
	}
	else
	{
		result = num1 / num2;
		printf("%d / %d = %lf\n", num1, num2, result);
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

void  main()
{
	char cmd[128];
	while (1)
	{
		scanf("%s", cmd);
		int comp;
		if (comp = (strcmp(cmd, "help") == 0))
		{
			help();
		}
		else if (comp = (strcmp(cmd, "quit") == 0))
		{
			quit();
		}
		else if (comp = (strcmp(cmd, "add") == 0))
		{
			add();
		}
		else if (comp = (strcmp(cmd, "sub") == 0))
		{
			sub();
		}
		else if (comp = (strcmp(cmd, "mul") == 0))
		{
			mul();
		}
		else if (comp = (strcmp(cmd, "div") == 0))
		{
			Div();
		}
		else if (comp = (strcmp(cmd, "squ") == 0))
		{
			squ();
		}
		else if (comp = (strcmp(cmd, "rem") == 0))
		{
			rem();
		}
		else
		{
			errorinform();
		}

	}
}



