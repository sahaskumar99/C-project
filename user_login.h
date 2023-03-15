struct user{
	int cid;
	char uname[30];
	char password[30];
	
}u;
void register_user()
{
	//fflush(stdin);
	printf("Enter username");
	scanf("%s",u.uname);
	fflush(stdin);
	printf("Enter password");
	scanf("%s",u.password);
	u.cid=autoincrementuser();
	FILE *fp=fopen("user_login.txt","a+");
	fprintf(fp,"%d,%s,%s\n",u.cid,u.password,u.uname);
	fclose(fp);
	
}
int autoincrementuser()
{
	FILE *fp= fopen("user_login.txt","r");
	int id=0;
	while(fscanf(fp,"%d,%[^,],%s[^,]\n",&u.cid,u.password,u.uname)!=EOF){
		id=u.cid;
	}
	return id+1;
	fclose(fp);
}
void login_user()
{
	int matched=0;
	char uname[30],pwd[30];
	printf("Enter username");
	scanf("%s",uname);
	printf("Enter password");
	scanf("%s",pwd);
	FILE *fp = fopen("user_login.txt","r");
	struct user c1;
	while(fscanf(fp,"%d,%[^,],%[^,]",&c1.cid,c1.password,c1.uname)!=EOF)
	{
		if(strcmp(uname,c1.uname)&&strcmp(pwd,c1.password))
		{
			matched =1;
			break;
		}
	}
	fclose(fp);
	if(matched)
		printf("Correct username and pass");
	else
		printf("Incorrect");
}
