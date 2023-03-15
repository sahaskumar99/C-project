#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"projectfinal.h"
#include"User.h"
#include"Admin_module.h"
#include"admin_module2.h"
void trav();
void c_insert(int);
void removenode(int );
void min();
int a[20]={0,0,0,0,0,0,0,0,0,0};
struct question *ptr[2]={NULL,NULL};
void generate_random();
struct node* addBst();
void displaybst(struct node *);
struct question* test(struct question *,int);
struct node *rear,*head,*c_cur;
struct question *cur1,*first1,*temp1,*temp2,*first3,*first_mock,*first4,*b_t1,*b_head;
int topic_choice,key;
int hash(int i,int j){
	return i%j;
}
void main()
{
	int choice,adchoice,subadchoice,subsubchoice,uname,question_id,manage_top,manage_question,i=0,ch,topic_choice;
	int mask_pass[30];
	printf("\n\n\n\t\t\t\t\t<<<<<WELCOME TO QUIZ GAME>>>>>\n");
	printf("\t\t\t\t******************************************\t\t\n\n\n\n");
	printf("1.Admin\n");
	printf("2.User\n\t");
	scanf("%d",&choice);
	int c,pw;
	switch(choice)
	{
		case 1:
			first=back();
			t1=first;
			/*while(t1!=NULL)
			{
				printf("%d %s %d\n",t1->username,t1->name,t1->password);
				t1=t1->next;
			}*/
			printf("1.Register As Admin\n2.Login as Admin\n\t");
			scanf("%d",&adchoice);
			switch(adchoice)
			{
				case 1:
					printf("Enter your details as Admin\n");
					first=create(first);
					printf("\n\nYou have registered as Admin Sucessfully\n");
					break;
				case 2:
					printf("Enter your details\n");
					printf("Enter Username: ");
					scanf("%d",&uname);
					printf("Enter the password: ");
					scanf("%d",&pw);
					c=check_login(uname,pw,first);
					if(c==1){
						printf("\n\nLogin Sucessfully\n");
						printf("\n\n\t\t\t\t\t<<<<<WELCOME ADMIN>>>>>\n");
						printf("\n1.Manage questions\n2.Update details\n3.Delete Admin\n\t");
						scanf("%d",&subadchoice);
						
						/*while(temp1!=NULL)
						{
							printf("%d %s %d\n",temp1->id,temp1->question,temp1->ans);
							temp1=temp1->link;
						}*/
						
						if(subadchoice==1)
						{
							printf("\nEnter the topic in which you want to enter...?\n1.C_DS\n2.Java\n\t");
							scanf("%d",&topic_choice);
							ptr[0]=question_back();
							ptr[1]=question_back1();
							key=hash(topic_choice,2);
							
						}
						switch(subadchoice)
						{
							/*case 1:
								printf("1.Add topic\n");
								printf("2.Display topic\n");
								scanf("%d",&manage_top);
								break;*/
							case 1:
								printf("1.Add question\n2.Display question\n3.Update question\n4.Delete question\n5.exit\n\t");
								scanf("%d",&manage_question);
								switch(manage_question){
									case 1:
										
										if(topic_choice==1)
											ptr[0]=addquestion(ptr[key]);
										if(topic_choice==2)
											ptr[1]=addquestion1(ptr[key]);
										break;
										
									case 2:
										printf("Enter the id:");
										scanf("%d",&question_id);
										if(topic_choice==1)
											ptr[0]=display(question_id,ptr[key]);
										if(topic_choice==2)
											ptr[1]=display(question_id,ptr[key]);
										
										break;
									case 3:
										printf("Enter the id:");
										scanf("%d",&question_id);
										if(topic_choice==1)
											ptr[0]=update_question(question_id,ptr[key]);
										if(topic_choice==2)
											ptr[1]=update_question(question_id,ptr[key]);
										break;
									case 4:
										printf("Enter the id:");
										scanf("%d",&question_id);
										if(topic_choice==1)
											ptr[0]=question_delte(question_id,ptr[key]);
										if(topic_choice==2)
											ptr[1]=question_delte(question_id,ptr[key]);
										break;
									}if(manage_question>=5)
									{
										break;
									}
									if(topic_choice==1 && manage_question==3 || manage_question==4)
									{
										into_file(ptr[0]);
										//printf("c_ds");
									}
									else if(topic_choice==2 && manage_question==3 || manage_question==4)
									{
										into_file1(ptr[1]);
										//printf("java");
									}
									exit(0);	
							case 2:
								first=update(uname,first);
								break;
							case 3:
								first=delte(uname,first);
								break;
						}if(subadchoice>3)
						{
							break;
						}
					}
					else
						printf("\nIncorrect credentials\nPlease Try again\n");	
			}
			FILE *fp=fopen("Admin_details.txt","w");
			t1=first;
			int x=1;
			while(t1!=NULL){
				if(x==1){
					fprintf(fp,"%d,%s,%d",t1->username,t1->name,t1->password);
					t1=t1->next;
					x++;
				}
				else{
				fprintf(fp,"\n%d,%s,%d",t1->username,t1->name,t1->password);
				t1=t1->next;
				}
			}
			fprintf(fp,"\n");
			fclose(fp);
			break;
		case 2:
			first2=backuser();
			t11=first2;
			/*while(t11!=NULL)
			{
				printf("%d %s %d\n",t11->username,t11->name,t11->password);
				t11=t11->next;
			}*/
			int userchoice,subuserchoice;
			printf("\n1.Register as User\n2.Login as User\n\t");
			scanf("%d",&userchoice);
			switch(userchoice)
			{
				int c;
				int uname1,pw1;
				case 1:
					printf("Enter the details as User:\n");
					first2=createuser(first2);
					printf("\n\nRegistered successfully\n\n\n");
					break;
				case 2:
					printf("Enter your details\n");
					printf("Enter Username: ");
					scanf("%d",&uname1);
					printf("Enter the password: ");
					scanf("%d",&pw1);
					c=check_login_user(uname1,pw1,first2);
					if(c==1)
					{
						printf("\n\nLogin Sucessfully\n\n\n");
						printf("\n\n\t\t\t\t\t<<<<<WELCOME USER>>>>>\n");
						printf("\n1.Take Mock test\n2.Take test\n3.Update details\n4.Delete User\n5.Exit\n\t");
						scanf("%d",&subuserchoice);
						switch(subuserchoice)
						{
							case 1:
								printf("\n\n\t\t\t\t\t<<<<<WELCOME TO MOCK TEST>>>>>\n");
								first_mock=mock_testback();
								first_mock=mock_test(first_mock);
								break;
							case 2:
								
								printf("\t\t\t\t\tRead following rules carefully!!\n");
								printf("\t\t1.For every correct answer +5 and for every wrong answer -1\n");
								printf("\t\t2.Select the team with low team number because when score are tie the team with greater team number will be eliminated\n");
								printf("\t\t3.Make sure your score is greater than 10 to declare as Winner in final round\n");
								printf("\n\n\n\t\t\t\t\t<<<<<WELCOME TO TEST>>>>>\n\n");
								printf("\n\n\n\t\t\t\t\t<<<<<ALL THE BEST>>>>>\n\n");
								printf("\nSelect the topic:\n1.DS_C\n2.Java\n3.Exit\n\t");
								scanf("%d",&topic_choice);
								switch(topic_choice)
								{
									case 1:
										printf("You have chosen C_DS\n");
										first3=question_back();
										break;
									case 2:
										printf("You have chosen JAVA\n");
										first3=question_back1();
										break;
									case 3:
										exit(0);
								}if(topic_choice>=3)
								{
									exit(0);
								}
								int t;
								printf("Enter number of teams?");
								scanf("%d",&t);
								for(i=1;i<=t;i++)
								{
									c_insert(i);
								}
								//trav1();
								while(t>0)
								{
								
									first3=test(first3,(t--)*3);
								
								}
									
								break;		
							case 3:
								first2=user_update(uname1,first2);
								break;
							case 4:
								first2=user_delte(uname1,first2);
								break;
						}
							
					}
					else
						printf("Incorrect credentials\nPlease Try again\n");
			}
			FILE *fp4=fopen("User_details.txt","w");
			t11=first2;
			int x1=1;
			while(t11!=NULL){
				if(x1==1){
					fprintf(fp4,"%d,%s,%d",t11->username,t11->name,t11->password);
					t11=t11->next;
					x1++;
				}
				else{
				fprintf(fp4,"\n%d,%s,%d",t11->username,t11->name,t11->password);
				t11=t11->next;
				}
			}
			fprintf(fp4,"\n");
			fclose(fp4);
			exit(0);		
	}
}
void c_insert(int t)
{
	if(head==NULL)
	{
		c_cur=(struct node *)malloc(sizeof(struct node));
		c_cur->team_num=t;
		c_cur->score=0;
		rear=c_cur;
		head=c_cur;
		rear->link=c_cur;
		return;	
	}
	else
	{
		rear=(struct node *)malloc(sizeof(struct node));
		rear->team_num=t;
		rear->score=0;
		rear->link=head;
		c_cur->link=rear;
		c_cur=c_cur->link;
		return;
	}
}
void trav()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
		printf("no nodes exists");
	/*if(head->link=NULL)
	{
		printf("\nCongratulations\nYou are the winner ");
		exit(0);
	}*/
	if(head->link==head)
	{
		if(head->score>10)
		{
			printf("\n\n\t\tCONGRATULATIONS....!\n\n\t\tWinner is : Team - %d\n",head->team_num);
			printf("\n\t\tThank you for playing the game :)");
		}
		else
		{
			printf("\n\tAs Team no %d score is not upto the mark... There is no winner for this Game...!",head->team_num);
			printf("\n\t\tThank you for playing the game :)");
		}
		exit(0);
	}
	else{
		while(temp!=rear)
		{
			printf("\n\t\tTeam No:%d",temp->team_num);
			printf("\n\t\tScore:%d\t",temp->score);
			temp=temp->link;
			printf("\n");
		}
		printf("\n\t\tTeam No:%d",rear->team_num);
		printf("\n\t\tScore:%d\t",rear->score);
	}
	
	return;
}

