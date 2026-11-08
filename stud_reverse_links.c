#include"student.h"
void reverse_list(SLL **head){
printf("\033[34m**********************\033[0m\n");
if(*head==0){ 
printf("\033[31mNo student records available!\033[0m\n");
printf("\033[34m***************************\033[0m\n");
return;
}

SLL *prev=NULL;
SLL *curr=*head;
SLL *next;

while(curr != NULL){
next=curr->next;
curr->next=prev;
prev=curr;
curr=next;
}

*head=prev;

printf("\033[32mLinked list reversed successfully!\033[0m\n");
show_records(*head);
}
