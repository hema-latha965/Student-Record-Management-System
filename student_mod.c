#include"student.h"
void modify_record(SLL *head){
        SLL *temp;
        int roll,found=0,valid=0;
        float search_per,new_per;
	char ch,name[30];

	if(head==NULL){
		printf("\033[31mNo student records available!\033[0m\n");
		return;
	}

	printf("\n\033[36mEnter which record to search for modification\n");
	printf("R/r : Search by roll number\n");
	printf("N/n : Search by name\n");
	printf("P/p : Search by percentage\n");
	printf("Enter your choice: \033[0m");
	scanf(" %c", &ch);

	/* Search by roll number */
	if(ch == 'R' || ch == 'r'){
		printf("\033[36Enter roll number: \033[0m");
		scanf("%d",&roll);
	}
	/* Search by name */
	else if(ch == 'N' || ch == 'n') {
		printf("\033[36mEnter student name: \033[0m");
		scanf(" %[^\n]", name);

		temp=head;
		while(temp){
			if(strcmp(temp->name,name)==0){
				found++;
				roll=temp->rollno;
				printf("\033[33mRoll No: %d  Name: %s  Percentage: %.2f\033[0m\n",temp->rollno,temp->name,temp->percentage);
			}
			temp=temp->next;
		}
		if(found==0){
			printf("\033[31mstudent name not found!\033[0m\n");
			return;
		}
		if(found>1){
			printf("\033[36mEnter roll number to modify: \033[0m");
			scanf("%d",&roll);
			temp = head;
			while(temp != NULL) {
				if(temp->rollno == roll && strcmp(temp->name, name) == 0) {
					valid = 1;
					break;
				}
				temp = temp->next;
			}
			if(valid==0){
				printf("\033[31mInvalid roll number for the entered name!\033[0m\n");
				return;
			}
		}
	}
	/* Search by percentage */
	else if(ch == 'P' || ch == 'p') {
			printf("\033[36mEnter percentage: \033[0m");
			scanf("%f", &search_per);
                        temp = head;

			while(temp != NULL) {
				if(temp->percentage == search_per) {
					found++;
					roll = temp->rollno;
                                        printf("\033[33mRoll No: %d  Name: %s  Percentage: %.2f\033[0m\n",temp->rollno, temp->name, temp->percentage);
				}
                                temp = temp->next;
			}
                        if(found == 0) {
				printf("\033[31mPercentage not found!\033[0m\n");
				return;
			}
                        if(found > 1) {
				printf("\033[36mEnter roll number to modify: \033[0m");                                                 
				scanf("%d", &roll);

				temp = head;

				while(temp != NULL) {
					if(temp->rollno == roll &&
					temp->percentage == search_per){
						valid = 1;
						break;
					}

					temp = temp->next;
				}
                                if(valid == 0) {
					printf("\033[31mInvalid roll number for the entered percentage!\033[0m\n");
					return;
				}
			}
		}
		else {
			printf("\033[31mInvalid choice!\033[0m\n");
			return;
		}

		/* find the selected record */
		temp=head;
		while(temp){
			if(temp->rollno == roll)
				break;

			temp=temp->next;
		}
		if(temp == NULL){
			printf("\033[31mRoll number not found\033[0m\n");
			return;
		}
		/* Display current details */
		printf("\n\033[33mCurrent Student Details:\033[0m\n");
		printf("Roll No: %d\n",temp->rollno);
		printf("Name: %s\n",temp->name);
		printf("Percentage: %.2f\n",temp->percentage);

		/*Update name */
		printf("\n\033[36mEnter  updated name: \033[0m");
		scanf(" %[^\n]",temp->name);

		/*Update percentage */
		do {
			printf("\033[36mEnter updated percentage: \033[0m");
			scanf("%f",&new_per);
			if(new_per <0 || new_per>100)
				printf("\033[31mPercentage must be between 0 and 100!\033[0m\n");
		}while(new_per < 0 || new_per > 100);
		temp->percentage=new_per;
		printf("\n\033[32mStudent record modified successfully!\033[0m\n");
}
