#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sorting.h"

int main(int argc, char ** argv){
  //argv[0]: excecutable, ./proj1
  //argv[1]: type of sort, i or s
  //argv[2]: input file name, #.b
  //argv[3]: output file name, #seq.t
  //argv[4]: output file name, #s.b

  clock_t start; 
  clock_t end;

  double iot = 0; //io time
  double st = 0; //sorting time
  long *Array; //Array of numbers
  int length = 0; //number of values
  double Comps = 0; //number of comparisons
  double Moves = 0; //number of moves
  int seq; //numbers in sequence
  int stored = 0; //numbers stored  


  start = clock();
  Array = Load_From_File(argv[2], &length); 
  seq = Print_Seq(argv[3], length);
  end = clock();
  iot = ((double)(end - start));
  //insertion or selection 
  if(argv[1][0] == 'i'){
	start = clock();
	Shell_Insertion_Sort( Array, length, &Comps, &Moves);
  	end = clock();
	st = ((double)(end - start));
  }
  if(argv[1][0] == 's'){
	start = clock();
	Shell_Selection_Sort( Array, length, &Comps, &Moves);	
   	end = clock();
	st = ((double)(end - start));
  } 
  
  start = clock();
  stored = Save_To_File(argv[4], Array, length);
  end = clock();
  iot += ((double)(end - start));

  printf("\nNumber of long integers read: %d\n", length);
  printf("Number of long integers stored: %d\n", stored);
  printf("Length if sequence: %d\n", seq);
  printf("Number of comparisons: %le\n", Comps);
  printf("Number of moves: %le\n", Moves);
  printf("I/O time: %le\n", (iot / CLOCKS_PER_SEC));
  printf("Sorting time: %le\n", (st / CLOCKS_PER_SEC));
 
  free(Array);
  return 0;

}
