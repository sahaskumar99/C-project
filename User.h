struct User1{
	char name[20];
	int username;
	int password;
	struct User1 *next;
};
int username_2;
int password_2;
struct User1 *cur2,*t11,*t21,*first2=NULL,*head2;
int username_1;
int password_1;
struct User1 *backuser()
{
	FILE *fp=fopen("User_details.txt","r");
	char buffer2[1024];
	int row=0,column=0;
	while(fgets(buffer2,1024,fp)){
		column=0;
		row++;
		char* value = strtok(buffer2, ",");
 		struct User1 *cur2=(struct User1 *)malloc(sizeof(struct User1));
 		while(value)
 		{	
 			if(column==0)
 				cur2->username=atoi(value);
 			if(column==1)
 				strcpy(cur2->name,value);
 			if(column==2)
 				cur2->password=atoi(value);
 			value = strtok(NULL, ",");
	        column++;
		}
		cur2->next=NULL;
	 	if(first2==NULL){
	 		first2=cur2;
		}
		else
		{
			t11=first2;
			while(t11->next!=NULL){
				t11=t11->next;
			}
			t11->next=cur2;
		}
	}
	fclose(fp);
	return first2;
}
struct User1* createuser(struct User1 *head2)
{
	int flag;
	cur2=(struct User1 *)malloc(sizeof(struct User1));
	printf("Enter the username ");
	scanf("%d",&cur2->username);
	flag=check_user(cur2->username,head2);
	if(flag==1){
		printf("User already exists ... Try Again");
		exit(0);
		return NULL;
	}
	printf("Enter the name: ");
	scanf("%s",cur2->name);
	fflush(stdin);
	printf("Enter the password");
	scanf("%d",&cur2->password);
	cur2->next=NULL;
	t11=head2;
	if(head2==NULL)
	{
		head2=cur2;
	}
	while(t11->next!=NULL){
		t11=t11->next;
	}
	t11->next=cur2;		
	FILE *fp=fopen("Admin_details.txt","a");
	fprintf(fp,"%d,%s,%d",cur2->username,cur2->name,cur2->password);
	fclose(fp);
	return head2;
}
int check_user(int username_1 ,struct User1 *head2){
	if(head2==NULL)
	{
		return 0;
	}
	while(head2!=NULL){
		if(username_1==head2->username){
			return 1;
		}
		head2=head2->next;
	}
	return 0;
}
int check_login_user(int uname,int p,struct User1 *head2){
	if(head2==NULL){
		return 0;
	}
	while(head2!=NULL){
		if(uname==head2->username){
			if(p==head2->password){
				return 1;
			}
		}
		head2=head2->next;
	}
	return 0;
}
struct User1* user_delte(int uname,struct User1 *head2){
	t11=head2;
	t21=head2;
	while(t11->username!=uname){
		t21=t11;
		t11=t11->next;
	}
		t21->next=t11->next;
		free(t11);
	printf("Record deleted sucessfully\n");
	return head2;
}
struct User1 * user_update(int uname,struct User1 *head2)
{
	int s;
	t11=head2;
		while(t11->username!=uname){
			t11=t11->next;
		}
		while(1)
		{
			printf("1.Update name\n2.Update Username\n3.Update Password\n4.Exit.\n"); 
			scanf("%d",&s);
			switch(s)
			{
				case 1:
					printf("Enter new name:");
					scanf("%s",t11->name);
					fflush(stdin);
					break;
				case 2:
					printf("Enter new Username:");
					scanf("%d",&t11->username);
					break;
				case 3:
					printf("Enter new password:");
					scanf("%d",&t11->password);
					break;
			}
			if(s>3)
				break;	
		}
	return head2;
}

