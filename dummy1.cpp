#include<stdio.h>
int total=0;
int main(){
	struct quiz{
		int codenum;
		char question[100];
		int ans;
	};
	struct quiz s1;
	FILE *fp;
	int ans,flag=0,code;
	fp=fopen("questions1.txt","rb");
	if(fp==NULL){
		printf("Cannot open file!");
	}
	else{
		printf("Phy code starts from 1900\n");
		printf("Enter the code of question?\n");
		scanf("%d",&code);
		while(fread(&s1,sizeof(s1),1,fp)>0 && flag==0)
		{
			if(s1.codenum==code)
			{
				flag=1;
				printf("code num:%d\nQuestion:\n%s\n",s1.codenum,s1.question);
				printf("Enter the answer:\n");
				scanf("%d",&ans);
				if(ans==s1.ans)
					total+=5;
				printf("Answer is %d\n",s1.ans);
			}
		}
	printf("total sum is %d",total);
	if(flag==0)
	printf("Not found");
	}

fclose(fp);
}
