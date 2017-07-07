#include<stdlib.h>
#include<stdio.h>
#include"sorting.h"

int power(int a, int b);
int* makeseq(int Size, int *length);
void swap(long * a, long * b);

long *Load_From_File(char * Filename,int *Size){
  FILE * input = fopen(Filename,"rb");
  if(input == NULL){
	printf("open error");
  }
  
  fseek(input, 0, SEEK_END);
  long fpos = ftell(input);
  *Size = (int)(fpos / sizeof(long)); //number of ints
  rewind(input); // jump to beginning 
  long * array = malloc(sizeof(long) * (*Size));
  fread(array, sizeof(long), *Size, input);
  fclose(input);
  
  return array;
}

int Save_To_File(char *Filename, long *Array, int Size){
  FILE * output = fopen(Filename, "wb");
  
  int num = fwrite(Array, sizeof(long), Size, output);
  fclose(output);  

  return num;

}

void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_Move){
  int i;
  int j;
  int k;
  int l;
  int shell; //shell gap
  int temp_low;  //lowerst index
  int length; //length of sequence 
  int * seq = makeseq(Size, &length);
  *N_Comp = 0;
  *N_Move = 0;
  
  for(j = length - 1 ;  j >= 0; j--){ //for every value in the array
 	shell = seq[j]; //length of shell
  	for(i = 0;  i < shell; i++){ //for every value in the shell
		for(k = i; k < (Size - shell); k += shell){
			*N_Comp = *N_Comp + 1;
			if(Array[k + shell] < Array[k]){
				swap(&Array[k + shell], &Array[k]);
				*N_Move = *N_Move + 3;			
			}
		}
		for((k = Size-shell-1); k >= i; k -= shell){ //insertion sort      
			temp_low = Array[k];
			l = k;
			while(Array[l ] > temp_low){
				Array[l] = Array[l - 1];
				l = l - 1;
			}
		Array[l] = temp_low;
		}
		
	}
  }
  free(seq);
 
}

void Shell_Selection_Sort(long *Array, int Size, double *N_Comp, double *N_Move){
  int i;
  int j;
  int k;
  int l;
  int shell;
  int temp_low;
  int length; //length of sequence 
  int * seq = makeseq(Size, &length);
  *N_Comp = 0;
  *N_Move = 0;
  
  for(j = length - 1 ;  j >= 0; j--){ //for every value in the array
 	shell = seq[j]; //length of shell
  	for(i = 0;  i < shell; i++){ //for every value in the shell
		for(k = i; k < Size; k += shell){ //selection sort      
			temp_low = k; 
			for(l = k; l < Size; l += shell){
				*N_Comp = *N_Comp + 1;
			 	if(Array[l] < Array[temp_low]){
					temp_low = l;
				}
			}
			if(temp_low != k){
				swap(&Array[temp_low], &Array[k]);
				*N_Move = *N_Move + 3;
			}
//backwards
		}
	}
  }
  free(seq);
 
}
int Print_Seq(char *Filename, int Size){
  int length;
  int i;
  FILE * output = fopen(Filename, "w");
  int * seq = makeseq(Size, &length);

  for(i = 0; i < length; i++){
  	fprintf(output,"%d\n", seq[i]);

  }

  fclose(output);
  free(seq);
  return length;
}

int* makeseq(int Size, int * length){
  int lev = 0;
  int large = 0;
  int i = 0; //position in array
  int *seq = NULL; //initialize sequence
  int p;
  int q;
  int temp;

  while(large < Size){
	q = 0;
	for(p = lev; p >= 0; p--){		
		temp = power(2,p) * power(3,q);
		if(temp > large){
			large = temp;
			if(large >= Size){
				break;
			}
		}
		seq = realloc(seq, ((i + 1) * sizeof(int)));
		seq[i] = temp;
		q++;
		i++;
	}		
	lev++;
	
  }
  *length = i;
  return seq;

}
 //power function
int power(int a, int b){

  int i;
  int num = 1;
  if(b == 0){
	return 1;
  }
  for(i = 0; i < b; ++i){
	num *= a;
  }

  return num;
}


//swap function
void swap(long * Array1, long * Array2){
  long temp = *Array1;
  *Array1 = *Array2;
  *Array2 = temp;
}
