# Basic_Assembly_simulator
C++11

Basic assembly simulator in c++.


Code  		Instruction

0000		HALT
0001		NEGATE
1XXX		MLOAD XXX
2XXX		DLOAD XXX
3XXX		ILOAD XXX
4XXX		DSTORE XXX
5XXX		ISTORE XXX
6XXX		JMP XXX
7XXX		JZ XXX
8XXX		JP XXX
9XXX		JN XXX
AXXX		ADD XXX

MLOAD value
ACC <- value
DLOAD dir
ACC<-M(dir)
ILOAD dir
ACC <- M(M(dir))
DSTORE dir
M(dir) <- ACC
ISTORE dir
M(M(dir))<- ACC
HALT
Program Ends
JMP dir
ProgramCounter <- dir
JZ dir
if acc = 0, ProgramCounter <- dir
JP dir
if acc > 0, ProgramCounter <- dir
JN dir
if acc < 0, ProgramCounter <- dir
ADD dir
ACC <- ACC + M[dir]
NEGATE
negates acc value