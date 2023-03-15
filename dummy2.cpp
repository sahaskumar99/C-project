#include<stdio.h>
int main(){
	struct quiz{
		int codenum;
		char question[1000];
		int ans;
	};
	struct quiz s1;
	FILE *fp;
	char ch='y';
	fp=fopen("questions1.txt","ab");
	if(fp==NULL)
		printf("Cannot open file");
	while(ch=='y')
	{
		printf("Enter code number");
		scanf("%d",&s1.codenum);
		printf("Enter question");
		gets(s1.question);
		gets(s1.question);
		fflush(stdin);
		printf("Enter answer");
		scanf("%d",&s1.ans);
		fwrite(&s1,sizeof(s1),1,fp);
		printf("Do you want to insert new question (y/n)\n");
		ch=getchar();
	}
fclose(fp);
	
}
