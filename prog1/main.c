#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sorting.h"

int main(int argc, char * * argv){
  //argv[0]: excecutable, ./proj1
  //argv[1]: type of sort, i or s
  //argv[2]: input file name, #.b
  //argv[3]: output file name, #seq.t
  //argv[4]: output file name, #s.b

  clock_t start; 
  clock_t end;

  double time; //io time
  double stime; //sorting time
  long *Array; //Array of numbers
  int length; //number of values
  double Comps; //number of comparisons
  double Moves; //number of moves
  int seq; //numbers in sequence
  int stored; //numbers stored  


  start = clock();
  Array = Load_From_File( argv[2], &length); 
  seq = Print_Seq(argv[3], length);
  end = clock();
  time = ((double)(end - start));

  if(argv[1] == "i"){
	start = clock();
	Shell_Insertion_Sort( Array, length, &Comps, &Moves);
  	end = clock();
	stime = ((double)(end - start));
  }
  if(argv[1] == "s"){
	start = clock();
	Shell_Selection_Sort( Array, length, &Comps, &Moves);	
   	end = clock();
	stime = ((double)(end - start));
  } 
  
  Print_Seq( argv[3], length);
  start = clock();
  stored = Save_To_File( argv[4], Array, length);
  end = clock();
  time += ((double)(end - start));

  printf("Number of long integers read: %d\n", length);
  printf("Number of long integers stored: %d\n", stored);
  printf("Length if sequence: %d\n", seq);
  printf("Number of comparisons: %le", Comps);
  printf("Number of moves: %le", Moves);
  printf("I/O time: %le", time);
  printf("Sorting time: %le", stime);

  free(Array);
  return 0;

}
