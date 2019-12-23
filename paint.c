#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
void main()
{
	int n,i,x,d; node *head=NULL,*curr,*tmp;
	printf("Enter the no. of elements: ");
	scanf("%d",&n);
	head=(node*)malloc(sizeof(node));
	curr=head;
	printf("Enter the values: ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		curr->data=x;
		if(i==n)	break;
		curr->next=(node*)malloc(sizeof(node));
		curr=curr->next;
	}curr->next=NULL;
	curr=head;
	do
	{
		printf("%d ",curr->data);
		curr=curr->next;
	}while(curr!=NULL);
	printf("\nEnter the value to be deleted: ");
	scanf("%d",&d);
	while(head!=NULL && head->data==d)
	{
		tmp=head;
		head=head->next;
		free(tmp);
	}
	for(curr=head;curr!=NULL;curr=curr->next)
	{
		while(curr->next!=NULL && curr->next->data==d)
		{
			tmp=curr->next;
			curr->next=tmp->next;
			free(tmp);
		}
	}
	curr=head;
	do
	{
		if(head==NULL)
		{
			printf("No values");
			break;
		}
		printf("%d ",curr->data);
		curr=curr->next;
	}while(curr!=NULL);
	getch();
}