#include <bits/stdc++.h>

using namespace std;

struct Node{
	
	int data;
	struct Node* next;
};

// 3 Methods of Insertion Linked Lists

// 1. At the front of the linked list
// 2. After a given node
// 3. At the end of the linked list


// Function print contents of linked list starting from head
void printLinkedLists(struct Node *node)
{
	while(node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}


// Add a node at the front
void prepend(struct Node** head_ref, int new_data)
{	
	// allocate node
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	
	// put in the data
	new_node->data = new_data;
	
	// make next of new node as head
	new_node->next = (*head_ref);
	
	// move the head to point the new node
	(*head_ref) = new_node;
}

// After a given node
void insertAfter(struct Node* prev_node, int new_data)
{	
	// check if the given prev_node is null
	if(prev_node == NULL)
	{
		printf("the given previous node cannot be null");
		return;
	}
	
	// allocate new node
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	
	// put in the data
	new_node->data = new_data;
	
	// make next of new node as next of prev_node
	new_node->next = prev_node->next;
	
	// move the next of prev_node as new_node
	prev_node->next = new_node;
}

// Add a node at the end
void append(struct Node** head_ref, int new_data)
{
	// allocate node
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	
	// use in step 5
	struct Node *last = *head_ref;
	
	// put in the data
	new_node->data = new_data;
	
	// this new node going to be the last node, so make next of it as NULL
	new_node->next = NULL;
	
	// if the linked list is empty then make the new node as head
	if(*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	
	// traverse till the last node
	while(last->next != NULL)
		last = last->next;
	
	// change the next of last node
	last->next = new_node;
	return;
}

// Delete a node with the given key
void deleteNode(struct Node** head_ref, int key)
{
	
	// Store the head node
	struct Node* temp = *head_ref, *prev;
	
	// If head node itself holds the key to be deleted
	if(temp != NULL && temp->data == key)
	{
		*head_ref = temp->next;
		free(temp);
		return;
	}
	
	// Search for the key to be deleted
	// Keep track of the previous node
	while(temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}
	
	// If key was not present in linked list
	if(temp == NULL)return;
	
	// Unlink the node from linked lists
	prev->next = temp->next;
	
	// Free memory
	free(temp);
}

int main()
{	
	
	struct Node* head = NULL;
	
	append(&head, 6);
	
	printLinkedLists(head);
	cout << endl;
	prepend(&head, 7);
	prepend(&head, 8);
	prepend(&head, 9);
	
	printLinkedLists(head);
	cout << endl;
	
	insertAfter(head->next->next, 10);
	printLinkedLists(head);
	
	cout << endl;
	
	deleteNode(&head, 7);
	printLinkedLists(head);
	
	cout << endl;
	
	return 0;
}
