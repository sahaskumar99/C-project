#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"login.h"
struct Student *afirst,*cur,*t,*temp,*t1;
struct Student *ptr[4]={NULL,NULL,NULL,NULL};
int  c=0,ccse,cit,cece,ceie;
int cseArr[100],eieArr[100],eceArr[100],itArr[100];
int Arrindex=0;
void count(struct Student *root){
	if(root->lc!=NULL){
		count(root->lc);
	}
	c++;
	if(root->rc!=NULL){
		count(root->rc);
	}
}
struct Student* addBst(struct Student *root,struct Student *t){
	struct Student *temp=root;
    if(root==NULL){
        root=t;
        return root;
    }
    while(1){
        if(temp->rollno > t->rollno){
            if(temp->lc==NULL){  //there is no lchild
                temp->lc=t;
                return root;
            }
            else{
                temp=temp->lc;
             }
        }
        else{
            if(temp->rc==NULL){ //there is no rchild
                temp->rc=t;
                return root;
            }
            else{
                temp=temp->rc;
            }
        }
    }
    return root;
}
void createbst(struct Student *head){
	int index=0;
	t1=head;
	while(t1!=NULL){
		t1->lc=NULL;
		t1->rc=NULL;
		if(strcmp(t1->branch,"cse")==0){
			index=0;
		}
		if(strcmp(t1->branch,"it")==0){
			index=1;
		}
		if(strcmp(t1->branch,"ece")==0){
			index=2;
		}
		if(strcmp(t1->branch,"eie")==0){
			index=3;
		}
		ptr[index]=addBst(ptr[index],t1);
		t1=t1->next;
	}
}
void displaybst(struct Student *root){
	if(root->lc!=NULL){
		displaybst(root->lc);
	}
//	FILE *fp=fopen("students_details.txt","a");
//	fprintf(fp,"%s,%s,%s,%d,%d,%s",t1->name,t1->subject,t1->branch,t1->rollno,t1->sem,t1->password);
//	fclose(fp);
	cseArr[Arrindex++]=root->rollno;
	printf("Name     : %s\t",root->name);
	printf("Branch   : %s\t",root->branch);
	printf("Subject  : %s\t",root->subject);
	printf("Roll NO  : %d\t",root->rollno);
	printf("Sem:     : %d\t",root->sem);
	printf("Password : %s\n",root->password);
	if(root->rc!=NULL){
		displaybst(root->rc);
	}
}
void dispbst(){
	int j;
	for(j=0;j<4;j++){
		if(j==0){
			printf("CSE Branch\n");
		}
		if(j==1){
			printf("IT branch\n");
		}
		if(j==2){
			printf("ECE branch\n");
		}
		if(j==3){
			printf("EIE branch\n");
		}
		if(ptr[j]==NULL){
			printf("Empty..\n\n");
		}
		else displaybst(ptr[j]);
	}
}
void main(){
	int ccse,cit,cece,ceie;
	first=set();
	createbst(first);
	//FILE *fp=fopen("students_details.txt","w");
	//fclose(fp);		
	if(ptr[0]==NULL) {
		ccse=0;
	}
	else{
		count(ptr[0]);
		ccse=c;
		c=0;
	}
	if(ptr[1]==NULL){
		cit=0;
	}
	else{
		count(ptr[1]);
		cit=c;
		c=0;
	}
	if(ptr[2]==NULL) {
	cece=0;}
	else{
		count(ptr[2]);
		cece=c;
		c=0;
	}
	if(ptr[3]==NULL) {
	ceie=0;}
	else{
		count(ptr[3]);
		ceie=c;
		c=0;
	}
	printf("CSE Count: %d\n",ccse);
	printf("IT Count: %d\n",cit);
	printf("ECE Count: %d\n",cece);
	printf("EIE Count: %d\n",ceie);
	dispbst();
	int i=0;
	for(i=0;i<ccse;i++){
		printf("%d\t",cseArr[i]);
	}
}
