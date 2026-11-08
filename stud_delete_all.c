#include"student.h"
void delete_all(SLL **head){
printf("\n\033[34m*********************\033[0m\n");
if(*head == NULL){
printf("\033[31mNo student records available!\033[0m\n");
return;
}

SLL *del=*head;
int c=1;
while(del){
*head=del->next;
printf("\033[33mNode position:%d deleted\033[0m\n",c++);
sleep(1);
free(del);
del=*head;
}
printf("\033[32mAll records deleted successfully!\033[0m\n");
printf("\033[34m***************************\033[0m\n");
}
