#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int index = 1;

typedef struct Node{
    int height,bf;
    char id[5];
    char name[20];
    char owner[20];
    char location[30];
    char type[10];
    Node* left,* right;
}Node;

Node *createNewNode(char name[], char owner[], char location[], char type[], char id[]){
    Node *createNode = (Node*)malloc(sizeof(Node));
    strcpy(createNode->name, name);
    strcpy(createNode->owner, owner);
    strcpy(createNode->location, location);
    strcpy(createNode->type, type);
    strcpy(createNode->id, id);

    createNode->left = createNode->right = NULL;
    createNode->height = 1;
    createNode->bf = 0;

    return createNode;
}

int maxHeight(int a, int b){
    return a > b ? a : b;
}

int getHeight(Node *node){
    if(node == NULL){
    	return 0;
	}
    else{
    	return node->height;
	}
}

int computeNewHeight(Node *root){
	return maxHeight(getHeight(root->left), getHeight(root->right)) + 1;
}

Node *updateNode(Node *root){
    if (root == NULL) {
        return root;
    }

    root->left = updateNode(root->left);
    root->right = updateNode(root->right);

    root->height = computeNewHeight(root);
    root->bf = getHeight(root->left) - getHeight(root->right);

    return root;
}

Node *rightRotate(Node *root){
    Node *pivot = root->left;
    Node *temp = pivot->right;

    pivot->right = root;
    root->left = temp;

    root = updateNode(root);
    pivot = updateNode(pivot);

    return pivot;
}

Node *leftRotate(Node *root){
    Node *pivot = root->right;
    Node *temp = pivot->left;

    pivot->left = root;
    root->right = temp;

    root = updateNode(root);
    pivot = updateNode(pivot);

    return pivot;
}

Node *rotation(Node *root){
    if (root->bf < -1 && root->right->bf < 0) {
        root = leftRotate(root);
    } else if (root->bf < -1 && root->right->bf > 0) {
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    } else if (root->bf > 1 && root->left->bf > 0) {
        root = rightRotate(root);
    } else if (root->bf > 1 && root->left->bf < 0) {
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }
    root = updateNode(root);

    return root;
}

Node *insert(Node *root, char name[], char owner[], char location[], char type[], char id[]){
	Node * new_node = createNewNode(name, owner, location, type, id);
    if(root  == NULL){
    	return new_node;
	}
    else if(strcmp(id, root-> id) < 0){
    	root->left = insert(root->left, name, owner, location, type, id);
	}
    else if(strcmp(id, root-> id) > 0){
    	root->right = insert(root->right, name, owner, location, type, id);
	}

        return rotation(updateNode(root));
}

Node *minValueNode(Node *node){
    Node *cur = node;
    while(cur->left != NULL){
    	cur = cur->left;
	}

    return cur;
}

Node *searchNode(struct Node* node, char id[]){
    if(node == NULL){
        return NULL;
    }
	else if(strcmp(id, node-> id) < 0){
        return searchNode(node->left, id);
    }
	else if(strcmp(id, node-> id) < 0){
        return searchNode(node->right, id);
    }
    return node;
}

Node *deleteNode(Node *root, char id[]){
    if(root == NULL){
    	printf("angka tidak ada");
    	return root;
	}
    else if(strcmp(id, root-> id) < 0){
    	root->left = deleteNode(root->left, id);
	}
    else if (strcmp(id, root-> id) < 0){
    	root->right = deleteNode(root->right, id);
	}
    else{
        if( root->left == NULL || root->right == NULL){
            Node *temp = root->left ? root->left : root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            }
			else{
				 *root = *temp;
			}
            free(temp);

        }
		else{
            Node *temp = minValueNode(root->right);
		    strcpy(root->name, temp->name);
		    strcpy(root->owner, temp->owner);
		    strcpy(root->location, temp->location);
		    strcpy(root->type, temp->type);
		    strcpy(root->id, temp->id);
            root->right = deleteNode(root->right, temp->id);
        }
    }
    if(root == NULL){
    	return root;
	}
	return rotation(updateNode(root));

}

