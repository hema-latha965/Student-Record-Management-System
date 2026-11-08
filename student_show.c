#include"student.h"
void show_records(SLL *head){
if(head==NULL){
printf("\033[31mNo student records available!\033[0m\n");
return;
}
printf("\n\033[36m");
printf("\n--------------------------------------------------\n");
printf("              STUDENT RECORDS\n");
printf("--------------------------------------------------\n");
printf("\033[33m");
printf("Roll No.       Name              Percentage\n");
printf("\n--------------------------------------------------\n");
printf("\033[0m");

while(head){
printf("\033[32m");
printf("%-15d %-18s %.2f\n",head->rollno,head->name,head->percentage);
printf("\033[0m");

head=head->next;
}
printf("\033[36m");
printf("--------------------------------------------------\n");
printf("\033[0m");

}
