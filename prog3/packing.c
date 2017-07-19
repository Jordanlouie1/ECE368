#include<stdio.h>
#include<stdlib.h>
#include"packing.h"
tnode * pop(stack* current){
	stack* freenode = current;
	tnode * tn = current->data;
	current = current->next;
	free(freenode);
	return tn;
}

stack * push(tnode* newdata, stack* stk){
	stack * newnode = malloc(sizeof(stack));
	newnode->data = newdata;
	newnode->next = stk;
	return newnode;
}


tnode * buildtree(FILE * input){
	int lab;
	char c;
	double width;
	double height;
	stack * head = NULL;

	while((c = fgetc(input)) != EOF){
		if(c == 'H' || c == 'V'){
			tnode * newLeaf = malloc(sizeof(tnode));
			newLeaf->def = c;
			newLeaf->right = pop(head);
			newLeaf->left = pop(head);
			head = push(newLeaf, head);

		}
		else if(c == '\n'){
			continue;
		}
		else{
			fseek(input, -1, SEEK_CUR);
			int valid = fscanf(input,"%d(%lf,%lf)", &lab, &width, &height);
			if( valid > 0)
				continue;
			tnode * newNode = malloc(sizeof(tnode));
			newNode->def = c;
			newNode->label = lab;
			newNode->width = width;
			newNode->length = height;
			head = push(newNode, head);
		}

	}

	fclose(input);

	return pop(head);

}

void printTree(tnode* node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	printf("%c ", node->def);  

	/* then recur on left sutree */
	printTree(node->left);  

	/* now recur on right subtree */
	printTree(node->right);
}    

