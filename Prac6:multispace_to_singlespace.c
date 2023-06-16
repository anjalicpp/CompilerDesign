Program 6: Lex code for replacing multiple whitespaces by single space 
 
Source Code 
%{ 
 
%} 
 
%% 
 
	. 	fprintf(yyout,"%s",yytext); 
 
%% 
 
int yywrap() 
{ return 1 
 
; }
int 
 main() 
 
{ extern FILE *yyin,*yyout;
yyin=fopen("Input.txt","r"); 
yyout=fopen("Output.txt","w");
yylex(); 
} 
