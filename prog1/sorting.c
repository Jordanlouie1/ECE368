#include<stdlib.h>
#include<stdio.h>

long *Load_From_File(char*Filename,int *Size){
  FILE * input = fopen(Filename, "r");

  fseek(input, 0L,SEEK_END);
  int fpos = ftell(fptr);
  *Size = fpos / sizeof(long); //number of ints
  rewind(input);

  long array = malloc(sizeof(long) * (*Size));
  fread(array, sizeof(long), *Size, input);
  
  fclose(input);
  return array;
}

int Save_To_File(char *Filename, long *Array, int Size){
  FILE * output = fopen(Filename, "w");
  
  fwrite(Array, sizeof(long), Size, output);

  fclose(output);  

  return 1;

}

void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_Move){
  int i;
  int j;
  int k;
  long temp_r = malloc(sizeof(long) * Size);  

  for(j = k ; Size - 1; j++){
 	temp_r = r[j];
  	for(i = j; 1; i--){
		*N_Comp++;
		if(Array[i - 1] > Array[i]){
			swap(&Array[i - 1], &Array[i]);
			*N_Moves = *N_Moves + 3;
		}
		else
			break;
	}
  }
  free(temp_r);
  
}

void Shell_Selection_Sort(long *Array, int Size, double *N_Comp, double *N_Move){
  int i;
  int j;
  
  for(i = Size - 1; 1; i--){
	int max_index = 0;
  	for(j = 1; i; j++){
		if(Array[j] >= Array[max_index]){
			max_index = j;
		}
		swap(&Array[i], &Array[max_index]);
	}

  }

}

int Print_Seq(char *Filename, int Size){

  printf("Number of long integers read: %d\n", read);
  printf("Number of long integers stored: %d\n", strd);
  printf("Length if sequence: %d\n", len);
  printf("Number of comparisons: %le", comps);
  printf("Number of moves: %le", moves);
  printf("I/O time: %le", time);
  printf("Sorting time: %le", stime);

}

void swap(long *Array1, long *Array2){
  long temp = *Array1;
  *Array1 = *Array2;
  *Array2 = temp
}
