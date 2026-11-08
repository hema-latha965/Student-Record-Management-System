#include"student.h"

void sort_records(SLL **head){
	printf("\033[34m**************************\033[0m\n");
	if(*head==0){
		printf("\033[31mNo records found!\033[0m\n");
		printf("\033[34m*********************************\033[0m\n");
		return;
	}
	SLL *p1,*p2;
	int roll;
	char name[30],ch;
	float percentage;

	printf("\033[36mN/n : Sort with name\n");
	printf("P/p : Sort with percentage\n");
	printf("Enter your choice: \033[0m");
	scanf(" %c", &ch);

	if(ch == 'N' || ch == 'n'){
		p1=*head;
		while(p1->next != NULL){
			p2=p1->next;
			while(p2!=NULL){
				if(strcmp(p1->name, p2->name)>0){
					roll=p1->rollno;
					p1->rollno = p2->rollno;
					p2->rollno = roll;

					strcpy(name,p1->name);
					strcpy(p1->name, p2->name);
					strcpy(p2->name,name);

					percentage=p1->percentage;
					p1->percentage=p2->percentage;
					p2->percentage=percentage;
				}
				p2=p2->next;
			}
			p1=p1->next;
		}
	}
	else if(ch == 'P' || ch == 'p') {
		p1=*head;
		while(p1->next != NULL) {
			p2 = p1->next;

			while(p2 != NULL) {

			   if(p1->percentage < p2->percentage) {

					roll = p1->rollno;
					p1->rollno = p2->rollno;
					p2->rollno = roll;

					strcpy(name, p1->name);
					strcpy(p1->name, p2->name);
					strcpy(p2->name, name);

					percentage = p1->percentage;
					p1->percentage = p2->percentage;
					p2->percentage = percentage;
				}

				p2 = p2->next;
			}

			p1 = p1->next;
		}
	}
	else {
		printf("\033[31mInvalid choice\033[0m\n");
		return;
	}
	printf("\033[32mRecords sorted successfully!\033[0m\n");
	show_records(*head);
}
