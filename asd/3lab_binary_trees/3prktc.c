#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
	struct treeNode * left;
	int key;
	struct treeNode * right;
} tree;

tree* addNode(tree*, int);
tree * createTreeNode(int);
void freeTree(tree**);

void preorder(tree*); 	
void inorder(tree*); 	
void postorder(tree*);
void levelorder(tree*);
void rightKnots(tree*, int, int *, int*);

int main(int argc, char const *argv[]) {
	tree * root = NULL;
	root = addNode(root, 877);
	root = addNode(root, 419);
	root = addNode(root, 752);
	root = addNode(root, 794);
	root = addNode(root, 308);
	root = addNode(root, 462);
	root = addNode(root, 913);
	root = addNode(root, 690);
	root = addNode(root, 604);
	root = addNode(root, 899);
	root = addNode(root, 802);
	root = addNode(root, 207);
	root = addNode(root, 594);
	root = addNode(root, 164);
	root = addNode(root, 413);
	root = addNode(root, 25);
	root = addNode(root, 581);
	root = addNode(root, 240);
	root = addNode(root, 601);
	root = addNode(root, 161);
	printf("======= Preorder ========\n");
	preorder(root); 	// P->L->R
	printf("=========================\n");
	printf("======= Inorder=========\n");
	inorder(root); 	// L->P->R
	printf("=========================\n");
	printf("======= Postorder =======\n");
	postorder(root); 	// L->R->P
	printf("=========================\n");
	printf("======= Levelorder ======\n");
	levelorder(root); 	// L->R->P
	printf("=========================\n");
	printf("===== AllRightKnots =====\n");

	int max_level = 0;
	int placeh = 0;
	
    rightKnots(root, 1, &max_level, &placeh);
    printf("\n====================\n");
    printf("Summ for all right knots: %d\n",placeh);
	
	freeTree(&root);

	return 0;
}

tree* addNode(tree* root, int key) {
	if (root == NULL) {
		root = createTreeNode(key);
	} else {
		if (key < root->key) {
			root->left = addNode(root->left, key);
		} else {
			root->right = addNode(root->right, key);
		}
	}
	return root;
}

tree * createTreeNode(int key) {
	tree * newTreeNode = (tree*) malloc (sizeof(tree));
	if (newTreeNode == NULL) {
		printf("out of memory \n");
		exit(1);
	}
	newTreeNode->key = key;
	newTreeNode->left = NULL;
	newTreeNode->right = NULL;
	return newTreeNode;
}

void preorder(tree* root) { 
	if (root != NULL) {
		printf("%d\n", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(tree* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d\n", root->key);
		inorder(root->right);
	}
}

void postorder(tree* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->key);
	}
}

void levelorder(tree* root){
	if (root != NULL) {
		printf("%d\n", root->key);
		
		if (root->left != NULL) {
			levelorder(root->left);
		}	

		if (root->right != NULL) {
			printf("%d\n", root->right->key);
		}
	}
}

void rightKnots(tree *root, int level, int *max_level,int *summurize) {
    if (root != NULL) { 
    	   	if (*max_level < level) {
       		printf("%d\n", root->key);
			*summurize = *summurize + root->key;
        	*max_level = level;
   		}
 
    	rightKnots(root->right, level+1, max_level, summurize);
    	rightKnots(root->left, level+1, max_level, summurize);
    }
}

void freeTree(tree** root) {
	if (*root != NULL) {
		freeTree(&((*root)->left));
		freeTree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}