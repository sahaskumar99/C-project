#include<stdio.h>
#include<stdlib.h>
struct node{
	int team_num;
	int score;
	struct node* link;
};
void trav();
void create_team(int);
struct node *rear,*head,*cur;
void main()
{
	int t,i;
	printf("Enter teams");
	scanf("%d",&t);
	for(i=1;i<=t;i++)
		insert(i);
	trav();
}
void insert(int t)
{
	if(head==NULL)
	{
		cur=(struct node *)malloc(sizeof(struct node));
		cur->team_num=t;
		cur->score=0;
		rear=cur;
		head=cur;
		rear->link=cur;
		return;	
	}
	else
	{
		rear=(struct node *)malloc(sizeof(struct node));
		rear->team_num=t;
		rear->score=0;
		rear->link=head;
		cur->link=rear;
		cur=cur->link;
		return;
	}
}
void trav()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
		printf("no nodes exists");
	else{
		while(temp!=rear)
		{
			printf("team no:%d",temp->team_num);
			printf("score:%d",temp->score);
			temp=temp->link;
			printf("\n");
		}
		printf("team no %d",rear->team_num);
		printf("score:%d\t",rear->score);
	}
	return;
}
