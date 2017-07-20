#include<stdio.h>
#include<stdlib.h>

typedef struct tnode{
	char def;
	int label;
	double width;
	double length;	
	double xcoord;
	double ycoord;
	struct tnode * right;
	struct tnode * left;
}tnode;

typedef struct stack{
	tnode * data;
	struct stack * next;
}stack;

typedef struct stacktop{
	stack * head;
}stacktop;

void printTree(tnode* root);

tnode * buildtree(FILE * input);

void freetree(tnode * tree);

void packtree(tnode * tree, int ,int);
