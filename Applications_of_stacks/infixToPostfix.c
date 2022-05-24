// infix to post conversion implementation in c

#include<stdio.h>
#include<ctype.h>

char stack[1000];
int top = -1;

void push(char x) {
	top++;
	stack[top] = x; 
}

int pop() {
	if(top == -1) {
		return -1; 
	}
	else {
		return stack[top--]; 
	}
}

int priority(char x) {
	if(x == '(') {
		return 0; 
	}
	else if(x == '+' || x == '-') {
		return 1; 
	}
	else if(x == '*' || x == '/') {
		return 2; 
	}
	else 
		return 0; 
}


int main() {
	char expression[1000];
	char *e, x; 
	
	printf("Enter expression: ");
	scanf("%s", expression); 

	printf("\n"); 
 
	e = expression; 

	while(*e!= '\0') {
		if(isalnum(*e)) {
			printf("%c ", *e); 
		}
		else if(*e == '(') {
			push(*e); 
		}
		else if(*e ==')') {
			while((x=pop()) != '(') {
				printf("%c ", x); 
			}
		}
		else {
			while( priority(stack[top]) >= priority(*e)) {
				printf("%c ", pop()); 
			}
			push(*e); 
		}
		e++; 
	}
	
	while(top!=-1) {
		printf("%c ", pop()); 
	}
	return 0;
}
