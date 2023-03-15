struct User{
	char name[20];
	int username;
	int password;
	struct User *next;
};
int username_1;
int password_1;
struct User *cur,*t1,*t2,*first=NULL;
struct User *back()
{
	FILE *fp=fopen("Admin_details.txt","r");
	char buffer[1024];
	int row=0,column=0;
	while(fgets(buffer,1024,fp)){
		column=0;
		row++;
		char* value = strtok(buffer, ",");
 		struct User *cur=(struct User *)malloc(sizeof(struct User));
 		while(value)
 		{	
 			if(column==0)
 				cur->username=atoi(value);
 			if(column==1)
 				strcpy(cur->name,value);
 			if(column==2)
 				cur->password=atoi(value);
 			value = strtok(NULL, ",");
	        column++;
		}
		cur->next=NULL;
	 	if(first==NULL){
	 		first=cur;
		}
		else
		{
			t1=first;
			while(t1->next!=NULL){
				t1=t1->next;
			}
			t1->next=cur;
		}
	}
	fclose(fp);
	return first;
}
struct User* create(struct User *head)
{
	int flag;
	cur=(struct User *)malloc(sizeof(struct User));
	printf("Enter the username ");
	scanf("%d",&cur->username);
	flag=check(cur->username,head);
	if(flag==1){
		printf("User already exists ... Try Again");
		exit(0);
		return NULL;
	}
	printf("Enter the name: ");
	scanf("%s",cur->name);
	fflush(stdin);
	printf("Enter the password");
	scanf("%d",&cur->password);
	cur->next=NULL;
	t1=head;
	if(head==NULL)
	{
		head=cur;
	}
	while(t1->next!=NULL){
		t1=t1->next;
	}
	t1->next=cur;		
	FILE *fp=fopen("Admin_details.txt","a");
	fprintf(fp,"%d,%s,%d",cur->username,cur->name,cur->password);
	fclose(fp);
	return head;
}
int check(int username_1 ,struct User *head){
	if(head==NULL)
	{
		return 0;
	}
	while(head!=NULL){
		if(username_1==head->username){
			return 1;
		}
		head=head->next;
	}
	return 0;
}
int check_login(int uname,int p,struct User *head){
	if(head==NULL){
		return 0;
	}
	
	while(head!=NULL){
		if(uname==head->username){
			if(p==head->password){
				return 1;
			}
		}
		head=head->next;
	}
	return 0;
}
struct User* delte(int uname,struct User *head){
	t1=head;
	t2=head;
	while(t1->username!=uname){
		t2=t1;
		t1=t1->next;
	}
		t2->next=t1->next;
		free(t1);
	printf("Record deleted sucessfully\n");
	return head;
}
struct User* update(int uname,struct User *head){
	int s;
	t1=head;
	t2=head;
	while(t1->username!=uname){
		t1=t1->next;
	}
		while(1){
		printf("1.Update name\n2.Update Username\n3.Update Password\n4.Exit.\n"); 
		scanf("%d",&s);
		switch(s){
		case 1:
				printf("Enter new name:");
				scanf("%s",t1->name);
				fflush(stdin);
				break;
			case 2:
				printf("Enter new Username:");
				scanf("%d",&t1->username);
				break;
			case 3:
				printf("Enter new password:");
				scanf("%d",&t1->password);
				break;
		}
		if(s>3){
			break;
		}
		
	}
	return head;
}

