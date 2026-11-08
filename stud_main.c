#include"student.h"

int main(){
	SLL *headptr=NULL;
	char ch,op;
        
        printf("MAIN STARTED\n");
        fflush(stdout);
	
        load_students(&headptr);
        
        printf("LOAD COMPLETED\n");
        fflush(stdout);

	while(1){
                printf("\n\033[36m");
                printf("========================================\n");
		printf("          STUDENT RECORD MANAGEMENT\n");
                printf("========================================\n");
                printf("\033[32m");
                printf("          Welcome to the System!\n");
                printf("\033[33m");
                printf("----------------------------------------\n");
		printf("a/A : Add new record\n");
		printf("d/D : Delete a record\n");        
		printf("s/S : Show the list\n");
		printf("m/M : Modify a record\n");
		printf("v/V : Save records\n");
		printf("t/T : Sort the list\n");
		printf("l/L : Delete all records\n");
		printf("r/R : Reverse the list\n");
                printf("e/E : Exit\n");
                printf("----------------------------------------\n");
                printf("\033[0m");

		printf("\033[36mEnter your choice: \033[0m");
		scanf(" %c",&ch);

		switch(ch){
			case 'a':
			case 'A': add_record(&headptr);
				  break;

			case 'd':
			case 'D': delete_record(&headptr);
				  break;

			case 's':
			case 'S': show_records(headptr);
				  break;

			case 'm':
			case 'M': modify_record(headptr);
				  break;

			case 'v':
			case 'V': save_records(headptr);
				  break;

			case 't':
			case 'T': sort_records(&headptr);
				  break;

			case 'l':
			case 'L': delete_all(&headptr);
				  break;

			case 'r':
			case 'R': reverse_list(&headptr);
				  break;

			case 'e': 
			case 'E': printf("\n\033[33mS/s : Save and Exit\n");
				  printf("E/e : Exit without saving\n");
				  printf("\033[36Enter your choice: \033[0m");
				  scanf(" %c",&op);

				  if(op=='s' || op=='S')
					  save_records(headptr);
				  else if(op!='e' && op!='E')
				  {
					  printf("Invalid choice\n");
					  break;
				  }

				  free_list(&headptr);
				  printf("\033[32mProgram terminated successfully!\033[0m\n");
				  return 0;

			default: printf("\033[31mInvalid choice! Please try again.\033[0m\n");
                                 break;

		}
	}
}
