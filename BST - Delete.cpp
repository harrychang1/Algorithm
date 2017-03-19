#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node{
	int key;
	struct node *left, *right;
};

// a utility function to create a new BST node
struct node *newNode(int item){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// a utility function to do inorder traversal of BST
void inorder(struct node *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ",root->key);
		inorder(root->right);
	}
}

//a utility function to insert a new node with given key in BST
struct node *insert(struct node* node , int key){
	
	//if the tree is empty return a new node
	if(node == NULL)return newNode(key);
	
	//otherwise recur down a tree
	if(key < node->key)
		node->left = insert(node->left , key);
	else
		node->right = insert(node->right , key);
		
	//return the unchanged node pointer
	return node;
}

/*
	given a non empty binary search tree , return the node with minimum 
	key value found in that tree. Note that the entire tree does not
	need to be searched
*/
struct node* minValueNode(struct node* node){
	struct node* current = node;
	
	//loop down to find the leftmost leaf
	while(current->left != NULL)
		current = current->left;
		
	return current; 
}

/*
	given a binary search tree and a key , this function deletes the key
	and returns the new root
*/

struct node* deleteNode(struct node* root , int key){
	
	//base case
	if(root == NULL)return root;
	
	if(key < root->key){
		
		//if the key to be deleted is smaller than the root's key,
		//then it lies in left subtree
		root->left = deleteNode(root->left , key);
		
	}else if(key > root->key){
		
		//if the key to be deleted is greater than the root's key
		//then it lies in right subtree
		root->right = deleteNode(root->right , key);
		
	}else{
		
		//if the key is same as root's key , then this is the node
		//to be deleted
		if(root->left == NULL){
			struct node *temp = root->right;
			free(root);
			return temp;
		}else if(root->right == NULL){
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		
		
		//node with two children : get inorder successor (smallest in the right subtree)
		struct node *temp = minValueNode(root->right);
		
		//copy the inorder successor's content to this node
		root->key = temp->key;
		
		//delete the inorder successor
		root->right = deleteNode(root->right , temp->key);
		
	}
		
	return root;
}

int main()
{	
	/*
		Following BST Tree
			   50
			  /  \
			/	  \
		   30     70
		  /  \    / \
		20  40  60  80
	*/
	struct node *root = NULL;
	root = insert(root , 50);
	root = insert(root , 30);
	root = insert(root , 20);
	root = insert(root , 40);
	root = insert(root , 70);
	root = insert(root , 60);
	root = insert(root , 80);
	
	printf("Inorder traversal of the given tree\n");
	inorder(root);
	
	
	printf("\n\nDelete 20\n");
	root = deleteNode(root , 20);
	printf("Inorder traversal of the modified tree\n");
	inorder(root);
	
	printf("\n\nDelete 80\n");
	root = deleteNode(root , 80);
	printf("Inorder traversal of the modified tree\n");
	inorder(root);
	
	printf("\n\nDelete 40\n");
	root = deleteNode(root , 40);
	printf("Inorder traversal of the modified tree\n");
	inorder(root);
	
	
	return 0;
}
