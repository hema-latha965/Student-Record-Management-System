#include"student.h"

void save_records(SLL *head){
        FILE *fp;
        printf("\033[34m*****************************************\033[0m\n");
        printf("\033[36m          SAVING STUDENT RECORDS\033[0m\n");
	fp=fopen("student.dat","w");
	if(fp == NULL)
	{
		printf("\033[31mFile opening failed!\033[0m\n");
		return;
	}
        
        if(head==NULL)
             printf("\033[33mNo records found\033[0m\n");

	while(head){
	   fprintf(fp,"%d\t%s\t%.2f\n",head->rollno,head->name,head->percentage);
           head=head->next;
	}
	printf("\033[32mData saved successfully in file\033[0m\n");
	printf("\033[34m***************************\033[0m\n");
	fclose(fp);
}

void load_students(SLL **head){
	SLL *new,*last;
	FILE *fp;
	fp=fopen("student.dat","r");
	if(fp==0){
		printf("\033[33mNo previous records found!\033[0m\n");
		return;
	}
	while(1){
		new=malloc(sizeof(SLL));
		if(new == NULL){
			printf("\033[31mMemory allocation failed!\033[0m\n");
			fclose(fp);
			return;
		}
		if(fscanf(fp,"%d\t%29[^\t]\t%f",&new->rollno,new->name,&new->percentage) != 3) {
			free(new);
			new=0;
			break;
		}
		new->next=0;
		if(*head==0)
			*head=new;
		else {
			last=*head;
			while(last->next)
				last=last->next;
			last->next=new;
		}
	}
	fclose(fp);
	printf("\033[32mstudent records loaded successfully!\033[0m\n");
}
