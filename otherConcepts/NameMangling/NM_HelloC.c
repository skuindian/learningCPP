#include <stdio.h>

/*
 * As C does not support "Name Mangling", it will through an error.
 *
 * C:\Development\learningCPP\otherConcepts>gcc -c NM_HelloC.c
 * NM_HelloC.c:8:6: error: redefinition of 'myFun'
 * void myFun(int val)
 *     ^
 * NM_HelloC.c:3:6: note: previous definition of 'myFun' was here
 * void myFun()
 *
 */
 
 /*
	C:\Development\learningCPP\otherConcepts>nm NM_HelloC.o
	00000000 b .bss
	00000000 d .data
	00000000 r .eh_frame
	00000000 r .rdata
	00000000 r .rdata$zzz
	00000000 t .text
			 U ___main
	00000015 T _main
	00000000 T _myFun
			 U _printf
 */
void myFun()
{
	printf("myFun()");	
}

void myFun(int val)
{
	printf("myFun(val)");	
}
	
int main(int argc, char **argv)
{
	printf("Hello C");
}
