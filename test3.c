#include <stdio.h>


struct _command {
	int *(callback)(int);
	struct _command *next;
};

struct _command * initCammandList();
void insertCommand(command * list, int *(callback)(int));

int main () {
	int add5(int a) {
		return a + 5;
	}
	int sub4(int a) {
		return a - 4;
	}
	int mul3 (int a) {
		return a * 3;
	}
	int div2 (int a) {
		return a / 2;
	}
}
