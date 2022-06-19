#include <stdio.h>

void f(int (*x)(int));
int myfoo(int);
int (*fooptr)(int);

int ((*foo(int)))(int);

int ((*foo(int i)))(int) {
	return myfoo;
}

int myfoo(int i) {
	printf("%d\n", i + 1);
}

int main () {
	int i = 10;
	fooptr = foo(0);
	fooptr(i);
}
