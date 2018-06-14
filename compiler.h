#ifndef COMPILER_H
#define COMPILER_H

#include <bits/stdc++.h>
typedef void (*ScriptFunction)( std::string );
typedef std::unordered_map<std::string, ScriptFunction> script_map;

extern std::string acc;
extern std::unordered_map<std::string, std::string> memory;

void MLOAD( std::string value ); 
void DLOAD( std::string value ); 
void ILOAD( std::string value ); 
void DSTORE( std::string value ); 
void ISTORE( std::string value ); 
void HALT( std::string value ); 
void JMP( std::string value ); 
void JZ( std::string value ); 
void JP( std::string value ); 
void JN( std::string value ); 
void ADD( std::string value ); 
void NEGATE( std::string value ); 

class Compiler_asm {
public:
	std::string fileName;
	std::vector< std::string > physicMemory;
	script_map functionMap;


public:
	void compile( std::string file );
	int process( std::string line );

	void init_functionMap();
};



#endif