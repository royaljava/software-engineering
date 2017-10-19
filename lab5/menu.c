
/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Mengning                                                             */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/08/31                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning, 2014/08/31
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
#include <string.h>
#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

/* data struct and its operations */
typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    void    (*handler)();
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

int SearchCondition(tLinkTableNode * pLinkTableNode,void *args)
{
    char * cmd=(char*)args;
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if(strcmp(pNode->cmd, cmd) == 0)
    {
        return  SUCCESS;
    }
    return FAILURE;
}

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    return  (tDataNode*)SearchLinkTableNode(head,SearchCondition,cmd);
}

/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

int InitMenuData(tLinkTable ** ppLinktable)
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

    return 0;
}

/* menu program */

tLinkTable * head = NULL;

int main()
{
    InitMenuData(&head);
    help();
   /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc);
        if(p->handler != NULL)
        {
            p->handler();
        }

    }
}


