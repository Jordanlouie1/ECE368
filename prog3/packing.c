#include<stdio.h>
#include<stdlib.h>

tnode * buildtree(FILE * input){i
/*	int lines; // lines in file

	while(fgetc(input) != EOF){
		lines = lines + 1;
	}

	rewind(input);
*/

	char c;
	int lab;
	double width;
	double height;
	double xcoord;
	double ycoord;

	while((fgetc(input) = c) != EOF){
		if(c == 'H' || c == 'V'){
			tnode * newLeaf = malloc(sizeof(tnode));
			newLeaf->split = c;
			newLeaf->right = pop(stack);
			newLeaf->left = pop(stack);
			stack = push(stack, newLeaf);

		}
		else{
			lab = c - '0';
			fscanf(input, ("(%le,%le)"), width, height);
			Node * newNode = malloc(sizeof(Node));
			newNode->label = lab;
			newNode->width = width;
			newNode->length = height;
			stack = push(stack, newNode);
		}
		c = fgetc(input);//eof at end???			

	}

}





