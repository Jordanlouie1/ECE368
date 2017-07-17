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
  Node *head; //head of unsorted list
//  Node *sorted; //head of sorted list

  //load output
  start = clock();
  head = Load_From_File(argv[1]); 
  end = clock();
  iot = ((double)(end - start));
 /* 
  sorted = Shell_Sort(head);
*/
  start = clock();
  Save_To_File (argv[2], head);
  end = clock();
  iot += ((double)(end - start));


  printf("\nIO Time: %le\n", iot);
  printf("%ld", head->value);

  return 0;

}
