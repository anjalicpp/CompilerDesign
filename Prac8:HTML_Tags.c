Program 8: Design a LEX Code to extract all html tags in the given HTML file at run time and store into Text file given at run time 
Source Code 
%{ 
 
%} 
 
%% "<"[^>]*">" ; 
. fprintf(yyout,"%s",yytext); 
 
%% 
 int yywrap() 
 
{ return 1 ; }

int main(int args, char **argv)
{ extern FILE *yyin,*yyout;
 yyin=fopen(argv[1],"r"); 
 yyout=fopen(argv[2],"w");
 yylex(); 
} 
