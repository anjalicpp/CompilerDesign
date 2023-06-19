Program 12 : Design a YAAC/ LEX Code to recognize valid arithmetic expression with operators +,-,*,/. 
 
Source Code a.y file 
%{ 
#include<stdio.h> int yylex(void); void yyerror(char *); 
%} 
 
%token digit 
%% 
S:S E '\n' {$$=$2;printf("output=%d\n",$$);} 
| ; 
E:E '+' T {$$=$1+$3;} 
|E '-' T {$$=$1-$3;} 
|T {$$ = $1;} 
; 
T: T '^' F {$$=$1*$3;} 
|T '/' F {$$=$1/$3;} 
|F {$$ = $1;} 
; 
F :digit {$$ = $1;} 
%% 
int main()
{ yyparse();
 return 0; 
} 
void yyerror(char *msg) 
{ printf("\n%s",msg); 
printf("\narithematic expression is invalid");
} 
} 

b.l file 
%{ 
#include<stdio.h> int yylval; 
#include"y.tab.h" 
%} 

%% 
[0-9]+ {yylval = atoi(yytext);return digit;} 
[-+*/\n] return *yytext; 
. ; 
%% 
  
int yywrap(void) 
{ 
  return 1;
} 

 
