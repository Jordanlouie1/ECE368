#include<stdlib.h>
#include<stdio.h>
#include"sorting.h"

int power(int a, int b);
Node* makeseq(int Size);
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
  }
  fclose(input);
  
  return head;
}

int Save_To_File(char *Filename, Node* list){
  FILE * output = fopen(Filename, "wb");
  int stored = 0; 
  Node * curnode = list;

  while(curnode != NULL){ 
  	fwrite(&curnode->value, sizeof(long), 1, output);
	curnode = curnode->next;
	stored++;
  }

  fclose(output);  

  return stored;

}

Node* Shell_Sort(Node *head){
  Node* temp = head; //temporary head
  int ct = 0; //num of longs
  int row = 0;
  while(temp != NULL){
	temp = temp->next;
	ct++; 
  }
  temp = head;
  Node* seq = makeseq(ct);
  Node* freedom = seq;
  long gap = 0;

  //pop and free
  while(seq != null){
  	gap = seq->value;
	for(row = 0; row < gap; row++){
  //create k lists
  		
  		
  //sort each k
  

	
  }

  return seq; 
}

Node* makeseq(int Size){
  int lev = 0;
  int large = 0;
  Node * curnode = NULL; //initialize sequence
  Node * head = curnode;
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
		curnode = malloc(sizeof(Node));
		curnode->value = temp;
		curnode->next = head;
		head = curnode;
		q++;
	}		
	lev++;
	
  }
	
  return curnode;

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





