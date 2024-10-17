#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    char id[8];
    char name[30];
    int price;
    char type[20];
    
    int height;
    
    Node* left;
    Node* right;
} Node;

// Get height of the node
int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Utility function to get the balance factor of the node
int getBalance(Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Utility function to update the height of the node
void updateHeight(Node* node) {
    int height_left = (node->left)? node->left->height: 0;
    int height_right = (node->right)? node->right->height: 0;
    node->height = (height_left > height_right ? height_left : height_right) + 1;
}

// Utility function to right rotate the sub-tree rooted with node
Node* rightRotate(Node* node) {
    Node* x = node->left;
    Node* T2 = x->right;
    x->right = node;
    node->left = T2;
    updateHeight(node);
    updateHeight(x);
    
    return x;
}

// Utility function to left rotate the sub-tree rooted with node
Node* leftRotate(Node* node) {
    Node* x = node->right;
    Node* T2 = x->left;
    x->left = node;
    node->right = T2;
    updateHeight(node);
    updateHeight(x);
    
    return x;
}

Node* rebalance(Node* node){
    // Update the height of this ancestor node
    updateHeight(node);
    
    // Get the balance factor to check whether this node became unbalanced
    int balance = getBalance(node);

    // If the node is unbalanced, then try out the 4 cases
    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}


// Function to insert a node and return the new root
Node* insertNode(Node* root, Node* property) {
    // Normal BST insertion
    if (root == NULL)
        return property;
    if (strcmp(property->id, root->id) < 0)
        root->left = insertNode(root->left, property);
    else if (strcmp(property->id, root->id) > 0)
        root->right = insertNode(root->right, property);
    else
        return root; // Equal keys not allowed

    return rebalance(root);
}

// Get the minimum value node
Node* minValueNode(Node* node) {
    Node* cur = node;
    while (cur->left != NULL)
        cur = cur->left;
    return cur;
}

// Delete a node
Node* deleteNode(Node* root, char* id) {
    if (root == NULL)
        return root;
    if (strcmp(id, root->id) < 0)
        root->left = deleteNode(root->left, id);
    else if(strcmp(id, root->id) > 0)
        root->right = deleteNode(root->right, id);
    else {
	    if((root->left == NULL) || (root->right == NULL)) {
	        Node *temp = root->left ? root->left : root->right;
	        if(temp == NULL) {
	            temp = root;
	            root = NULL;
	        } else {
	            strcpy(root->id, temp->id);
	            strcpy(root->name, temp->name);
	            root->price=temp->price;
	            strcpy(root->type, temp->type);
	            
	            root->left = temp->left;
	            root->right = temp->right;
	            
	            root->height = temp->height;
	        }
	        free(temp);
	    } else {
	        Node* temp = minValueNode(root->right);
	        
	        strcpy(root->id, temp->id);
	        strcpy(root->name, temp->name);
	        root->price=temp->price;
	        strcpy(root->type, temp->type);
	
	        root->right = deleteNode(root->right, temp->id);
	    }
	}
    
    if (root == NULL)
        return root;
    
    return rebalance(root);
}

// Create a new node
//Node* createNode(Node* root, int id) {
//	Node* node = (Node*) malloc(sizeof(Node));
//    
//    node->id = id;
//    
//    node->left = NULL;
//    node->right = NULL;
//    node->height = 1;
//
//    return node;
//}

// Print all nodes
void preOrder(Node* root) {
    if(root != NULL) {
        //Print
        printf("%s | %s | %d | %s\n", root->id, root->name, root->price, root->type);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int search(Node *root, char* id){
	if(root==NULL){
		return 0;
	}else if(strcmp(id, root->id)==0){
		return 1;
	}else if(strcmp(id, root->id) < 0){
		return search(root->left, id);
	}else if(strcmp(id, root->id) > 0){
		return search(root->right, id);
	}
}

Node* create(Node* root){
	char id[8];
    char name[30];
    int price;
    char type[20];
    
    int random = rand() % 9999;
    sprintf(id, "PRO%04d", random);
    
    do{
    	printf("Enter the name [5-30 chars] : ");
    	gets(name);
    	if(strlen(name)<5 || strlen(name)>30){
    		printf("invalid cuy\n");
		}
	}while(strlen(name)<5 || strlen(name)>30);
	
	do{
    	printf("Enter the price [10000-500000] : ");
    	scanf("%d", &price);
    	getchar();
    	if(price<10000 || price>500000){
    		printf("invalid cuy\n");
		}
	}while(price<10000 || price>500000);
    
    do{
    	printf("Enter the type [Land Only | Residential | Commercial] : ");
    	gets(type);
    	if(strcmp(type, "Land Only")!=0 && strcmp(type, "Residential")!=0 && strcmp(type, "Commercial")!=0){
    		printf("invalid cuy\n");
		}
		
	}while(strcmp(type, "Land Only")!=0 && strcmp(type, "Residential")!=0 && strcmp(type, "Commercial")!=0);
	
	Node* property = (Node*) malloc(sizeof(Node));
	
	strcpy(property->id, id);
	strcpy(property->name, name);
	property->price=price;
	strcpy(property->type, type);
    
    property->height=1;
    property->left=NULL;
    property->right=NULL;
    
    return property;
}

int main() {
    Node* root = NULL;
    
    int option=-1;
    
    do{
    	srand(time(0));
    	printf("JUDUL\n======\n");
    	printf("1. add\n2. view\n3. delete\n4. exit\n\n");
    	printf(">> ");
    	
    	scanf("%d", &option);
    	getchar();
    	
    	Node* property;
    	if(option==1){
    		property = create(root);
    		if(property!=NULL){
    			root=insertNode(root, property);
			}
    		
		}else if(option==2){
			if(root==NULL){
				printf("There is no property yet.\n");
			}else{
				preOrder(root);
			}
		}else if(option==3){
			if(root==NULL){
				printf("There is no property yet.");
			}else{
				preOrder(root);
				printf("\nEnter ID to delete : ");
				char iddelete[8]; 
				gets(iddelete);
				if(search(root, iddelete)==0){
					printf("ID Not found.\n");
				}else{
					root=deleteNode(root, iddelete);
				}
			}
		}
    	
	}while(option != 4);

    return 0;
}
