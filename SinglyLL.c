#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE head , int no)
{
	PNODE newn = NULL;
	
	newn =(PNODE)malloc(sizeof(NODE));
	
	newn->data = no;
	newn->next = NULL;

   if(*head == NULL)
   {
	   *head = newn;
   }	   
   else
   {
	   newn->next = *head;
	   *head = newn;
   }
}

void InsertLast(PPNODE head , int no)
{
	PNODE newn = NULL;
	
	newn =(PNODE)malloc(sizeof(NODE));
	
	newn->data = no;
	newn->next = NULL;

   if(*head == NULL)
   {
	   *head = newn;
   }	   
   else
   {
	   PNODE temp = *head;
	   
	   while(temp->next != NULL)
	   {
		   temp = temp->next;
	   }
	   temp->next = newn;
	   newn = temp;
   }
}

void DeleteFirst(PPNODE head)
{
	PNODE temp = NULL;
	
	if(*head == NULL)
	{
		return;
	}
	else
	{
		temp = *head;
		*head = temp->next;
		 free(temp);
	}
}

void DeleteLast(PPNODE head)
{
	PNODE temp = NULL;
	
	if(*head == NULL)
	{
		return;
	}
	else
	{
		 temp = *head;
		 
		 while(temp->next->next != NULL)
		 {
			 temp = temp->next;
		 }
		 free(temp->next);
		 temp->next = NULL;
	}	
		
}

void Display(PNODE head)
{
	PNODE temp = head;
	do
	{
		printf("|  %d  |->",temp->data);
		temp = temp->next;
	}while(temp != NULL);
	printf("NULL\n");
}
int Count(PNODE head)
{
	PNODE temp = head;
	int iCnt = 0;
	do
	{
		iCnt++;
		temp = temp->next;
	}while(temp != NULL);
	
	return iCnt;
}

void InsertAtPos(PPNODE head , int no ,int Pos)
{
	int size = 0;
	size = Count(*head);
	PNODE temp = *head;
	
	if((Pos<1)  || (Pos>(size + 1)))
	{
		return;
	}
	if(Pos == 1)
	{
		InsertFirst(head,no);
	}
	else if(Pos == (size + 1))
	{
		InsertLast(head,no);
	}
	else
	{
		PNODE newn = NULL;
		
		newn = (PNODE)malloc(sizeof(NODE));
		
		newn->data=no;
		newn->next=NULL;
		
		temp = *head;
		int iCnt = 0;
		
		for(iCnt = 1 ; iCnt < size - 1 ; iCnt++)
		{
			temp = temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	}
}

void DeleteAtPos(PPNODE head , int no ,int Pos)
{
	int size = 0;
	size = Count(*head);
	PNODE temp = *head;
	PNODE template = NULL;
	
	if((Pos<1)  || (Pos>(size + 1)))
	{
		return;
	}
	if(Pos == 1)
	{
		DeleteFirst(head);
	}
	else if(Pos == (size))
	{
		DeleteLast(head);
	}
	else
	{
		
		temp = *head;
		int iCnt = 0;
		
		for(iCnt = 1 ; iCnt < Pos - 1 ; iCnt++)
		{
			temp = temp->next;
		}
		 template = temp->next;
		 temp->next = temp->next->next->next;
		free(template);
	}
}

int main()
{
	PNODE first = NULL;
	int iRet = 0;
	
	InsertFirst(&first , 11 );
	InsertFirst(&first , 21 );
	InsertFirst(&first , 31 );
	InsertFirst(&first , 41 );
	Display(first);
	iRet = Count(first);
	printf("Number of Elelments are:%d\n",iRet);
	
	InsertFirst(&first , 51 );
	Display(first);
	iRet = Count(first);
	printf("Number of Elelments are:%d\n",iRet);
	
	InsertLast(&first , 61 );
	Display(first);
	iRet = Count(first);
	printf("Number of Elelments are:%d\n",iRet);
	
	DeleteFirst(&first);
	Display(first);
	iRet = Count(first);
	printf("Number of Elelments are:%d\n",iRet);
	
	DeleteLast(&first);
	Display(first);
	iRet = Count(first);
	printf("Numberssss of Elelments are:%d\n",iRet);
	
	InsertAtPos(&first , 38 , 2);
	Display(first);
	iRet = Count(first);
	printf("Numberssss of Elelments are:%d\n",iRet);
	
	DeleteAtPos(&first , 38 , 2);
	Display(first);
	iRet = Count(first);
	printf("Numberssss of Elelments are:%d\n",iRet);
	return 0;
}