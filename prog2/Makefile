CFLAGS = -Wall -Wshadow -O3 -Werror  
GCC = gcc $(CFLAGS)
OBJS = main.o sorting.o 
OBJS2 = test.o sorting.o
VALGRIND = valgrind --tool=memcheck --leak-check=full --show-reachable=yes -v 

.c.o: 
	$(GCC) -c $*.c

all: $(OBJS2) sorting.h
	$(GCC) $(OBJS2) -o proj2

current: all
	./proj2 test/15.b out/15s.b

test: all
	./proj1 i 15.b 15_seq.t 15s.b
	./proj1 i 1000.b 1000_seq.t 1000s.b
	./proj1 i 10000.b 10000_seq.t 10000s.b
	./proj1 i 100000.b test/100000eq.t 100000s.b	
	./proj1 s 15.b 15_seq.t 15s.b
	./proj1 s 1000.b 1000_seq.t 1000s.b
	./proj1 s 10000.b 10000_seq.t 10000s.b
	./proj1 s 100000.b 100000_seq.t 100000s.b


compare: all
	diff 15.b giv/15.b
	diff 15_seq.t giv/15_seq.t
	diff 15s.b giv/15s.b
	diff 1000.b giv/1000.b	
	diff 1000_seq.t giv/1000_seq.t
	diff 1000s.b giv/1000s.b


memory: all
	$(VALGRIND) ./proj1 s test/15.b test/15_seq.t test/15s.b	
	$(VALGRIND) ./proj1 i test/15.b test/15_seq.t test/15s.b 
clean:
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f proj1
