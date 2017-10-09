/*data struct and its operations */

typedef struct DataNode
{
	char* cmd;
	char* desc;
	void   (*handler)();
	struct DataNode *next;
} tDataNode;

/*find a cmd in the linklist and return the datanode point */
tDataNode* FindCmd(tDataNode * head, char * cmd);

/* show all cmd in linklist */
int ShowAllCmd(tDataNode * head);
