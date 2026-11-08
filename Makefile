
student: stud_main.o stude_add.o stud_del.o student_show.o student_mod.o stud_save.o stud_sort.o stud_delete_all.o stud_reverse_links.o stud_free.o
	cc stud_main.o stude_add.o stud_del.o student_show.o student_mod.o stud_save.o stud_sort.o stud_delete_all.o stud_reverse_links.o stud_free.o -o student

stud_main.o: stud_main.c
	cc -c stud_main.c

stude_add.o: stude_add.c
	cc -c stude_add.c

stud_del.o: stud_del.c
	cc -c stud_del.c

student_show.o: student_show.c
	cc -c student_show.c

student_mod.o: student_mod.c
	cc -c student_mod.c

stud_save.o: stud_save.c
	cc -c stud_save.c

stud_sort.o: stud_sort.c
	cc -c stud_sort.c

stud_delete_all.o: stud_delete_all.c
	cc -c stud_delete_all.c

stud_reverse_links.o: stud_reverse_links.c
	cc -c stud_reverse_links.c

stud_free.o: stud_free.c
	cc -c stud_free.c

clear:
	@echo "Cleaning up......."
	@rm -f *.o student exe

.PHONY: clear
