#include "compiler.h"

void Compiler_asm::compile( std::string file ) {
	this->fileName = file;
	int accumulator;
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

	return 0;
}

void Compiler_asm::call_script(const std::string& pFunction, int value)
{
    auto iter = functionMap.find(pFunction);
    if (iter == functionMap.end())
    {
        std::cout << "Function not found " << std::endl;
    }

    (*iter->second)(value);
}


void Compiler_asm::init_functionMap() {
	functionMap.emplace("0000", &HALT);
	functionMap.emplace("0001", &NEGATE);
	functionMap.emplace("1", &MLOAD);
	functionMap.emplace("2", &DLOAD);
	functionMap.emplace("3", &ILOAD);
	functionMap.emplace("4", &DSTORE);
	functionMap.emplace("5", &ISTORE);
	functionMap.emplace("6", &JMP);
	functionMap.emplace("7", &JZ);
	functionMap.emplace("8", &JP);
	functionMap.emplace("9", &JN);
	functionMap.emplace("A", &ADD);
	// functionMap["0000"] = HALT;
	// functionMap["0001"]= NEGATE;
	// functionMap["1"] = MLOAD;
	// functionMap["2"] = DLOAD;
	// functionMap["3"] = ILOAD;
	// functionMap["4"] = DSTORE;
	// functionMap["5"] = ISTORE;
	// functionMap["6"] = JMP;
	// functionMap["7"] = JZ;
	// functionMap["8"] = JP;
	// functionMap["9"] = JN;
	// functionMap["A"] = ADD;
}

void MLOAD( int value ) {
	int accumulator = value;
	std::cout << "accumulator = " << accumulator << std::endl;
}

void DLOAD( int value ) {
	int memory[128];
	int accumulator = memory[ value ];
	std::cout << "accumulator = " << accumulator << std::endl;
}

void ILOAD( int value ) {
	int memory[128];
	// std::cout << "M = " << value << std::endl;
	std::cout << "accumulator = " << memory[ value ] << std::endl;

	int accumulator = memory[memory[ value ]];
}

void DSTORE( int value ) {
	int accumulator;
	int memory[128];
	memory[ value ] = accumulator; 
}

void ISTORE( int value ) {
	int accumulator;
	int memory[128];
	memory[ memory[value] ] = accumulator;
}

void HALT( int val) {
	std::cout << "Program Ended " << std::endl;
	return;
}

void JMP( int dir ) {
	int accumulator;
	int programCounter;
	programCounter = dir;
}

void JZ( int value )  {
	int accumulator;
	int programCounter;
	if( accumulator = 0 )
		programCounter = value;

}

void JP( int value ) {
	int accumulator;
	int programCounter;
	if( accumulator > 0 )
		programCounter = value; 
	else
		programCounter++;
}

void JN( int value ) {
	int accumulator;
	int programCounter;
	if( accumulator < 0 )
		programCounter = value;
	else
		programCounter++;
}

void ADD( int value ) {
	int accumulator;
	int memory[128];
	accumulator += memory[value];
}

void NEGATE( int val) {
	std::cout << val << std::endl;
	int accumulator;
	accumulator = -1*accumulator;
	std::cout<< "aacc " << accumulator << std::endl;
}