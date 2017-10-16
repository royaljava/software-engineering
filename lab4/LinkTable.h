#include <pthread.h>

#define SUCCSEE 0
#define FAILURE (-1)

/* LinkTable Node Type */
typedef struct LinkTableNode
{
	struct LinkTableNode * next;
}tLinkTableNode;

/* LinkTable Type */
typedef struct LinkTable
{
	tLinkTableNode *pHead;
	tLinkTableNode *pTail;
	int        SumOfNode;
    pthread_mutex_t mutex;
}tLinkTable;

/* Create a LinkTable */
tLinkTable * CreateLinkTable();

/* Delete a LinkTable */
int DeleteLinkTable(tLinkTable *pLinkTable);

/* Add a LinkTableNode to LinkTable*/
int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);

/* Delete a LinkTableNode from LinkTable */
int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);

/* get LinkTableHead */
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable);

/* get next LinkTableNode */
tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);

