#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
//#include"user_login.h"
void admin();
void user();
void register_user();
int autoincrementuser();
void login_user();
struct user{
	int cid;
	char uname[30];
	char password[30];	
}u;
int main()
{
	int choice;
	printf("Enter as?\n1.Admin\n2.User\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			admin();
			break;
		case 2:
			user();
			break;
		default:
			printf("Enter correct choice:");
	}
	return 0;
}
void admin()
{
	int adchoice;
	printf("1.Register as Admin\n2.Login as Admin\n");
	scanf("%d",&adchoice);
	switch(adchoice)
	{
		case 1:
			register_user();
			break;
		case 2:
			login_user();
			break;
		default:
			printf("Enter valid choice");
			
	}
}
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
		if(strcmp(uname,c1.uname)==0 &&strcmp(pwd,c1.password)==0)
		{
			printf("Login succesfull");
			break;
		}
	}
	//printf("Enter correct details");
	fclose(fp);
	
	

}
void user()
{
	printf("Welcome to user menu");
}