void generate_random()
{
	time_t t10;
	srand((unsigned) time(&t10));
	
	int i, num,c=0,count=0,j;
	for (i = 1; i <= 100; i++)  
    {  
        num = rand() % 30 + 1;
        count=0; 
        for(j=0;j<20;j++)
		{
            if(a[j]==num)
			{
                count++;
                break;
            }
        }
        if(count==0) 
			a[c++]=num;
        if(c==20) 
			break;
    }
}
struct question* test(struct question *head1,int t)
{
	int answer,total=0,index=0;
	int number;
	struct node *temp;
	temp=head;
	generate_random();
	while(t>0)
	{			
		index++;
		number=a[index];
		temp1=head1;
		//printf("head is %d",head->team_num);
		while(temp1!=NULL)
		{
			if(temp1->id==number)
			{
				printf("\n**************************************************************\n");
				printf("\nTeam Number: %d \n",temp->team_num);
				printf("\nQuestion:");
				printf("%s",temp1->question);
				printf("\nEnter the ans:");
				scanf("%d",&answer);
				if(temp1->ans==answer)
				{
					printf("\nAnswer is correct!");
					temp->score=temp->score+5;
					
				}
				else{
					printf("\nWrong answer");
					temp->score=temp->score-1;
					
				}
				printf("\nAnswer is %d",temp1->ans);
				printf("\nYour score:%d\n",temp->score);
					
				temp=temp->link;
			}
			temp1=temp1->link;			
		}
		t--;
	}

	
	trav();
	min();
	return head1;
}
void min()
{
	struct node *t1=head,*t2=head;
	int min,max;
	struct node *temp=head;
	if(head==NULL)
	{
		printf("\nTHE NODE IS EMPTY");
	}
	min=head->score;
	max=head->score;
	do
	{
		if(min>temp->score)
		{
			min=temp->score;
			t1=temp;
        }
        if(max<temp->score)
        {
        	max=temp->score;
        	t2=temp;
		}
		//t1=temp;
		temp=temp->link;
	}while(temp->link!=head->link);
		//rear=temp;
		//printf("\nHighest in this round...!\nTeam no:%d\nScore:%d\n ",t2->team_num,max);
		printf("\nLowest in this round...!\nTeam no:%d\nScore:%d\n ",t1->team_num,min);
		printf("\n\t\tTeam:%d is eliminated...! \n",t1->team_num);
		
		removenode(min);
		return;
}

void removenode(int min)
{
	struct node *t1,*t2;
	struct node *temp=head;
	do
	{
		if(head->score==min)
		{
			rear->link=head->link;
			head=head->link;
			break;
		}
		if(temp->link->score==min)
		{
			temp->link=temp->link->link;
			break;
		}
		temp=temp->link;
    }while(temp->link!=head->link);
	
}

