#include <stdio.h>
#include <stdlib.h>
struct _command {
	int (*callback)(int); // A command will excecute a callback function
	struct _command* next;
};

struct _command* initCommandList() {
	struct _command* _head = malloc(sizeof(struct _command*));
	_head -> callback = NULL;
	_head -> next = NULL;
	return _head;
};

command* orderOfFunctions;

void insertCommand(struct _command* list , int (*callback)(int))
{
	if (list == NULL) {
		return;
	}
	
	command* func = (command*)malloc(sizeof(command));
	func->next = NULL;
	func->callback = callback;
	command* temp = *list;
	if (*list == NULL) *list = func, lastCommand = func;
	else
	{
		lastCommand->next = func;
		lastCommand = func;
	}
}
int calculate(int a, struct _command** orderOfFunctions)
{
	A = a;
	command* temp = *orderOfFunctions;
	while (temp->next != NULL)
	{
		A = temp->callback(A);
		temp = temp->next;
	}
	return temp->callback(A);
}
int add5(int a) { return (a + 5); };
int sub4(int a) { return (a - 4); };
int mul3(int a) { return (a * 3); };
int div2(int a) { return (a / 2); };
int main()
{
	insertCommand(&orderOfFunctions, add5);
	insertCommand(&orderOfFunctions, sub4);
	insertCommand(&orderOfFunctions, mul3);
	insertCommand(&orderOfFunctions, div2);
	printf("%d", calculate(5, &orderOfFunctions));
}
