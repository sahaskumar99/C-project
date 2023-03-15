#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct l
{
	int id;
	char name[30];
	char uname[50];
	char phone[10];
	char p1[10];
};
void r();
int autoinc();
void r()
{    
     struct l c;
	fflush(stdin);
	printf("\nENTER YOUR NAME:");
	scanf("%[^\n]s",c.name);
	
 	fflush(stdin);
	printf("\nENTER YOUR USERNAME:");
	scanf("%s",c.uname);

	
	fflush(stdin);
	printf("\nENTER YOUR NUMBER:");
	scanf("%s",c.phone);
	
	fflush(stdin);
	printf("\nENTER YOUR PASSWORD:");
	scanf("%s",c.p1);
	
	c.id=autoinc();
	FILE *fp;
	fp=fopen("register.txt","a+");
	fprintf(fp,"%d,%s,%s,%s,%s\n",c.id,c.name,c.uname,c.phone,c.p1);
	fclose(fp);       
}
int autoinc()
{
int i=0;
FILE *fp;
fp=fopen("register.txt","r");
struct l c;
while(fscanf(fp,"%d,%[^,],%[^,],%[^,],%s\n",&c.id,c.name,c.uname,c.phone,c.p1)!=EOF)	
{                    
	i=c.id;
}
fclose(fp);
return i+1;
}
	
int main()
{
	int i;
	while(1)
	{
		char username[30];char p2[30];
		printf("\nENTER YOUR CHOICE>>>>");
		printf("\n1.student login \n2.REGISTER");
		printf("\nENTER YOUR CHOICE>>>>");
		scanf("%d",&i); 
		switch(i)                 
		{
			
			case 1:
				

	printf("\nENTER USERNAME:");
	scanf("%s",username);
	printf("\nENTER PASSWORD:");
	scanf("%s",p2);
		FILE *p;
	struct l t;
	p=fopen("register.txt","r");
	if(fscanf(p,"%d,%[^,],%[^,],%[^,],%s\n",&t.id,t.name,t.uname,t.phone,t.p1) ==EOF)
	{
		printf("\nEMPTY");
		printf("\nPLEASE REGISTER ");
		printf("\nREGISTRATION:");
		r();
		fclose(p);
	}
	p=fopen("register.txt","r");
	while(fscanf(p,"%d,%[^,],%[^,],%[^,],%s\n",&t.id,t.name,t.uname,t.phone,t.p1) != EOF)	
	{
		if(strcmp(t.uname,username)==0 && strcmp(t.p1,p2)==0)
		{
			printf("\nLOGIN SUCCESSFUL");
			
			break;
			
		}
		
	}
	
	printf("\nENTER CORRECT DETAILS");
	fclose(p);
	break;
	
			case 2:
			     r();
				 break;
	
			  exit(0);	 		
		}
	}
	return(0);
}
