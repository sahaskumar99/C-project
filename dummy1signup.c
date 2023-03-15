struct node{
	int team_num;
	int score;
	struct node* link;
	struct node* lchild;
	struct node* rchild;
};
struct node *rear,*c_head=NULL,*c_cur,*c_root=NULL;
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

