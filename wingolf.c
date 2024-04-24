#include <stdio.h>

#include "wingolf.h"

#define NUM_LEN_LIMIT 6
#define BUFSIZE 1024 // avoids invalid command being repeated

void h()
{
    puts("hello");
}
void H()
{
    puts("Hello");
}
void w()
{
    puts("hello world");
}
void W()
{
    puts("Hello World!");
}
void q()
{
    putchar('q');
    putchar('\n');
}
void b()
{
    char ending[2] = "s";
    char num[3] = "99";
    for (int i = 99; i > 0; i--) {
        printf("\n%s bottle%s of beer on the wall,\n\
%s bottle%s of beer.\n\
Take one down, pass it around,\n",
               num, ending, num, ending);
        if (i - 1 == 1) {
            ending[0] = '\0';
        } else {
            ending[0] = 's';
        }
        if (i - 1 == 0) {
            snprintf(num, sizeof(num), "No");
        } else {
            snprintf(num, sizeof(num), "%d", i - 1);
        }
        printf("%s bottle%s of beer on the wall.", num, ending);
    }
    putchar('\n');
}

void f()
{
    for (;;);
}

void i()
{
    char buf[BUFSIZE];
    fgets(buf, sizeof(buf), stdin);
}

void I()
{
    while (getchar() != EOF);
}

void c()
{
    char buf[BUFSIZE];
    fgets(buf, sizeof(buf), stdin);
    fputs(buf, stdout);
}

void C()
{
    char buf[8192];
    while (fgets(buf, sizeof(buf), stdin)) {
        fputs(buf, stdout);
    }
}

void t()
{
    int n;
    scanf("%d", &n);
    while (getchar() != '\n');
    if (!n) {
        putchar('0');
    }
    if (n == 1) {
        for (;;) {
            putchar('1');
            putchar('\n'); // creative liberty to write a newline
        }
    }
    putchar('\n');
}

int s_e_i(char *buf)
{
    long s = 1, e = 0, i = 1;
    // upper bound 9,999,999 (no commas obviously)
    int ind, tmp;
    for (ind = 0; ind < NUM_LEN_LIMIT && buf[ind] >= '0' && buf[ind] <= '9';
            ind++) {
        e = e * 10 + buf[ind] - '0';
    }
    // check if e is still continuing or next char is not a ('_' or '\0')
    if (buf[ind] != '_' && buf[ind] != '\0' && buf[ind] != '\n') {
        return 1;
    }
    if (buf[ind] == '_') {
        s = e;
        e = 0;
        tmp = ind + 1;
        for (ind = ind + 1;
                ind < NUM_LEN_LIMIT + tmp && buf[ind] >= '0' && buf[ind] <= '9';
                ind++) {
            e = e * 10 + buf[ind] - '0';
        }
        if (buf[ind] != '_' && buf[ind] != '\0' && buf[ind] != '\n') {
            return 1;
        }
        if (buf[ind] == '_') {
            i = 0;
            tmp = ind + 1;
            for (ind = ind + 1;
                    ind < NUM_LEN_LIMIT + tmp && buf[ind] >= '0'
                    && buf[ind] <= '9'; ind++) {
                i = i * 10 + buf[ind] - '0';
            }
            if (buf[ind] != '\0' && buf[ind] != '\n') {
                return 1;
            }
        }
    }
    for (long x = s; x <= e; x += i) {
        printf("%ld\n", x);
    }
    return 0;
}

int interpret_golf(char *buf)
{
    // will ignore all input after a valid command as noise.
    // s_e_i special case
    if (buf[0] >= '0' && buf[0] <= '9') {
        return s_e_i(buf);
    }
    // commands are only 1 char long except for the s_e_i command, so if the
    // check above fails and the next char is not a newline or null, it's an
    // invalid command and the function exits before the switch statement.
    if (buf[1] != '\0' && buf[1] != '\n') {
        return 1;
    }
    switch (buf[0]) {
        case '\n': // empty buffer
        case '\0':
            return 0;
        case 'h':
            h();
            return 0;
        case 'H':
            H();
            return 0;
        case 'w':
            w();
            return 0;
        case 'W':
            W();
            return 0;
        case 'q':
            q();
            return 0;
        case 'b':
            b();
            return 0;
        case 'f':
            f();
            return 0;
        case 'i':
            i();
            return 0;
        case 'I':
            I();
            return 0;
        case 'c':
            c();
            return 0;
        case 'C':
            C();
            return 0;
        case 't':
            t();
            return 0;
        case '?':
            puts(HELP);
            return 0;
        default: // invalid command
            return 1;
    }
}

int main(int argc, char **argv)
{
    char buf[BUFSIZE];
    if (argc >= 3) {
        fputs("Too many arguments", stderr);
        return 1;
    }
    if (argc == 1) { // cli mode
        for (;;) {
            fputs("\n>>> ", stdout);
            if (!fgets(buf, sizeof(buf), stdin)) {
                putchar('\n');
                return 0;
            }
            if (interpret_golf(buf)) {
                fputs("Invalid command!", stdout);
            }
        }
    }
    if (argc == 2) { // read file
        FILE *f;
        if ((f=fopen(argv[1], "r"))) {
            while (fgets(buf, sizeof(buf), f)) {
                interpret_golf(buf);
            }
            fclose(f);
        } else {
            fputs("Invalid file.\n", stderr);
        }
    }
}

