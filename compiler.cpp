#include "compiler.h"

void Compiler_asm::compile( std::string file ) {
	this->fileName = file;

	init_functionMap();

	std::string line;
	std::ifstream program( fileName );
	while( !program.eof() ) {
		getline(program, line);
		physicMemory.push_back( line );
		process( line );
	}
}

int Compiler_asm::process( std::string line ) {

	std::cout << line << " "<< line[0] << std::endl;
	if( line[0] != 0)
		functionMap[line.substr(1, 3)];
	else {
		functionMap[line];
	}

	return 0;
}

void Compiler_asm::init_functionMap( ){
	// functionMap.emplace("0000",);
	// functionMap.emplace("0001",);
	// functionMap.emplace("1",);
	// functionMap.emplace("2",);
	// functionMap.emplace("3",);
	// functionMap.emplace("4",);
	// functionMap.emplace("5",);
	// functionMap.emplace("6",);
	// functionMap.emplace("7",);
	// functionMap.emplace("8",);
	// functionMap.emplace("9",);
	// functionMap.emplace("A",);
}



void MLOAD( std::string value ) {
	std::string acc = value;
}

void DLOAD( std::string value ) {

}

void ILOAD( std::string value ) {

}

void DSTORE( std::string value ) {
	std::string acc;
	std::unordered_map<std::string, std::string> memory;
	memory[value] = acc;
}

void ISTORE( std::string value ) {

}

void HALT( std::string value ) {

}

void JMP( std::string value ) {

}

void JZ( std::string value )  {

}

void JP( std::string value ) {

}

void JN( std::string value ) {

}

void ADD( std::string value ) {

}

void NEGATE( std::string value ) {

}