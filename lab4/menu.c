#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkTable.h"

typedef struct DataNode
{
    tLinkTableNode *next;
    char *cmd;
    char *desc;
    void(*handler)();
} tDataNode;

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

void InitMenuData(tLinkTable ** ppLinktable)
{
    *ppLinktable=CreateLinkTable();
    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode->cmd = "help";
	pNode->desc = "Menu List";
	pNode->handler = help;
	AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);

	pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode->cmd = "add";
	pNode->desc = "addition of two numbers";
	pNode->handler= add;
	AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);

	pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode->cmd = "sub";
	pNode->desc = "subtraction of two numbers";
	pNode->handler= sub;
	AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);

	pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode->cmd = "mul";
	pNode->desc = "Multiplication of two numbers";
	pNode->handler= mul;
	AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);

	pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode->cmd = "div";
	pNode->desc = "Division of two numbers";
	pNode->handler= Div;
	AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);

	pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode->cmd = "squ";
	pNode->desc = "suqare of a number";
	pNode->handler= squ;
	AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);

	pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode->cmd = "rem";
	pNode->desc = "remainder of two numbers";
	pNode->handler= rem;
	AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);

	pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode->cmd = "quit";
	pNode->desc = "exit cmd";
	pNode->handler= quit;
	AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);

}

tDataNode * FindCmd(tLinkTable *pLinkTable, char *cmd)
{
	tDataNode * pNode = (tDataNode *)GetLinkTableHead(pLinkTable);
	while(pNode != NULL)
	{
		if(strcmp(pNode->cmd,cmd) ==0)
		{
			return pNode;
		}
		pNode =(tDataNode*)GetNextLinkTableNode(pLinkTable,(tLinkTableNode*)pNode);
	}
	return NULL;
}
tLinkTable * head = NULL;

void main()
{
	InitMenuData(&head);
	tDataNode * p;
	help();
	/* cmd line begins */
	while(1)
	{
		char cmd[128];
		printf("Input a cmd number > ");
		scanf("%s",cmd);
		tDataNode *p = FindCmd(head, cmd);
		if( p == NULL)
		{
			printf("This is a wrong cmd!\n");
			continue;
		}
		printf("%s - %s\n", p->cmd, p->desc);
		if(p->handler !=NULL)
		{
			p->handler();
		}
	}
}



