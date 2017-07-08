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

  Node* head = NULL; //head of the list
  Node* cur = NULL;
  long temp = 0; //number is stored

  while(fread(&temp, sizeof(long), 1, input) == 1){
  	cur = malloc(sizeof(Node));
	cur->value = temp;
	cur->next = head;
	head = cur;
	printf("\n%ld",cur->value);
  }
printf("diwjewh");
  fclose(input);
  
  return head;
}

int Save_To_File(char *Filename, Node* list){
  FILE * output = fopen(Filename, "wb");
  
  while(list != NULL){ 
  	fwrite(&list->value, sizeof(long), 1, output);
	printf("\n%ld",list->value);
	list = list->next;
  }
  fclose(output);  

  return 1;

}

Node* Shell_Sort(Node *head){
  Node* temp = head; //temporary head
  int ct = 0; //num of longs


  while(head != NULL){
	temp = temp->next;
	ct++; // might be behind 1
  }
  printf("\n%d", ct);
//  Node* seq = makeseq(ct);
  
  return 0; 
}
/*
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

void buildlist(){



*/
