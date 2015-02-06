

#ifndef _YYDEFS_H_
#define _YYDEFS_H_

#define YYLTYPE YYLTYPE
typedef struct {
    int start, end;
} YYLTYPE;

#define YYLLOC_DEFAULT(Current, Rhs, N) \
    do { \
        if (N) { \
            (Current).start = YYRHSLOC(Rhs, 1).start; \
            (Current).end = YYRHSLOC(Rhs, N).end; \
        } else { \
            (Current).start = YYRHSLOC(Rhs, 0).start; \
            (Current).end = YYRHSLOC(Rhs, 0).end; \
        } \
    } while (0)

int yylex();

#endif
