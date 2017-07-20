CFLAGS = -Wall -Wshadow -O3 -Werror -g 
GCC = gcc $(CFLAGS)
OBJS = packing_main.o packing.o 
VALGRIND = valgrind --tool=memcheck --leak-check=full --show-reachable=yes -v 

.c.o: 
	$(GCC) -c $*.c

all: $(OBJS) packing.h
	$(GCC) $(OBJS) -o proj3

test: all
	./proj3 pa3_samples/r0_po.txt outputs/r0.flr
	./proj3 pa3_samples/r6_po.txt outputs/r6.flr
	  
compare: all
	diff pa3_samples/r0_po.flr outputs/r0.flr
	diff pa3_samples/r6_po.flr outputs/r6.flr
 
memory: all
	$(VALGRIND) ./proj3 pa3_samples/r0_po.txt #outputs/r6.flr
	
clean:
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f proj3

tree: all
	./proj3 pa3_samples/r6_po.txt
	./proj3 pa3_samples/r0_po.txt
