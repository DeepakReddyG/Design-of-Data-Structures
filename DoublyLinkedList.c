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
		while(temp) {
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
			
			temp->next->prev = newNode;
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next = newNode;

		}
	}
}

void DeleteAtBeginning() {
	struct node *temp;
	if(temp == NULL) {
		printf("\tDeletion not possible, since list is empty\n");
	}
	else {
		temp = head; 
		head = head->next; 
		if(head!=NULL) {
			head->prev = NULL; 
		}
		free(temp); 
	}
}

void DeleteAtEnd() {
	struct node *temp = head;
	if(temp == NULL) {
		printf("\tDeletion not possible, since the list is empty\n");
	}
	else {
		while(temp->next!=NULL) {
			temp=temp->next;
		}
		
		temp->prev->next = NULL;
		free(temp); 
	}
}

void DeleteAtPosition() {
	struct node *temp = head;
	int i=1, value, position; 
	if(temp == NULL) {
		printf("Deletion not possible, since list is empty\n");
	}
	else {
		printf("Enter position: ");
		scanf("%d", &position);
		
		if(position > NumberOfNodes()) {
			printf("\tInvalid position\n"); 
		}
		else if(position ==1 ) {
			DeleteAtBeginning();
		}
		else if(position == NumberOfNodes()) {
			DeleteAtEnd();
		}
		else {
			while(i<position-1) {
				i++;
				temp=temp->next; 
			}
			struct node *pos = temp->next; 
			pos->next->prev = temp;
			temp->next = pos->next;
		
			free(pos);  
		}
	}
}

int main() {
	int choice;
	printf("--------------->> Menu <<--------------\n"); 
	printf("\t1.Traverse the list\n\t2.Insert at the beginning\n\t3.Insert at the end\n\t4.Insert at position\n\t5.Number of nodes\n\t6.Delete at Beginning\n\t7.Delete at the end\n\t8.Delete at a position\n\t9.Exit Menu\n");
	 
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
			case 5: printf("\t\tNuber of nodes = %d\n", NumberOfNodes()); 
				break;
			case 6: printf("\tYou choose to Delete at the Beginning\n");
				DeleteAtBeginning();
				break;
			case 7: printf("\tYou choose to Delete at the end\n");
				DeleteAtEnd();
				break;
			case 8: printf("\tYou choose to Delete at a position\n"); 
				DeleteAtPosition();
				break;
			case 9: printf("\tYou are out of Menu\n"); 
				exit(0);
				break; 
			default: printf("\tYou choose an INVALID choice, please choose a VALID choice\n");

		}
	}

}
