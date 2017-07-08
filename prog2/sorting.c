#include<stdlib.h>
#include<stdio.h>
#include"sorting.h"

int power(int a, int b);
int* makeseq(int Size, int *length);
void swap(long * a, long * b);

Node *Load_From_File(char * Filename){
  FILE * input = fopen(Filename,"rb");
  if(input == NULL){
	printf("open error");
  }

  Node* head = malloc(sizeof(Node));
  List begin;
  begin.node = head;
  while(fread(&(head->value), sizeof(long), 1, input) == 1){
	head->next = malloc(sizeof(Node));// 1 extra
  	head = head->next;
  }
  fclose(input);
  
  return begin.node;
}

int Save_To_File(char *Filename, Node* list){
  FILE * output = fopen(Filename, "wb");
  
  while(list->next != NULL){ 
  	fwrite(list->value, sizeof(long), 1, output);
	list = list->next;
  }
  fclose(output);  

  return 1;

}

Node* Shell_Sort(long *Array, int Size, double *N_Comp, double *N_Move){
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
  
  makeseq();

  while(seq != NULL){ //for every value in the seqence
	shell = list.value; //length of shell maybeeeeeeeeeeeeeeeeeeeeeeeee
		while(linkedlist != NULL){//selectionsort
			selectionsort(linkedlist->*node);
			freelist

	}
	seq = seq->next;
  }

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

Node* makeseq(int Size){
  int lev = 0;
  int large = 0;
  int i = 0; //position in array
  Node * curnode; //initialize sequence
  Node * head = curnnode;
  int p;
  int q;
  long temp;

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
		curnode->value = temp;
		curnode->next = malloc(sizeof(Node));
		curnode = curnode->next;
		q++;
	}		
	lev++;
	
  }
  
  return head;

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
