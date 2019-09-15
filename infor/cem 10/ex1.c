#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node
{
	char *word;
	int count;
	struct Node *left;
	struct Node *right;
}node;
char *strcopy(char *s)
{
	char *p=(char*)malloc(strlen(s)+1);
	if(p!=NULL)
	{
		strcpy(p,s);
	}
	return p;
}
void treeprintASC(node *p)
{
	if(p!=NULL)
	{
		treeprintASC(p->left);
		printf("%d %s\n",p->count,p->word);
		treeprintASC(p->right);
	}
}
void treeprintDESC(node *p)
{
	if(p!=NULL)
	{
		treeprintDESC(p->right);
		printf("%d %s\n",p->count,p->word);
		treeprintDESC(p->left);
	}
}
node *addtree(node *p,char *w)
{
	int cond;
	if(p==NULL)
	{
		p=malloc(sizeof(node));
		p->word=w;
		p->count=1;
		p->left=NULL;
		p->right=NULL;
	}
	else if((cond=strcmp(w,p->word))==0)
	{
		p->count++;
	}
	else if(cond<0)
	{
		p->left=addtree(p->left,w);
	}
	else
	{
		p->right=addtree(p->right,w);
	}
	return p;
}
int main()
{
	int i=0;
	char *word,choose[5];
	scanf("%s",choose);
	node *root=NULL;
	FILE *fp;
	fp=fopen("1.txt","r");
	char getword[100],c;
	while((c=getc(fp))!=EOF)
	{
		if(c=='\n')
		{
			if(i>0)
			{
				getword[i]='\0';
				root=addtree(root,strcopy(getword));
			}	
			i=0;	
		}
		else
		{
			getword[i]=c;
			i++;
		}
	}
	fclose(fp);
	if(strcmp(choose,"ASC")==0)
	{
		treeprintASC(root);
	}
	else if(strcmp(choose,"DESC")==0)
	{
		treeprintDESC(root);
	}
}
