#include "compiler.h"

void Compiler_asm::compile( std::string file ) {
	this->fileName = file;
	
	init_functionMap();

	std::string line;
	std::ifstream program( fileName );
	while( !program.eof() ) {
		getline(program, line);
		physicMemory.push_back( line );
	}

	for (int programCounter = 0; programCounter < physicMemory.size(); ++programCounter)
	{
		process( physicMemory[programCounter] );
	}
}

int Compiler_asm::process( std::string line) {
	std::string index;
	int value;
	std::cout << " Code " << line << " "<< line[0] << std::endl;
	if( line[0] != '0') {
		index = line[0]; 
		value = std::stoi( line.substr(1, 3), 0, 16 );
		call_script( index, value );
	}	
	else
		call_script( line, value );
	std::cout << "current val in accumulator  " << accumulator << std::endl;
 
	return 0;
}

void Compiler_asm::call_script(const std::string& pFunction, int value)
{
	auto fp = functionMap[pFunction];
    (this->*fp)(value);
}


void Compiler_asm::init_functionMap() {
	functionMap.emplace("0000", &Compiler_asm::HALT);
	functionMap.emplace("0001", &Compiler_asm::NEGATE);
	functionMap.emplace("1", &Compiler_asm::MLOAD);
	functionMap.emplace("2", &Compiler_asm::DLOAD);
	functionMap.emplace("3", &Compiler_asm::ILOAD);
	functionMap.emplace("4", &Compiler_asm::DSTORE);
	functionMap.emplace("5", &Compiler_asm::ISTORE);
	functionMap.emplace("6", &Compiler_asm::JMP);
	functionMap.emplace("7", &Compiler_asm::JZ);
	functionMap.emplace("8", &Compiler_asm::JP);
	functionMap.emplace("9", &Compiler_asm::JN);
	functionMap.emplace("A", &Compiler_asm::ADD);
}

void Compiler_asm::MLOAD( int value ) {
	accumulator = value;
}

void Compiler_asm::DLOAD( int value ) {
	accumulator = memory[ value ];
}

void Compiler_asm::ILOAD( int value ) {
	accumulator = memory[memory[ value ]];
}

void Compiler_asm::DSTORE( int value ) {
	memory[ value ] = accumulator; 
}

void Compiler_asm::ISTORE( int value ) {
	memory[ memory[value] ] = accumulator;
}

void Compiler_asm::HALT( int val) {
	return;
}

void Compiler_asm::JMP( int dir ) {
	programCounter = dir;
}

void Compiler_asm::JZ( int value )  {
	if( accumulator = 0 )
		programCounter = value;

}

void Compiler_asm::JP( int value ) {
	if( accumulator > 0 )
		programCounter = value; 
	else
		programCounter++;
}

void Compiler_asm::JN( int value ) {
	if( accumulator < 0 )
		programCounter = value;
	else
		programCounter++;
}

void Compiler_asm::ADD( int value ) {
	accumulator += memory[value];
}

void Compiler_asm::NEGATE( int val) {
	accumulator = -1*accumulator;
}