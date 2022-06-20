#include <stdio.h>

void main () {
	char showMe[] = "HUMAX"; // bao gom ki tu NULL ket thuc 
	int foo = 0;
	int bar = 0;
	
	printf("%s\n", (char*)&foo+10);
	printf("%s\n", (char*)&bar+6);
}
