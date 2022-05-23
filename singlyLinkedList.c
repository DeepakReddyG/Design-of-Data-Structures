// Menu driven program for 'singly linked' list in c


#include<stdio.h>
#include<stdlib.h>



void Traverse(); 
void InsertAtBeginning(); 
void InsertAtEnd();
void InsertAtPoisition();
int NumberOfNodes(); 
void DeleteAtBeginning();
void DeleteAtEnd();
void DeleteAtPosition();

struct node {
	int data;
	struct node *next; 
}; 

struct node *head = NULL; 


int NumberOfNodes() {
	struct node *temp = NULL; 
	int count = 0;
	if(head == NULL) {
		return 0; 
	}	
	else {
		temp = head;
		while(temp) {
			count++; 
			temp=temp->next; 
		}
		return count; 
	}
}

void Traverse() {
	struct node *temp = head; 
	printf("\tHEAD --> "); 
	if(temp==NULL) {
		printf("\tList is empty\n"); 
	}
	else {
		while(temp!=NULL) {
			printf("[%d", temp->data); 
			temp=temp->next;
			if(temp) {
				printf(" ]---->"); 
			} 
			else {
				printf(" | NULL ] "); 
			}
		}
	}
}

void InsertAtBeginning() {
	
	struct node *newNode = malloc(sizeof(struct node)), *temp; 
	int value; 
	if(head == NULL) {
		printf("\tInserting a new node into an empty list\n"); 		
	}
	
	printf("\tEnter value to insert: ");
	scanf("%d", &value); 
		
	newNode->data = value; 
	newNode->next = NULL; 
		
	newNode->next = head; 
	head = newNode; 		
	
}


void InsertAtEnd() {
	struct node *newNode, *temp; 
	int value;
		
	if(head == NULL) {
		printf("\tList empty!! Do you want to add the newNode into a empty list?[1/0]:"); 
		int x;  
		scanf("%d", &x); 
		if(x == 1 ) {
			InsertAtBeginning(); 
		}
		else {
			printf("\tOops\n"); 
		}
	}
	
	else {
		printf("\tEnter a value to insert: ");
		scanf("%d", &value);
		
		newNode = malloc(sizeof(struct node));
		newNode->data = value;
		newNode->next = NULL; 
		
		temp = head;
			
		while(temp->next!=NULL) {
			temp=temp->next; 
		}
		temp->next = newNode; 
	}
}

void InsertAtPosition() {
	struct node *newNode, *temp;
	int value, position, i=1;  
	
	if(head == NULL) {
		printf("\tSince list is empty, this function doesn't work\n"); 
	}
	else {
		printf("\tEnter position: ");
		scanf("%d", &position); 
	
		if(position > NumberOfNodes()) {
			printf("\tInvalid position\n"); 
		} 
		else {
			printf("Enter value to insert: ");
			scanf("%d", &value); 
			
			newNode = malloc(sizeof(struct node));
			newNode->data = value;
			newNode->next = NULL; 
			temp = head;	
			while(i < position-1) {
				temp=temp->next;
				i++; 
			}
			newNode->next = temp->next; 
			temp->next = newNode; 
		}
	}
}


void DeleteAtBeginning() {
	struct node *temp = head;
	if(temp==NULL) {
		printf("\tDeletion not possible, since list is empty\n"); 
	}
	else {
		head = head->next;
		free(temp); 
	}
}

void DeleteAtEnd() {
	struct node *temp = head, *prevNode;
	if(temp == NULL) {
		printf("\tDeletion not possible, since list is empty\n"); 
	}
	else if(temp->next->next == NULL) {
		DeleteAtBeginning(); 
	}
	else {
		while(temp->next!=NULL) {
			prevNode = temp; 
			temp=temp->next;
		}
		prevNode->next = NULL;
		free(temp); 
	}
}

void DeleteAtPosition() {
	struct node *temp = head;
	if(temp == NULL) {
		printf("Deletion not possible, since list is empty\n"); 
	}
	else {
		int position, i =1;
		printf("\t\tEnter position to delete: ");
		scanf("%d", &position);
		if(position > NumberOfNodes()) {
			printf("\t\tInvalid position to delete\n"); 
		}
		else if(position ==1) {
			DeleteAtBeginning();
		}
		else if(position == NumberOfNodes()) {
			DeleteAtEnd(); 
		}
		else {
			while(i<position-1) {
				temp = temp->next; 
			}
			
			struct node *pos = temp->next; 
			temp->next = pos->next; 
			free(pos); 
		}
	}
}
int main() {
	int choice; 
	printf("------------->> Menu <<-----------\n"); 
	printf("\t1.Traverse list\n\t2.Insert at the beginning\n\t3.Insert at the end\n\t4.Insert at a position\n\t5.Count number of nodes\n\t6.Delete At the Beginning\n\t7.Delete At the end\n\t8.Delete at a position\n\t9.Exit from menu\n");
	
	while(1) {
		printf("\nEnter your choice: ");
		scanf("%d", &choice); 
	
		switch(choice) {
			case 1: printf("\tYou choose to Traverse the list\n"); 
				Traverse();
				break; 
			case 2: printf("\tYou choose to Insert at the beginning\n"); 
				InsertAtBeginning();
				break;
			case 3: printf("\tYou choose to Insert at the end of the list\n"); 
				InsertAtEnd();
				break;
			case 4: printf("\tYou choose to Insert at a position\n"); 
				InsertAtPosition();
				break;
			case 5: printf("\tYou choose to 'Count number of nodes\n"); 
				int X = NumberOfNodes();
				printf("\t\tNumber of nodes = %d\n", X);
				break;
			case 6: printf("\tYou choose to Deleting a node in the beginning\n"); 
				DeleteAtBeginning();
				break; 
			case 7: printf("\tYou choose to Deleting a node in the end\n"); 
				DeleteAtEnd();
				break;
			case 8: printf("\tYou choose to Deleting a node at a position\n"); 
				DeleteAtPosition();
				break; 
			case 9: printf("\tYou exited from the list\n"); 
				exit(0); 
				break; 
			default: printf("\tYour choice is INVALLID, please choose a VALID choice\n"); 

		} 
	}
	
	return 0;

}
