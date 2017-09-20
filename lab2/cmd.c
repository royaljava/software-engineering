#include <stdio.h>
#include <stdlib.h>

void help()
{
	printf("this is help command!\n");    
}

void quit()
{
	exit(0);
}

void sleep()
{
	printf("this is sleep command!\n");
}

void play()
{
	printf("this is play command!\n");
}

void writeCode()
{
	printf("this is writeCode command!\n");
}

void readCode()
{
	printf("this is the readCode command!\n");
}

void kick()
{
	printf("this is the kick command!\n");
}

void wake()
{
	printf("this is the wake command!\n");
}

void errorinform()
{
	printf("wrong command!\n");
}

void  main()
{
	char cmd[128];
	while(1)
	{
		scanf("%s",cmd);
		int comp;
		if(comp=(strcmp(cmd,"help")==0))
		{
			help();
		}
		else if(comp=(strcmp(cmd,"quit")==0))
		{
			quit();
		}
		else if(comp=(strcmp(cmd,"sleep")==0))
		{
			sleep();
		}
		else if(comp=(strcmp(cmd,"play")==0))
		{
			play();
		}
		else if(comp=(strcmp(cmd,"writeCode")==0))
        {
            writeCode();
        }	
		else if(comp=(strcmp(cmd,"readCode")==0))
        {
            readCode();
        }
		else if(comp=(strcmp(cmd,"kick")==0))
        {
            kick();
        }
		else if(comp=(strcmp(cmd,"wake")==0))
        {
            wake();
        }
		else
		{
			errorinform();
		}

	}
}




