#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sorting.h"

int main(int argc, char ** argv){
  //argv[0]: excecutable, ./proj2
  //argv[1]: input file name, #.b
  //argv[2]: output file name, #.b

  clock_t start; 
  clock_t end;

  double iot = 0; //io time
  double st = 0; //sorting time
  //int stored;
  Node *head; //head of list

  //load output
  start = clock();
  head = Load_From_File(argv[1]); 
  end = clock();
  iot = ((double)(end - start));

  //insertion 
  start = clock();
  Shell_Sort(head);
  end = clock();
  st = ((double)(end - start));
  
  //save output
  start = clock();
  Save_To_File(argv[2], head);
  end = clock();
  iot += ((double)(end - start));
  
  printf("\nI/O time: %le\n", (iot / CLOCKS_PER_SEC));
  printf("Sorting time: %le\n", (st / CLOCKS_PER_SEC));
 
  free(head);
  return 0;

}
