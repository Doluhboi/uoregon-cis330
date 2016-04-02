// This program is from: 
// The author believes it has <3> memory errors
#include <string.h>
#include <stdio.h>

struct Node
{
	int value;
	Node* next;
	Node() { next = NULL; }
	Node(int n) { next = NULL; value = n; }
};

int main()
{
	Node* head = new Node;
	
	Node* curr = head;
	for(int i = 0; i<10; i++)
	{
		curr->value = i;
		curr->next = new Node;
		curr = curr->next;
	}
	curr->next = head;

	Node* prev = head;
	curr = head->next;
	while(curr->next!=NULL)
	{
		//	printf("deleted");
		delete prev;
		prev = curr;
		curr = curr->next;
	}

	int final = curr->value;
	printf("Final int is; %d", final);
}
