struct node{
	int team_num;
	int score;
	struct node* link;
};
struct node c_rear,*c_head=NULL,*c_cur;
struct question* mock_testback()
{
	
	FILE *fp=fopen("mock_test.txt","r");

	char buffer1[1024];
	int row=0,column=0;
	while(fgets(buffer1,1024,fp)){
		column=0;
		row++;
		char* value = strtok(buffer1, ",");
 		struct question *cur1=(struct question *)malloc(sizeof(struct question));
 		while(value)
 		{	
 			if(column==0)
 				cur1->id=atoi(value);
 			if(column==1)
 				strcpy(cur1->question,value);
 			if(column==2)
 				cur1->ans=atoi(value);
 			value = strtok(NULL, ",");
	        column++;
		}
		cur1->link=NULL;
	 	if(first3==NULL)
		{
	 		first3=cur1;
		}
		else
		{
			temp1=first3;
			while(temp1->link!=NULL){
				temp1=temp1->link;
			}
			temp1->link=cur1;
		}
	}
	fclose(fp);
	return first3;
}
struct question* mock_test(struct question *head1)
{
	int questions=5,answer,total=0;
	int number;
	temp1=head1;
	int y1=0;
	while(questions>0)
	{
		while(temp1!=NULL)
		{
			y1++;
			if(temp1->id==y1)
			{
				printf("\nQuestion:");
				printf("%s",temp1->question);
				printf("\nEnter the ans:");
				scanf("%d",&answer);
				if(temp1->ans==answer)
				{
					printf("\nAnswer is correct!");
					total=total+5;
				}
				else{
					printf("\nWrong answer");
					total=total-1;
				}
				printf("\nAnswer is %d",temp1->ans);
				printf("\nYour score:%d\n",total);
			}
			temp1=temp1->link;
		}
		questions--;
	}
	printf("\n\t\tYOUR FINAL SCORE IS %d",total);
	printf("\n\t\tMOCK TEST IS DONE!");
	printf("\n\t\tPLEASE LOGIN AGAIN FOR ORIGINAL TEST..!\n");
	return head1;
}
int generate_random(int t)
{
	int a[10]={0,0,0,0,0,0,0,0,0,0};
	int i, num,c=0,count=0,j;
	for (i = 1; i <= 100; i++)  
    {  
        num = rand() % 10 + 1;
        count=0; 
        for(j=0;j<10;j++)
		{
            if(a[j]==num)
			{
                count++;
                break;
            }
        }
        if(count==0) 
			a[c++]=num;
        if(c==10) 
			break;
    }
    return a[t];
}
struct question* test(struct question *head1)
{
	int teams,answer,total=0,index=0;
	//c_head=c_insert(c_head,teams);
	//trav(c_head);
	int number;
	while(teams>0)
	{
		index++;
		printf("%d",teams);
		number=generate_random(index);
		temp1=head1;
		while(temp1!=NULL)
		{
			if(temp1->id==number)
			{
				printf("\nQuestion:");
				printf("%s",temp1->question);
				printf("\nEnter the ans:");
				scanf("%d",&answer);
				if(temp1->ans==answer)
				{
					printf("\nAnswer is correct!");
					total=total+5;
				}
				else{
					printf("Wrong answer");
					total=total-1;
				}
				printf("\nAnswer is %d",temp1->ans);
				printf("\nYour score:%d\n",total);
			}
			temp1=temp1->link;
			
		}
		teams--;
	}
	printf("\t\t\tYOUR FINAL SCORE IS %d",total);
	return head1;
}


struct node* c_insert(struct node* c_head,int t)
{
	if(c_head==NULL)
	{
		c_cur=(struct node *)malloc(sizeof(struct node));
		c_cur->team_num=t;
		c_cur->score=0;
		c_rear=c_cur;
		c_head=c_cur;
		c_rear->link=c_cur;
		return;	
	}
	else
	{
		c_rear=(struct node *)malloc(sizeof(struct node));
		c_rear->team_num=t;
		c_rear->score=0;
		c_rear->link=c_head;
		c_cur->link=c_rear;
		c_cur=c_cur->link;
		return;
	}
	return c_head;
}
void trav(struct node* c_head)
{
	struct node *c_temp;
	c_temp=c_head;
	if(c_head==NULL)
		printf("no nodes exists");
	else{
		while(c_temp!=c_rear)
		{
			printf("team no:%d",c_temp->team_num);
			printf("score:%d",c_temp->score);
			c_temp=c_temp->link;
			printf("\n");
		}
		printf("team no %d",c_rear->team_num);
		printf("score:%d\t",c_rear->score);
	}
	return;
}*/
