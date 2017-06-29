CFLAGS = -std=c99 -g -Wall -Wshadow -Werror -O3
GCC = gcc $(CFLAGS)
OBJS = main.c sorting.c sorting.h
VALGRIND = valgrind --tool=memcheck --leak-check=yes 

.c.o: 
	$(GCC) -c $*.c

all: $(OBJS)
	$(GCC) $(OBJS) -o proj1

test: all
	./proj1 i test/15.b test/15_seq.t test/15s.b
	./proj1 i test/1000.b test/1000_seq.t test/1000s.b
	./proj1 i test/10000.b test/10000_seq.t test/10000s.b
	
	./proj1 s test/15.b test/15_seq.t test/15s.b
	./proj1 s test/1000.b test/1000_seq.t test/1000s.b
	./proj1 s test/10000.b test/10000_seq.t test/10000s.b
	
	./proj1 i test/10000.b test/10000_seq.t test/10000s.b
	./proj1 i test/100000.b test/100000_seq.t test/100000s.b
	./proj1 i test/1000000.b test/1000000eq.t test/1000000s.b
	
	./proj1 s test/10000.b test/10000_seq.t test/10000s.b
	./proj1 s test/100000.b test/100000_seq.t test/100000s.b
	./proj1 s test/1000000.b test/1000000eq.t test/1000000s.b
	



memory:
	$(VALGRIND) ./proj1 i test/15.b test/15_seq.t test/15s.b	
	$(VALGRIND) ./proj1 s test/15.b test/15_seq.t test/15s.b
clean:
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f proj1
