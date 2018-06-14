#ifndef COMPILER_H
#define COMPILER_H

// #include <string>
#include <bits/stdc++.h>

class Compiler_asm {
public:
	std::string fileName;

public:
	void compile( std::string file );
	int getFunctionFromLine();



};



#endif