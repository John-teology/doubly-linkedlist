#include<stdio.h>
#include<stdlib.h>
struct node *head = NULL;			

struct node
{
	int data;
	struct node *left;
	struct node *right;	
};
void addloc(int loc,int data)
{									
	int ctr,jump=1;
	struct node *temp,*p;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left = NULL;
	temp->right = NULL;
	ctr= loc-1;
	p=head;
	while(jump < ctr )
	{
		p=p->right;
		jump++;
	}
	temp->right = p->right;							
	p->right->left = temp;						
	temp->left = p;								
	p->right = temp;								
}
void replacethehead(int data)
{
	struct node *temp;					
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left = NULL;
	temp->right = NULL;						
	temp->right = head;							
	head->left = temp;							
	head = temp;								
}

void append(int data)
{
	struct node *temp,*p;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left = NULL;
	temp->right = NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		struct node *p;
		p=head;
		while(p->right != NULL)
		{
			p=p->right;
		}
		p->right = temp;
		temp->left = p;	
	}	
}

int length()
{
	struct node *temp = head;
	int count = 0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->right;
	}
	return count;	
}

void display()
{
	struct node *t = head;
	if (t != NULL)
	{	
		while(t != NULL)
		{
			printf("%d->",t->data);
			t=t->right;
		}	
	}
	else
		printf(" ITS EMPTY!");
				
}

void specific(int loc,int data)
{
	int len=0;
	len = length();
	if(loc > len)
	{
		append(data);
	}
	else
	{
		if(loc!=1)
			addloc(loc,data);
			
		else
			replacethehead(data);
				
	}	
}

int find(int value)
{
	
	struct node *p=head;
	while(p != NULL && p->data != value)
        p = p->right;
    return p;
}

 
void deletenode(int loc)
{
	struct node *p=head;
	int ctr,jump=1;
	if(loc!=1)
	{
		while(jump < loc )
		{
			p=p->right;
			jump++;
		}
		if(p->right==NULL)		// this will check if it is the only node 
		{
			p->left->right = NULL;
			free(p);
		}
		else			// eto is if asa middle
		{
			p->left->right = p->right;
			p->right->left = p->left;
			free(p);	
		}	
	}
	else 				//eto namna if asa unahan
	{
		
		if(p->right == NULL)		//eto  if isa lang yung node tapos dedelete
		{
			head = NULL;
			free(p);	
		}
		
		else 
		{		
			head = p->right;        // eto naman is if may more than 1 na laman then dedelete mo yun unahan
			p->right->left = head;
			p->right = NULL;
			free(p);
		}	
	}	
}
void first()
{
	printf("SOME OPERATIONS IN DOUBLY LINKED LIST");
	printf("\n\n1. APPEND\n2. DELETE\n3. FIND\n4. DISPLAY\n5. QUIT\n\n");
}
int main()
{
	int loc=0;
	int ch,val,data,len;
	int f=0;
	first();
	while(ch!=6)
	{
		switch(getch())
		{
			case '1':
				printf("Enter location:");
				scanf("%d",&loc);
				printf("Enter a data: ");
				scanf("%d",&data);
				specific(loc,data);
				printf("\n");
				break;
			case '2':
				printf("Enter location you want to delete:");
				scanf("%d",&loc);
				len=length();
				if(loc>len || len==0)
				{
					printf(" invalid location\n list only contain %d nodes",len);
					printf("\n");	
				}
				else
					deletenode(loc);
				printf("\n");
				break;
			case '3':
				printf("Enter the value you want to find:");
				scanf("%d",&val);
				f=find(val);
				if(f == 0)
					printf("Element is not yet entered");
				else
					printf("%d is present",val);
				printf("\n");
				break;
			case '4':
				display();
				printf("\n");
				printf("\n");
				break;
			case '5':
				exit(0);
				break;
					
		}
	}
	
}
