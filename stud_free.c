#include"student.h"
void free_list(SLL **head)
{
SLL *temp;
while(*head != NULL){
temp=*head;
*head = (*head)->next;
free(temp);
}
printf("\033[32mMemory released successfully!\033[0m\n");
}
