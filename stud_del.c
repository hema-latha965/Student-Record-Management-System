#include"student.h"
void delete_record(SLL **head){
	SLL *del,*prev;
	int roll,valid=0,found=0;
	char ch,name[30];
	if(*head==0){
		printf("\033[31mStudent list is empty!\033[0m\n");
		return;
	}
	printf("\033[36mR/r: Enter roll number to delete\n");
	printf("N/n: Enter name to delete\n");
	printf("Enter your choice: \033[0m");
	scanf(" %c",&ch);
	if(ch=='R' || ch=='r'){
		printf("\033[36mEnter roll number: \033[0m");
		scanf("%d",&roll);
	}
	else if(ch=='N' || ch=='n'){
		printf("\033[36mEnter student name: \033[0m");
		scanf(" %[^\n]",name);
		del = *head;
		while(del){
			if(strcmp(del->name,name)==0){
				found++;
				roll=del->rollno;
				printf("\033[33mRoll no: %d Name: %s Percentage: %.2f\033[0m\n",del->rollno,del->name,del->percentage);
			}
			del=del->next;
		}
		if(found==0){
			printf("\033[31mStudent name not found!\033[0m\n");
			return;
		}
		if(found>1){
			printf("\033[36mEnter roll number to delete: \033[0m");
			scanf("%d",&roll);
			del=*head;
			while(del){
				if(del->rollno == roll && strcmp(del->name,name)==0){
					valid=1;
					break;
				}
				del=del->next;
                        }
			if(valid==0){
				printf("\033[31mInvalid roll number for the entered name!\033[0m\n");
				return;
			}

		}
	}
	else {
		printf("\033[31mInvalid choice!\033[0m\n");
		return;
	}
	/* Search the node to delete */
	del=*head;
	prev=NULL;
	while(del){
		if(del->rollno == roll)
			break;
		prev=del;
		del=del->next;
	}
	if(del==NULL){
		printf("\033[31mRoll number not found!\033[0m\n");
		return;
	}
	/* unlink the node */
	if(prev  == NULL)
		*head=del->next;
	else
		prev->next=del->next;
	free(del);
	printf("\033[32mstudent record deleted successfully!\033[0m\n");

}
