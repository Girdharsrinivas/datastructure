#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
}*start=NULL;
void insertbeg()
{
	struct node *nn;
	int a;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&nn->data);
	a=nn->data;
	nn->next=nn->prev=NULL;
	if(start==NULL)
	{
		printf("\ndll is empty,so new node inserted as start node");
		start=nn;
	}
	else
	{
		nn->next=start;
		start->prev=nn;
		start=nn;
	}
	printf("\n %d sucessfully inserted\n",a);
}
void insertend()
{
	struct node *nn,*t;
	int b;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("\n enter data:");
	scanf("%d",&nn->data);
	b=nn->data;
	nn->next=nn->prev=NULL;
	if(start==NULL)
	{
		printf("\n dll is empty,so new node inserted as start node\n");
		start=nn;
	}
	else
	{
		t=start;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=nn;
		nn->prev=t;
	}
	printf("%d is sucessfully inserted \n",b);
}
void insertmid()
{
	struct node*nn,*t=start;
	int x,v;
	nn=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		printf("dll is empty\n");
		return;
	}
	printf("\n enter data:");
	scanf("%d",&nn->data);
	v=nn->data;
	nn->next=NULL;
	nn->prev=NULL;
	printf("enter data after which no. is to be inserted\n");
	scanf("%d",&x);
	while(t!=NULL&&t->data!=x)
	{
		t=t->next;
	}
	if(t==NULL)
	{
		printf("\n data does not exist\n");
		return;
	}
	else
	{
		if(t->next==NULL)
		{
			t->next=nn;
			nn->prev=t;
		}
		else
		{
			t->next->prev=nn;
			nn->prev=t;
			nn->next=t->next;
			t->next=nn;
		}
		printf("%d is sucessfully inserted\n",v);
	}
}
void deletebeg()
{
	struct node *t=start;
	if(start==NULL)
	{
		printf("\n dll is empty");
		return;
	}
	else
	{
		if(start->next==NULL)
		{
			start=NULL;
		}
		else
		{
			start=start->next;
			t->next=NULL;
			start->prev=NULL;
		}
	}
	printf("\n %d is sucessfully deleted",t->data);
	free(t);
}
void deleteend()
{
	struct node *t=start;
	int x;
	if(start==NULL)
	{
		printf("\n dll is empty");
		return;
	}
	else
	{
		if(start->next==NULL)
		{
			start=NULL;
			printf("dll contains only one element and %d is deleted",t->data);
			free(t);
		}
		else
		{
			while(t->next!=NULL)
			{
				t=t->next;
			}
			t->prev->next=NULL;
			t->prev=NULL;
			printf("\n %d is sucessfully deleted",t->data);
			free(t);
		}
	}
}
void deletemid()
{
	struct node *t=start;
	int x;
	if(start==NULL)
	{
		printf("\n dll is empty");
		return;
	}
	else
	{
		if(start->next=NULL)
		{
			start=NULL;
			printf("dll contains only one element and %d is deleted",t->data);
		}
		else
		{
			printf("enter data to be deleted:");
			scanf("%d",&x);
			while(t!=NULL&&t->data!=x)
			{
				t=t->next;
			}
			if(t==NULL)
			{
				printf("\n data does not exist",x);
			}
			else
			{
				if(t->next==NULL)
				{
					printf("\n deleted first element in dll");
					deletebeg();
					return;
				}
				else
				{
					t->prev->prev=t->next;
					t->next->prev=t->prev;
					t->next->prev=NULL;
				}
				printf("\n %d is sucessfully deleted",t->data);
				free(t);
			}
		}
	}
}
void display()
{
	struct node *t;
	if(start==NULL)
	{
		printf("dll is empty\n");
		return;
	}
	printf("elements are:\n");
	t=start;
	while(t!=NULL)
	{
		printf("<-->%d",t->data);
		t=t->next;
	}
}
int main()
{
	int c,a;
	do
	{
		printf("\n1.insert\n2.de lete\n3.display\n4.exit");
		printf("\n enter choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("1.insert at beg\n2.insert at end\n3.insert at mid");
				printf("\n enter choice:");
				scanf("%d",&a);
				switch(a)
				{
					case 5:insertbeg();break;
					case 6:insertend();break;
					case 7:insertmid();break;
				}
				break;
			case 2:
				printf("1.delete at beg\n2.delete at end\n3. delete at mid");
				printf("\n enter choice:");
				scanf("%d",&a);
				switch(a)
				{
					case 7:deletebeg();break;
					case 8:deleteend();break;
					case 9:deletemid();break;
				}
				break;
			case 3:display();
			break;
			case 4:printf("program ends\n");
			break;
			default:printf("wrong choice\n");
			break;
		}
	}while(c!=4);
}