void preOrder(Node* root) {
    if(root != NULL) {
          printf("%s | %s | %s | %s | %s \n",root->id,root->name,root->owner,root->location,root->type);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if(root != NULL) {
        preOrder(root->left);
        printf("%s | %s | %s | %s | %s \n",root->id,root->name,root->owner,root->location,root->type);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if(root != NULL) {
        preOrder(root->left);
        preOrder(root->right);
        printf("%s | %s | %s | %s | %s \n",root->id,root->name,root->owner,root->location,root->type);
    }
}

Node *root = NULL;

void displayMenu(){
    puts("1. View all stores");
    puts("2. Insert new store");
    puts("3. Delete a store");
    puts("4. Delete all stores");
    puts("5. Exit");
}

void view(){
	int choose = 0;
    puts("1. Pre-Order");
    puts("2. in-Order");
    puts("3. Post-Order");
    printf(">>");
    scanf("%d", &choose);
    if(choose == 1){
    	preOrder(root);
	}else if(choose == 2){
    	inOrder(root);
	}else if(choose == 3){
    	postOrder(root);
	}else{
		view();
	}
}


void delete_menu(){
	char delete_item[5];
	printf("Input Store ID: ");
	scanf("%s", &delete_item);
	//ini rusak
	if(strcmp(searchNode(root, delete_item) -> id, delete_item) != 0){ // logikanya pas kita search node hasinya sama dengan variable delete_node
		puts("ID Not found!");
		delete_menu();
	}else{
		deleteNode(root, delete_item); // kalo berhasil langsung delete node pake variable delete item
	}
}

void insert_menu(){
	puts("Menu: Insert new store\n");

    char name[20];
    char owner[20];
    char location[30];
    char type[10];
    do {
    	printf("Input store name: ");
    	gets(name);
    	if((strlen(name) < 5)) puts("Store name must be at least 5!");
	}while(strlen(name) < 5);

    int error = 0;
    do {
    	error = 0;
    	printf("Input store owner name ['Mr. ' or 'Mrs. ' (case sensitive)]: ");
    	gets(owner);
    	char template1[4] = "Mr.";
    	if(owner[0] != 'M'){
    		error++;
		}
		if(owner[1] != 'r'){
    		error++;
		}
		if(owner[2] != '.'){
    		if(owner[2] != 's'){
	    		error++;
			}else{
				if(owner[3] != '.'){
		    		error++;
				}
			}
		}
    	if(error > 0) puts("Owner must be Mr atau Mrs");
	}while(error > 0);


    do {
    	error = 0;
    	printf("Input tempat gitu: ");
    	gets(location);

    	int length = strlen(location);
    	char template1[8] = " Street";
    	int temp_index = 0;
    	for(int i = length - 7; i < length; i++){
    		if(location[i] != template1[temp_index]){
    			error++;
    			break;
			}
			temp_index++;
		}
    	if(error > 0) puts("Gagal");
	}while(error > 0);

    do {
    	error = 1;
    	printf("Input tipe gitu: ");
    	gets(type);

    	char tipe_list[5][20] = { "Dialy Needs", "Cloating", "F&B", "Electronics", "Kitchenware" };
    	for(int i = 0; i < 5; i++){
    		if(strcmp(tipe_list[i], type) == 0){
    			error = 0;
    			break;
			}
		}
    	if(error > 0) puts("Gagal");
	}while(error > 0);

    char id[5];
    sprintf(id, "ST%03d", index);
    index += 1;

	root = insert(root, name, owner, location, type, id);
}

int main() {
    int error = 0;
    int choice;

    do {
        displayMenu();
        printf("Choose >> ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                view();
                break;
            case 2:
                insert_menu();
                break;
            case 3:
                delete_menu();
                break;
            case 4:
                // Kode untuk pilihan 4
                break;
            case 5:
                // Kode untuk pilihan 5
                break;
            default:
                error = 1;
                break;
        }
    } while (error == 0);

    return 0;
}


