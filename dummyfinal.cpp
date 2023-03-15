#include<stdio.h>
int nextquestion(int);
struct quiz
{
	int codenum;
	char question[100];
	int ans;
};
int score=0;
int main()
{
	int id=1900,choice;
	while(1)
	{
		printf("\n1.Next question?\n2.View Result\n3.Exit");
		printf("Enter your choice:\n");
		scanf("%d",&choice);
		int x;
		switch(choice){
			case 1:
				x=nextquestion(id);
				id++;
				score=score+x;
				break;
			case 2:
				printf("The score is %d",score);
				break;
			case 3:
				exit(0);
			default:
				printf("Enter valid choice");
		}
		
	}
}
int nextquestion(int code){
	struct quiz s1;
	FILE *fp;
	int ans,flag=0,code;
	fp=fopen("questions1.txt","rb");
	if(fp==NULL){
		printf("Cannot open file!");
	}
	else{
		int total=5;
		while(fread(&s1,sizeof(s1),1,fp)>0 && flag==0)
		{
			if(s1.codenum==code)
			{
				flag=1;
				printf("Question:\n%s\n",s1.question);
				printf("Enter the answer:\n");
				scanf("%d",&ans);
				if(ans==s1.ans)
					total=5;
				printf("Answer is %d\n",s1.ans);
			}
		}
	return total;
	if(flag==0)
	printf("Not found");
	}

fclose(fp);
}
