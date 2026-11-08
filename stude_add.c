#include "student.h"

void add_record(SLL **head)
{
    SLL *new, *last;
    int roll = 1;

    new= malloc(sizeof(SLL));

    if(new == NULL)
    {
        printf("\033[31mMemory allocation failed!\033[0m\n");
        return;
    }

    printf("\033[36mEnter student name: \033[0m");
    scanf(" %[^\n]",new->name);

    do
    {
        printf("\033[36mEnter percentage: \033[0m");

        if(scanf("%f",&new->percentage) != 1)
        {
            printf("\033[31mInvalid input!\033[0m\n");
            while(getchar() != '\n');
            continue;
        }

        if(new->percentage < 0 || new->percentage > 100)
             printf("\033[33mPercentage must be between 0 and 100!\033[0m\n");

    }while(new->percentage < 0 || new->percentage > 100);

    /* Find smallest unused roll number */

    while(1)
    {
        last = *head;

        while(last != NULL)
        {
            if(last->rollno == roll)
                break;

            last = last->next;
        }

        if(last == NULL)
            break;

        roll++;
    }

    new->rollno = roll;
    new->next = NULL;

    /* Insert node at the end */

    if(*head == NULL)
        *head = new;
    else {
        last = *head;

        while(last->next != NULL)
            last = last->next;

        last->next = new;
    }

    printf("\n\033[32mStudent record added successfully!\033[0m\n");
    printf("\033[32mAssigned Roll Number: %d\033[0m\n",roll);
}
