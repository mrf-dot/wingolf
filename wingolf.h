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
 * {e}  Writes the numbers `1` to `e` with an increment of `1`
 * {s}_{e}  Writes the numbers `s` to `e` with an increment of `1`
 * {s}_{e}_{i}  Prints the numbers `s` to `e` with an increment of `i`
 */
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

