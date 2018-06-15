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
	for (int i = 0; i < physicMemory.size(); ++i)
	{
		process( physicMemory[i] );
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
	functionMap.emplace("0000",);
	functionMap.emplace("0001",);
	functionMap.emplace("1",);
	functionMap.emplace("2",);
	functionMap.emplace("3",);
	functionMap.emplace("4",);
	functionMap.emplace("5",);
	functionMap.emplace("6",);
	functionMap.emplace("7",);
	functionMap.emplace("8",);
	functionMap.emplace("9",);
	functionMap.emplace("A",);
}



void MLOAD( int value ) {
	int acc = std::stoi( value, 0, 10 )
}

void DLOAD( int value ) {
	acc = mem[value];
}

void ILOAD( int value ) {
	acc = mem[ mem[value] ];
}

void DSTORE( int value ) {
	int acc;
	std::unordered_map<std::string, std::string> memory;
	acc += std::stoi( memory[value], 0, 16 );
}

void ISTORE( int value ) {
	int acc;
	int mem[50];
	mem[ mem[value] ] = acc;
}

void HALT( int value ) {
	return;
}

void JMP( int dir ) {
	pc = dir;
}

void JZ( int value )  {
	if( acc = 0 );

}

void JP( int value ) {
	if( acc > 0 );
		pc = value;
	else
		pc++;
}

void JN( int value ) {
	if( acc < 0 )
		pc = value;
	else
		pc++;
}

void ADD( int value ) {
	std::unordered_map<std::string, std::string> memory;
	std::string acc;
	memory[value];
}

void NEGATE( int value ) {
	acc = -1*acc;
}