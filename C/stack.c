/* The given file gives the basics of a stack. The following functions are the main functions on the stack:
		  1) push operation
		  2) pop operation.
		  3) get top
		  4) get stack size

This is a program written in C, with comments explaining the logic behind it.
*/


#include <stdio.h>

typedef struct _NODE {
	int data;
	struct _NODE* prev;
} node;

typedef struct _STACK{
	int size;
	struct _NODE* top;
} stack;

void initStack(stack* s) {
	s->size = 0;
	s->top = NULL;
}

void push(stack* s, int data) {
	node* newNode = malloc(sizeof(node));

	newNode->data = data;
	newNode->prev = s->top;
	s->top = newNode;
	s->size++;
}

void pop(stack* s) {
	node* delNode = s->top;
	s->top = delNode->prev;
	free(delNode);
	s->size--;
}

int getSize(stack s) {
	return s.size;
}

void printStack(stack s) {
	node* dataPrint = NULL;
	while (s.top != NULL) {
		dataPrint = s.top;
		printf("%d\n", dataPrint->data);
		s.top = dataPrint->prev;
	}
}


/*node getTop(stack s) {
	return s->top;
}*/

int main (int argc, char ** argv) {
	stack mySt;
	initStack(&mySt);

	

	push(&mySt, 10);
	push(&mySt, 11);
	push(&mySt, 12);
	push(&mySt, 13);

	printStack(mySt);
	printf("%d\n", getSize(mySt));

	pop(&mySt);
	pop(&mySt);
	push(&mySt, 20);
	printStack(mySt);
	printf("%d\n", getSize(mySt));



	
	}