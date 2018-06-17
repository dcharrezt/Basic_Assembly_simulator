#ifndef COMPILER_H
#define COMPILER_H

#include <bits/stdc++.h>


class Compiler_asm {
public:
	typedef void (Compiler_asm::*ScriptFunction)( int );
	typedef std::unordered_map<std::string, ScriptFunction> script_map;

	std::string fileName;
	std::vector< std::string > physicMemory;
	script_map functionMap;
	int memory[128];
	int accumulator;
	int programCounter;

public:
	void compile( std::string file );
	int process( std::string line );
	void call_script(const std::string& pFunction, int value);

	void init_functionMap();




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
};



#endif