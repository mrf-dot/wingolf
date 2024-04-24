#ifndef WINGOLF_H
#define WINGOLF_H
/*
 * based on https://esolangs.org/wiki/Win_Golf
 * h    Writes "hello" on the console
 * H    Writes "Hello!" on the console
 * w    Writes "hello world" on the console
 * W    Writes "Hello World!" on the console
 * q    Writes "q" on the console (can be used as a quine)
 * b    Writes the lyrics of 99 bottles of beer on the console
 * f    Makes a forever loop that does nothing
 * i    Asks for input
 * I    Asks for input infinite times
 * c    Executes the cat program
 * C    Executes the cat program infinite times
 * t    Truth Machine
 * {e}  Writes the numbers `1` to `e` with an increment of `1` (upper bound: 9,999,999)
 * {s}_{e}  Writes the numbers `s` to `e` with an increment of `1`
 * {s}_{e}_{i}  Prints the numbers `s` to `e` with an increment of `i`
 * ?    Prints the help message
 */
#define HELP "h\t\tWrites \"hello\" on the console\nH\t\tWrites \"Hello!\" on the console\nw\t\tWrites \"hello world\" on the console\nW\t\tWrites \"Hello World!\" on the console\nq\t\tWrites \"q\" on the console (can be used as a quine)\nb\t\tWrites the lyrics of 99 bottles of beer on the console\nf\t\tMakes a forever loop that does nothing\ni\t\tAsks for input\nI\t\tAsks for input infinite times\nc\t\tExecutes the cat program\nC\t\tExecutes the cat program infinite times\nt\t\tTruth Machine\n{e}\t\tWrites the numbers `1` to `e` with an increment of `1` (upper bound: 9,999,999)\n{s}_{e}\t\tWrites the numbers `s` to `e` with an increment of `1`\n{s}_{e}_{i}\tPrints the numbers `s` to `e` with an increment of `i`\n?\t\tPrints the help message"
// print "hello" to the console
void h();
// print "Hello" to the console
void H();
// print "hello world" to the console
void w();
// print "Hello World!" to the console
void W();
// write q to the console (quine)
void q();
// print the lyrics of 99 bottles of beer to the console
void b();
// make a forever loop that does nothing
void f();
// ask for input
void i();
// ask for input infinite times
void I();
// executes the cat program
void c();
// executes the cat program infinite times
void C();
// truth machine
void t();
// reads the buffer and attempts to iterate through the buffer to define the start, end, and increment variables. If the syntax of buffer is good, it will print and return 0, otherwise it will return 1
int s_e_i(char *buf);
// Take a buffer as input, return 0 if read successfully, 1 if "syntax error"
int interpret_golf(char *buf);
#endif

