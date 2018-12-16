#include <iostream>
 
 /*
	C:\Development\learningCPP\otherConcepts>nm NM_HelloCpp.o
	00000000 b .bss
	00000000 d .ctors
	00000000 d .data
	00000000 r .eh_frame
	00000000 r .rdata
	00000000 r .rdata$zzz
	00000000 t .text
			 U ___main
			 U ___mingw_vprintf
	0000009e t ___tcf_0
	000000de t __GLOBAL__sub_I__Z5myFunv
	000000b0 t __Z41__static_initialization_and_destruction_0ii
	00000053 T __Z5myFunf
	0000003e T __Z5myFuni
	00000068 T __Z5myFunif
	00000029 T __Z5myFunv
	00000000 t __ZL6printfPKcz
			 U __ZNSt8ios_base4InitC1Ev
			 U __ZNSt8ios_base4InitD1Ev
	00000000 b __ZStL8__ioinit
			 U _atexit
	0000007d T _main
 */
 
 /*
 C:/Qt/Tools/mingw530_32/i686-w64-mingw32/include/stdio.h:296:5: note: 'int printf(const char*, ...)' previously defined here
 int printf (const char *__format, ...)
 */

 //extern "C"
 //{
	int printf(const char *format...);
 //}

void myFun()
{
	printf("myFun()");	
}

void myFun(int val)
{
	printf("myFun(val)");	
}

void myFun(float val)
{
	printf("myFun(val)");	
}

void myFun(int val, float val2)
{
	printf("myFun(val)");	
}
	
int main(int argc, char **argv)
{
	printf("Hello CPP");
}
