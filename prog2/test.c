#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

  
typedef struct Node{
	long value;
	struct Node* next;
}Node;



  int lev = 0;
  int large = 0;
  int i = 0; //position in array
  int * seq = NULL;
  int p;
  int q;
  int Size = 15;
  int temp;
  Node * curnode;
  printf("\nEnter Size:");
  scanf("%d", &Size);

  while(large < Size){
	q = 0;
	for(p = lev; p >= 0; p--){		
		temp = pow(2,p) * pow(3,q);
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
	printf("%ld\n",curnode->next->value);
	}		
	lev++;
	
  }

  printf("\n%d\n", i);

}
 




