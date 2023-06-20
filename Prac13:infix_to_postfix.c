Program 13 :Design a YAAC/LEX code that translates infix expression to postfix expression. 
 
Source Code 
 
ALPHA [A-Z a-z] 
DIGIT [0-9] 
%% 
	{ALPHA}({ALPHA}|{DIGIT})* 	return ID; 
	{DIGIT}+ 	{yylval=atoi(yytext); return ID;} 
	[\n \t] 	yyterminate(); 
	. 	return yytext[0]; 
%% 
 
%{ 
#include <stdio.h> 
#include <stdlib.h> 
%} 
	%token 	ID 
%left '+' '-' 
%left '*' '/' 
%left UMINUS 
 
%% 
 
	S 	: E 
	E 	: E'+'{A1();}T{A2();} 
| E'-'{A1();}T{A2();} 
| T 
; 
	T 	: T'*'{A1();}F{A2();} 
| T'/'{A1();}F{A2();} 
| F 
; 
F : '('E{A2();}')' 
| '-'{A1();}F{A2();} 
| ID{A3();} 
; 
 
%% 
 
#include "lex.yy.c" char st[100]; 
int top=0;
int main()
{ printf("Enter infix expression: ");
yyparse();
printf("\n"); 
} 
 
A1() 
{ st[top++]=yytext[0]; 
} 
 
A2() 
{ printf("%c",st[--top]); 
} 
 
A3() 
{ printf("%c",yytext[0]); 
}  
