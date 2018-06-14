#include <iostream>
#include "compiler.h"

int main(int argc, char const *argv[])
{
	
	Compiler_asm ms;
	ms.compile("program.asm");

	return 0;
}