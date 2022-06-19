#include <stdio.h>
#include <stdlib.h>

int main () {
	long val = 0x41414141;
	char buf[4];
	
	printf("Correct val's value from 0c41414141 -> 0xdeadbeef!\n'");
	printf("Here is your chance: ");
	scanf("%8s", &buf);
	printf("buf: %s\n", buf);
	printf("val: 0x%08x\n", val);
	
	if(val == 0xdeadbeef) {
		printf("OK! YOU WIN!!!\n");
	}
	else {
		printf("WAY OFF!!!\n");
		exit(1);
	}
	
	return 0;
}
