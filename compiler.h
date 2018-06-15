#ifndef COMPILER_H
#define COMPILER_H

#include <bits/stdc++.h>
typedef void (*ScriptFunction)( int );
typedef std::unordered_map<std::string, ScriptFunction> script_map;

extern mem[128];
extern int acc;
extern int pc;
extern std::unordered_map<std::string, std::string> memory;

void MLOAD( int value ); 
void DLOAD( int value ); 
void ILOAD( int value ); 
void DSTORE( int value ); 
void ISTORE( int value ); 
void HALT( int value ); 
void JMP( int value ); 
void JZ( int value ); 
void JP( int value ); 
void JN( int value ); 
void ADD( int value ); 
void NEGATE( int value ); 

class Compiler_asm {
public:
	int fileName;
	std::vector< int > physicMemory;
	script_map functionMap;

public:
	void compile( int file );
	int process( int line );

	void init_functionMap();
};



#endif