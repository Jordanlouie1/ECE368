#include<stdio.h>
#include<stdlib.h>
#include"packing.h"
tnode * pop(stacktop* current){
	stack* freenode = current->head;
	tnode * tn = current->head->data;
	current->head = current->head->next;
	free(freenode);
	return tn;
}

void push(tnode* newdata, stacktop* stk){
	stack * newnode = malloc(sizeof(stack));
	newnode->data = newdata;
	newnode->next = stk->head;
	stk->head = newnode;
}


tnode * buildtree(FILE * input){
	int lab;
	char c;
	double width;
	double length;
	stacktop * head = malloc(sizeof(stacktop));
	int nodes = 0;

	while((c = fgetc(input)) != EOF){
		if(c == 'H' || c == 'V'){
			tnode * newLeaf = malloc(sizeof(tnode));
			newLeaf->def = c;
			newLeaf->right = pop(head);
			newLeaf->left = pop(head);
			push(newLeaf, head);

		}
		else if(c == '\n'){
			continue;
		}
		else{
			fseek(input, -1, SEEK_CUR);
			int valid = fscanf(input,"%d(%lf,%lf)", &lab, &width, &length);
			if( valid > 0)
				nodes = nodes + 1;
			tnode * newNode = malloc(sizeof(tnode));
			newNode->def = c; //nullllllllllllllllllllllll
			newNode->label = lab;
			newNode->width = width;
			newNode->length = length;
			push(newNode, head);
			printf("%d (%le, %le) \n", head->head->data->label, head->head->data->width, head->head->data->length);


		}

	}

	tnode* root = pop(head);
	fclose(input);
	free(head);

	return root;

}

void subbox(tnode * tree){

	int wid = 0;
	int len = 0;

	if(tree->def == 'V'){
		tree->left->xcoord = wid;
		wid = wid + tree->left->width;
		tree->right->xcoord = wid;
		wid = wid + tree->right->width;
		if(tree->left->length > tree->right->length)
			len = tree->left->length;
		else
			len = tree->right->length;
	}
	else if(tree->def == 'H'){
		tree->left->ycoord = len;
		len = len + tree->left->length;
		tree->right->ycoord = len;
		len = len + tree->right->length;
		if(tree->left->width > tree->right->width)
			wid = tree->left->width;
		else
			wid = tree->right->width;
	}
	else{
		return;
	}
	tree->width = wid;
	tree->length = len;
}

void freetree(tnode * tree) {
        if (tree == NULL)
	       	return;
	freetree(tree -> left);
        freetree(tree -> right);
        free(tree);
        return;
}




void packtree(tnode* tree, int wid, int len){

	if (tree->left == NULL || tree->right == NULL)
		return;

	packtree(tree->left, wid, len);
	packtree(tree->right, wid, len);

	subbox(tree);

	wid = 0;
	len = 0;
/*	if(tree->def == 'V'){
		tree->left->xcoord = wid;
		wid = wid + tree->left->width;
		tree->right->xcoord = wid;
		wid = wid + tree->right->width;
	}
	else if(tree->def == 'H'){
		tree->left->ycoord = len;
		len = len + tree->left->length;
		tree->right->ycoord = len;
		len = len + tree->right->length;
	}
	else{
		return;
	}
*/

}

void printTree(tnode* node){

	if (node == NULL)
		return;

	// first print data of node /
//	printf("%c ", node->def);  

	// then recur on left sutree /
	printTree(node->right);  
//	printf("%c ", node->def);  


	// now recur on right subtree /
	printTree(node->left);
	printf("%c ", node->def);  

	free(node);

}    

