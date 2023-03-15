struct question{
	int id;
	char question[1000];
	int ans;
	struct question *link;
};

int id;
struct question *cur1,*first1,*temp1,*temp2,*first3,*first_mock,*first4,*b_t1,*b_head,*firsti3;

int autoincrement(struct question *head1)
{
	struct question *temp1;
	temp1=head1;
	
	while(temp1->link!=NULL)
	{
		temp1=temp1->link;
	}
	return temp1->id+1;
	
}
struct question* addquestion(struct question *head2)
{
	printf("in c");
	int flag;
	cur1=(struct question *)malloc(sizeof(struct question));
	cur1->id=autoincrement(head2);
	printf("%d",cur1->id);
	fflush(stdin);
	printf("\nEnter the question:");
	gets(cur1->question);
	fflush(stdin);
	printf("Enter the answer");
	scanf("%d",&cur1->ans);
	cur1->link=NULL;
	temp1=head2;
	if(head2==NULL)
	{
		head2=cur1;
	}
	while(temp1->link!=NULL){
		temp1=temp1->link;
	}
	temp1->link=cur1;		
	FILE *fp=fopen("Admin_questions.txt","a");
	fprintf(fp,"%d,%s,%d\n",cur1->id,cur1->question,cur1->ans);
	fclose(fp);
	return head2;
}
struct question* addquestion1(struct question *head1)
{
	printf("in java");
	int flag;
	cur1=(struct question *)malloc(sizeof(struct question));
	cur1->id=autoincrement(head1);
	fflush(stdin);
	printf("%d",cur1->id);
	printf("\nEnter the question:");
	gets(cur1->question);
	fflush(stdin);
	printf("Enter the answer");
	scanf("%d",&cur1->ans);
	cur1->link=NULL;
	temp1=head1;
	if(head1==NULL)
	{
		head1=cur1;
	}
	while(temp1->link!=NULL){
		temp1=temp1->link;
	}
	temp1->link=cur1;		
	FILE *fp=fopen("Admin_questions1.txt","a");
	fprintf(fp,"%d,%s,%d\n",cur1->id,cur1->question,cur1->ans);
	fclose(fp);
	return head1;
}
int checkid(int id,struct question *head1){
	if(head1==NULL)
	{
		return 0;
	}
	while(head1!=NULL){
		if(id==head1->id){
			return 1;
		}
		head1=head1->link;
	}
	return 0;
}
struct question* question_delte(int id,struct question *head1){
	temp1=head1;
	temp2=head1;
	while(temp1->id!=id){
		temp2=temp1;
		temp1=temp1->link;
	}
		temp2->link=temp1->link;
		free(temp1);
	printf("Record deleted sucessfully\n");
	return head1;
}

struct question* update_question(int id,struct question *head1){
	int s;
	temp1=head1;
	//temp2=head1;
	while(temp1->id!=id)
	{
		temp1=temp1->link;
	}
	
		while(1)
		{
			printf("\n1.Update Question\n2.Update Answer\n3.Exit.\n"); 
			scanf("%d",&s);
			switch(s)
			{
				case 1:
					fflush(stdin);
					printf("Enter new Question:");
					gets(temp1->question);
					break;
				case 2:
					printf("Enter new Answer:");
					scanf("%d",&temp1->ans);
					break;
				case 3:
					break;
			}
			if(s>2)
				break;
		}
	
	return head1;
}
struct question* question_back()
{
	
	FILE *fp=fopen("Admin_questions.txt","r");
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
struct question* display(int id,struct question *head1)
{
	int flag=0;
	temp1=head1;
	while(temp1!=NULL)
	{
		if(temp1->id==id)
		{
			printf("Question:\n%s\n",temp1->question);
			printf("Answer:\n%d\n",temp1->ans);
			flag=1;
			break;
		}
		temp1=temp1->link;
	}
	if(flag==0)
		printf("Id not found...!\n");
	return head1;
}

struct question* question_back1()
{
	
	FILE *fp=fopen("Admin_questions1.txt","r");

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
void into_file(struct question *first3)
{
	FILE *fp=fopen("Admin_questions.txt","w");
	temp1=first3;
	int x=1;
	while(temp1!=NULL){
		
		fprintf(fp,"%d,%s,%d\n",temp1->id,temp1->question,temp1->ans);
		temp1=temp1->link;
	}
		fclose(fp);
}

void into_file1(struct question *first3)
{
	FILE *fp3=fopen("Admin_questions1.txt","w");
	temp1=first3;
	int x=1;
	while(temp1!=NULL){
		if(x==1){
			fprintf(fp3,"%d,%s,%d",temp1->id,temp1->question,temp1->ans);
			temp1=temp1->link;
			x++;
		}
		else{
			fprintf(fp3,"\n%d,%s,%d",temp1->id,temp1->question,temp1->ans);
			temp1=temp1->link;
		}
	}
	fprintf(fp3,"\n");
	fclose(fp3);
}

