#include <stdio.h>
#include <stdlib.h>
struct _command {
    int (*callback)(int); // A command will excecute a callback function
    struct _command *next;
};

struct _command * initCommandList();
void insertCommand(struct _command * list, int (*callback)(int));
int add5(int a){return a + 5;}
int sub4(int a){return a - 4;}
int mul3(int a){return a * 3;}
int div2(int a){return a / 2;}
struct _command* initCommandList()
{
    struct _command* _head = malloc(sizeof(struct _command*));
    _head->callback = NULL;
    _head->next = NULL;
    return _head;
}
void insertCommand(struct _command * list, int (*callback)(int))
{
    //if list is empty, get out
    if(list == NULL)    return;
    //list is not empty
    struct _command* _browse = list;
    while(_browse->next != NULL)
    {
        _browse = _browse->next;
    }
    struct _command* _new = malloc(sizeof(struct _command*));
    _new->callback = callback;
    _new->next = NULL;
    _browse->next = _new;
}
int calculate(int a, struct _command * orderOfFunctions) 
{
    //if orderList is empty, return -1
    if(orderOfFunctions == NULL || orderOfFunctions->next == NULL)   return -1;
    //ignore the head of list
    struct _command* _browse = orderOfFunctions->next;
    //browse to the last node
    while(_browse != NULL)
    {
        a = _browse->callback(a);
        _browse = _browse->next;
    }
    return a;   
}
int main()
{
    struct _command *orderOfFunctions = initCommandList();
    insertCommand(orderOfFunctions, add5);
    insertCommand(orderOfFunctions, sub4);
    insertCommand(orderOfFunctions, mul3);
    insertCommand(orderOfFunctions, div2);  
    
    int res = calculate(1001, orderOfFunctions);
    printf("%d", res);
    return 0;
}
