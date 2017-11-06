#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
#include "menu.h"
#include <string.h>
#include <unistd.h>

void quit(int argc, char * argv[])
{
	int ret;
	while((ret = getopt(argc, argv, "a::b::"))!= -1)
	{
		switch(ret)
		{
			case'a':
			printf("命令行参数a方式退出！\n");
			break;
			case'b':
			printf("命令行参数b方式退出！\n");
			break;
			default:
			printf("正常退出,其他方式退出！\n");
			break;
		}
	}
	exit(0);

}

void add(int argc, char * argv[])
{
	double num1, num2, sum;
	printf("please input two numbers to add!\n");
	scanf("%lf %lf", &num1, &num2);
	sum = num1 + num2;
	printf("%lf + %lf = %lf\n", num1, num2, sum);
}

void mul(int argc, char * argv[])
{
	double num1, num2;
	double result;
	printf("Please input two numbers to multiple\n");
	scanf("%lf %lf", &num1, &num2);
	result = num1 * num2;
	printf("%lf - %lf = %lf\n", num1, num2, result);
}

void sub(int argc, char * argv[])
{
	double num1, num2;
	double result;
	printf("Please input two numbers to subtract!\n");
	scanf("%lf %lf", &num1, &num2);
	result = num1 - num2;
	printf("%lf - %lf = %lf\n", num1, num2, result);
}

void Div(int argc, char * argv[])
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

void squ(int argc, char * argv[])
{
	double num1;
	double result;
	printf("Please input a number to get its square!\n");
	scanf("%lf", &num1);
	result = num1 * num1;
	printf("%lf ^2 = %lf\n", num1, result);
}

void rem(int argc, char * argv[])
{
	int num1, num2;
	int result;
	printf("Please input two numbers to calculate the remainder!\n");
	scanf("%d %d", &num1, &num2);
	result = num1 % num2;
	printf("%d %% %d = %d\n", num1, num2, result);
}

int main(int argc, char * argv[])
{
	MenuConfig("add","addition of two numbers",add);
	MenuConfig("sub","subtraction of two numbers",sub);
	MenuConfig("mul","Multiplication of two numbers",mul);
	MenuConfig("div","Division of two numbers",Div);
	MenuConfig("squ","suqare of a number",squ);
	MenuConfig("rem","remainder of two numbers",rem);
	MenuConfig("quit","exit cmd",quit);
	ExecuteMenu();
	return 0;
}
