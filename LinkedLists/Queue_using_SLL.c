// implementation of 'Queue data structure' using Singly Linked List

#include<stdio.h>
#include<stdlib.h>

void enQueue();
void deQueue();
void peek();
void isEmpty();


struct node {
	int data;
	struct node *next; 
}; 


struct node *front = NULL, *rear = NULL; 

void enQueue() {
	int value;
	struct node *newNode = malloc(sizeof(struct node));
	printf("Enter value: ");
	scanf("%d", &value);
	newNode->data = value;
	newNode->next = NULL; 
	
	if(front == NULL && rear == NULL) {
		front = rear = newNode; 
	}
	else {
		rear->next = newNode; 
		rear = newNode; 
	}
}

void deQueue() {
	struct node *temp;
		
	if(front == NULL) {
		printf("\tQueue is empty\n");	
	}
	else {
		temp = front;
		front = front->next;
		free(temp); 
	}
}

void peek() {
	struct node *temp;
	
	if(front == NULL) {
		printf("\tQueue is empty\n");
	}
	else {
		printf("\tPeek element = %d\n", rear->data);
	}
}

void isEmpty() {
	if(front == NULL) {
		printf("\tQueue is empty\n"); 
	}
	else {
		printf("\tQueue is not empty\n"); 
	}
}

void display() {
	if(front == NULL) {
		printf("Queue is empty\n");
	}
	else {
		struct node *temp;
		temp = front; 
		
		while(temp) {
			printf("%d ---> ", temp->data); 
			temp = temp->next; 
		}
	}
	printf("\n");
}

int main() {
	int choice;
	printf("------------->> Menu <<-----------\n");
	printf("\t1.enQueue\n\t2.deQueue\n\t3.peek\n\t4.isEmpty\n\t5.display\n\t6.Exit\n");
	
	while(1) {
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1: printf("\tYou choose to enQueue\n");
				enQueue();
				break;
			case 2: printf("\tYou choose to deQueue\n");
				deQueue();
				break;
			case 3: printf("\tYou choose to peek element\n");
				peek();
				break;
			case 4: printf("\tYou choose to isEmpty\n");
				isEmpty();
				break;
			case 5: printf("\tYou choose to display\n");
				display();
				break;
			case 6: printf("\tYou are out of menu\n");
				exit(0);
				break; 
			default: printf("\tYou choice in Invalid\n");
				
		}
	}
	return 0; 
}
	



