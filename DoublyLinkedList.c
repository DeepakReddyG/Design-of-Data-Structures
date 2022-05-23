// Menu driven program for doubly linked list in c 

#include<stdio.h>
#include<stdlib.h>


void Traverse();
void InsertAtBeginning();
void InsertAtEnd();
void InsertAtPosition();
int NumberOfNodes(); 

struct node {
	int data;
	struct node *prev; 
	struct node *next; 
};

struct node *head = NULL;

int NumberOfNodes() {
	int count = 0;
	struct node *temp = head; 
	if(temp == NULL) {
		return count; 
	}
	else {
		while(temp->next) {
			count++;
			temp=temp->next; 
		}
		
		return count; 
	}
} 

void Traverse() {
	struct node *temp = head; 
	printf("HEAD ---> ");
	if(head == NULL) {
		printf("list empty\n"); 
	}
	else {
		while(temp!=NULL) {
			printf("[%d  ] --->", temp->data); 
			temp=temp->next; 
		}
	}
	printf("\n"); 
} 

void InsertAtBeginning() {
	struct node *newNode, *temp = head; 
	int value; 
	if(temp == NULL) {
		printf("\tInserting a newNode in to an empty list\n"); 
	}
	
	printf("Enter value: ");
	scanf("%d", &value);
	
	newNode = malloc(sizeof(struct node)); 	

	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = NULL; 
	
	newNode->next = head; 
	head = newNode;  
	
}

void InsertAtEnd() {
	struct node *newNode, *temp = head;
	int value; 
	if(temp == NULL) {
		InsertAtBeginning(); 
	}
	else {
		printf("Enter value: ");
		scanf("%d", &value); 

		newNode = malloc(sizeof(struct node)); 
	
		newNode->data = value;
		newNode->next = NULL;
		newNode->prev = NULL; 
		
		while(temp->next!=NULL) {
			temp=temp->next; 
		}
	
		newNode->prev = temp;
		temp->next = newNode;  
	}
}

void InsertAtPosition() {
	struct node *newNode, *temp = head; 
	int value, position, i=1; 
	
	if(temp == NULL) {
		printf("\tList is empty, no position is valid to insert a new node\n"); 
	}
	else {
		printf("\t\tEnter position: ");
		scanf("%d", &position); 
		
		if(position > NumberOfNodes()) {
			printf("\tposition is INVALID\n"); 
		}
		else if(position ==1 ) {
			InsertAtBeginning();
		}
		else if(position == NumberOfNodes()) {
			InsertAtEnd(); 
		}
		else {
			printf("\t\tEnter value: "); 
			scanf("%d", &value); 
		
			newNode = malloc(sizeof(struct node)); 
			
			newNode->data = value;
			newNode->prev = NULL;
			newNode->next = NULL; 

			while(i<position-1) {
				temp=temp->next; 
			}
			
			newNode->prev =  temp; 
			newNode->next = temp->next; 
			temp->next->prev = newNode; 
			temp->next = newNode; 
		}
	}
}

int main() {
	int choice;
	printf("--------------->> Menu <<--------------\n"); 
	printf("\t1.Traverse the list\n\t2.Insert at the beginning\n\t3.Insert at the end\n\t4.Insert at position\n\t5.Eixt\n");
	 
	while(1) {
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1: printf("\tYou choose to Traverse the list\n"); 
				Traverse();
				break;
			case 2: printf("\tYou choose to Insert at the beginning\n");
				InsertAtBeginning();
				break;
			case 3: printf("\tYou choose to Insert at the End\n");
				InsertAtEnd();
				break;
			case 4: printf("\tYou choose to Insert at a position\n");
				InsertAtPosition();
				break;
			case 5: printf("\tYou are out Menu\n");
				exit(0);
			default: printf("\tYou choose an INVALID choice, please choose a VALID choice\n");

		}
	}

}
