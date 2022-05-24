// balancing brackets implementation in c

#include<stdio.h>
int main() {
	char expression[50];
	int x =0, i=0;
	
	printf("Enter expression: ");
	scanf("%s", expression);
	
	while(expression[i] != '\0') {
		if(expression[i] == '(') {
			x++; 
		}
		if(expression[i] == ')') {
			x--;
		
			if(x<0) {
				break; 
			}
		}
		i++; 
	}

	if(x ==0) {
		printf("Expression is balanced\n");
	}
	else {
		printf("Expression is not balanced\n"); 
	}	
	
	return 0;
}
