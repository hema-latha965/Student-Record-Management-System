#ifndef STUDENT_H
#define STUDENT_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>


typedef struct student
{
int rollno;
char name[30];
float percentage; 
struct student *next;  //self-referential structure
}SLL;

/* Function declarations */
 
void load_students(SLL **);
void add_record(SLL **);
void delete_record(SLL **);
void show_records(SLL *);
void modify_record(SLL *);
void save_records(SLL *);
void sort_records(SLL **);
void delete_all(SLL **);
void reverse_list(SLL **);
void free_list(SLL **);

#endif
