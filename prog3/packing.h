#include<stdio.h>
#include<stdlib.h>
typedef struct tnode{
	int label;
	double width;
	double length;
	double height;
	double xcoord;
	double ycoord;
	tnode right;
	tnode left;
}tnode;

tnode * buildtree(FILE * input);


