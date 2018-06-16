#ifndef COMPILER_H
#define COMPILER_H

#include <bits/stdc++.h>
typedef void (*ScriptFunction)( int );
typedef std::unordered_map<std::string, ScriptFunction> script_map;

extern int memory[128];

extern int accumulator;
extern int programCounter;

void MLOAD( int value ); 
void DLOAD( int value ); 
void ILOAD( int value ); 
void DSTORE( int value ); 
void ISTORE( int value ); 
void HALT( int val); 
void JMP( int value ); 
void JZ( int value ); 
void JP( int value ); 
void JN( int value ); 
void ADD( int value ); 
void NEGATE( int val ); 

class Compiler_asm {
public:
	std::string fileName;
	std::vector< std::string > physicMemory;
	script_map functionMap;
	int memory[128] = {0};

public:
	void compile( std::string file );
	int process( std::string line );
	void call_script(const std::string& pFunction, int value);

	void init_functionMap();
};



#endif