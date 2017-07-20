#include<stdio.h>
#include<stdlib.h>
#include"packing.h"

int main(int argc, char** argv){
//	if(argc != 3){
//		fprintf(stderr, "Incorrect number of arguments.\n");
//		return EXIT_FAILURE;
  //	}	

	FILE * input = fopen(argv[1], "r");
	tnode * tree = buildtree(input);
	int totalheight = 0;
	int totalwidth = 0;
	packtree(tree, totalwidth, totalheight);
//	printTree(tree);
	freetree(tree);	
	return 0;	
}

