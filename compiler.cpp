#include "compiler.h"

void Compiler_asm::compile( std::string file ) {
	this->fileName = file;

	std::string tmp;
	std::ifstream program( fileName );
	while( !program.eof() ) {
		getline(program, tmp);
		std::cout << tmp << std::endl;
	}

}