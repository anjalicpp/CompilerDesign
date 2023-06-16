Program 7: Lex code for removing C-comment from C-program. 
Source Code 
%{ 
 
%} 
 
%% 
 
"//"[^\n]* ; "/*"([^*]|[*]+[^/])*[*]+"/" ; 
. fprintf(yyout,"%s",yytext); 
 
%% 
 int main() 
 
{ extern FILE *yyin,*yyout; 
yyin=fopen("Input.c","r"); 
yyout=fopen("Out.c","w"); 
yylex(); 
} 
