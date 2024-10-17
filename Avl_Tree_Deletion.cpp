#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	char name[100];
	int age;
	int height;
	Node *left, *right;
};

Node *newNode(char name[], int age){
	Node *temp = (Node*) malloc(sizeof(Node));
	
	strcpy(temp -> name, name);
	temp -> age = age;
	temp -> height = 1;
	
	temp -> left = NULL;
	temp -> right = NULL;
	
	return temp;
}

int max(int a, int b){
	return a > b ? a : b;
	//(apakah int a lebih besar dari pada int b apabila iya return a apabila tidak return b
}

int height(Node *root){
	if(root == NULL){
		return 0;
	} else {
		return root -> height;
	}
}

int balanceFactor(Node *root){
	if(root == NULL){
		return 0;
	} else {
		return height(root -> left) - height(root -> right);
	}
}

Node *leftRotate(Node *root){
	Node *rightChild = root -> right;
	Node *leftRightChild = rightChild -> left;
	
	rightChild -> left = root;
	root -> right = leftRightChild;
	
	root -> height = max(height(root -> left), height(root -> right)) + 1;
	rightChild -> height = max(height(rightChild -> left), height(rightChild -> right)) + 1;
	
	return rightChild;
}

Node *rightRotate(Node *root){
	Node *leftChild = root -> left;
	Node *rightLeftChild = leftChild -> right;
	
	leftChild -> right = root;
	root -> left = rightLeftChild;
	
	root -> height = max(height(root -> left), height(root -> right)) + 1;
	leftChild -> height = max(height(leftChild -> left), height(leftChild -> right)) + 1;
	
	return leftChild;
}

Node *rebalance(Node *root){
	int factor = balanceFactor(root);
	
	if(factor > 1){
		if(balanceFactor(root -> left) >= 0){				//Left Left Case
			return rightRotate(root);
		} else {											// Left Right Case
			root -> left = leftRotate(root -> left);
			return rightRotate(root);	
		}
	} else if (factor < -1){
		if(balanceFactor(root -> right) <= 0){				//Right Right Case
			return leftRotate(root);
		} else {											// Right Left Case
			root -> right = rightRotate(root -> right);
			return leftRotate(root);
		}
	}
	return root;
}

Node *insertNode(Node *root, char name[], int age){
	if(root == NULL){
		return newNode(name, age);
	} else if (strcmp(root -> name, name) > 0){
		root -> left = insertNode(root -> left, name, age);
	} else if (strcmp(root -> name, name) < 0){
		root -> right = insertNode(root -> right, name, age);
	} else {
		printf("Duplicate Value!\n");
//		printf("Point +");
	}
	
	root -> height = max(height(root -> left), height(root -> right)) + 1;
	return rebalance(root);
}

void inOrder(Node *root){
	if(root != NULL){
		inOrder(root -> left);
		printf("Name: %s, Age: %d\n", root -> name, root -> age);
		inOrder(root -> right);
	}
}

Node *pop(Node *root, char name[]){
	if(root == NULL){
		printf("Nodenya tidak ketemu!\n");
		return NULL;
	} else if (strcmp(root -> name, name) > 0){
		root -> left = pop(root -> left, name);
	} else if (strcmp(root -> name, name) < 0){
		root -> right = pop(root -> right, name);
	} else {		//Nodenya sudah ketemu
		if(root -> left == NULL){				//Punya anak kanan
			Node *temp = root -> right;
			free(root);
			root = NULL;
			return temp;
		} else if (root -> right == NULL){		//Punya anak kiri
			Node *temp = root -> left;
			free(root);
			root = NULL;
			return temp;
		} else {								//Punya 2 anak
			Node *temp = root -> left;
			while (temp -> right){
				temp = temp -> right;
			}
			//Sudah dapat predeccesor
			
			root -> age = temp -> age;
			strcpy(root -> name, temp -> name);
			
			root -> left = pop(root -> left, temp -> name);
				
		}
	}
	root -> height = max(height(root -> left), height(root -> right)) + 1;
	return rebalance(root);
}

Node *popAll (Node *root){
	if(root != NULL){
		popAll(root -> left);
		popAll(root -> right);
		free(root);
		root = NULL;
	}
	return NULL;
}

Node *searching(Node *root, char name[]){
	if(root == NULL){
		printf("Node Not Found!\n");
		return NULL;
	} else if (strcmp(root -> name, name) > 0){
		return root -> right = searching(root -> right, name);
	} else if (strcmp(root -> name, name) < 0){
		return root -> left = searching(root -> left, name);
	} else if (strcmp(root -> name, name) == 0){
		printf("Node Is Found!\n");
		return root;
	}
}

int main(){
	Node *root = NULL;
	root = insertNode(root, "joko", 54);
	root = insertNode(root, "asep", 32);
	root = insertNode(root, "anton", 30);
	root = insertNode(root, "Joel", 26);
	inOrder(root);
	printf("\n");
	
	printf("After Deletion\n");
	root = pop(root, "joko");
//	root = pop(root, "asep");
//	root = pop(root, "anton");
	inOrder(root);
	printf("\n");
	
	printf("Searching\n");
	root = searching(root, "joko");
	printf("%d\n", root);
	printf("\n");
	
	printf("Pop All\n");
	root = popAll(root);
	inOrder(root);
	printf("\n");
	
	return 0;
}
