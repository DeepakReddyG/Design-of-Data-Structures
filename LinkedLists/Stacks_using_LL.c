//implementation of 'stack data structure' using Singly Linked List 

#include<stdio.h>
#include<stdlib.h>

void Push();
void Pop();
void Peek();
void display();

struct node {
	int data;
	struct node *next; 
}; 

struct node *head = NULL; 

void Push() {
	struct node *newNode = malloc(sizeof(struct node)); 
	int value;
	printf("\tEnter value: ");
	scanf("%d",&value);
	
	newNode->data = value;
	newNode->next = head; 
	head = newNode; 
	
}

void Pop() {
	if(head == NULL) {
		printf("Pop operation coundn't be performed since list is empty\n");
	}
	else {
		struct node *temp;
		printf("%d poped out from the stack\n", head->data);
		temp = head;
		head = head->next;
		free(temp); 
	}
}

void peek() {
	if(head == NULL) {
		printf("\tNo peek element, list is empty\n");
	}
	else {
		printf("\tPeek element = %d\n", head->data); 
	}
}

void display() {
	if(head == NULL) {
		printf("\tList is empty\n");
	}
	else {
		struct node *temp = head;
		while(temp) {
			printf("%d --->", temp->data);
			temp = temp->next; 
		}
	}
	printf("\n");
}

int main() {
	int choice;
	printf("------------>> Menu <<------------\n");
	printf("\t1.Push\n\t2.Pop\n\t3.Peek\n\t4.Display\n\t5.Exit\n");

	while(1) {
		printf("Enter your choice: ");
		scanf("%d", &choice);
	
		switch(choice) {
			case 1: printf("\tYou choose to Push an element\n");
				Push();
				break;
			case 2: printf("\tYou choose to Pop an element\n");
				Pop();
				break;
			case 3: printf("\tYou choose to Peek element\n");
				peek();
				break;
			case 4: printf("Displaying Stack elements: \n");
				display();
				break;
			case 5: printf("\tYou are out of menu\n");
				exit(0);
				break;
			default: printf("\tInvalid choice\n");

		}
	}
	return 0;	
}
