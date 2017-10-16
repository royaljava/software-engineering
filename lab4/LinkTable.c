#include <stdio.h>
#include <stdlib.h>
#include "LinkTable.h"

tLinkTable * CreateLinkTable()
{
    tLinkTable*pLinkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    tLinkTableNode *pNode=(tLinkTableNode*)malloc(sizeof(tLinkTableNode));
     pNode->next = NULL;
     pLinkTable->pHead=pNode;
     pLinkTable->pTail=pNode;
     pLinkTable->SumOfNode=0;
     return pLinkTable;
}

int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
    if(pLinkTable->SumOfNode == 0)
    {
        pLinkTable->pHead = pNode;
    }
    pLinkTable->pTail->next = pNode;
    pLinkTable->pTail=pNode;
    pLinkTable->SumOfNode++;
    return 0;
}

tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable)
{
    return pLinkTable->pHead;
}

tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode * pNode)
{
    return pNode->next;
}
