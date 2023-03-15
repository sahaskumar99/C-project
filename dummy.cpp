#include<stdio.h>
int main()
{
	int a[10];
	int i,sum=0;
	for(i=1;i<=5;i++)
	{
		switch(i){
			case 1:
				printf("Spaces and commas are allowed in a variable name?\n");
				printf("1.TRUE 2.FALSE\n");
				scanf("%d",&a[i]);
				if(a[i]==2)
					sum+=5;
				break;
			case 2:
				printf("C programs are converted into machine language with the help of a program called Editor?\n");
				printf("1.TRUE 2.FALSE\n");
				scanf("%d",&a[i]);
				if(a[i]==2)
					sum+=5;
				break;
			case 3:
				printf("The maximum value that an integer constant can have varies from one compiler to another ?\n");
				printf("1.TRUE 2.FALSE\n");
				scanf("%d",&a[i]);
				if(a[i]==1)
					sum+=5;
				break;
			case 4:
				printf("Only character or integer can be used in switch statement ?\n");
				printf("1.TRUE 2.FALSE\n");
				scanf("%d",&a[i]);
				if(a[i]==1)
					sum+=5;
				break;
			case 5:
				printf("The return type of malloc function is void ?\n");
				printf("1.TRUE 2.FALSE\n");
				scanf("%d",&a[i]);
				if(a[i]==2)
					sum+=5;
				break;	
		}
	}
	printf("Final score is %d",sum);
}
