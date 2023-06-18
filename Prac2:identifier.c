Program 2: Design a LEX Code to identify and print valid Identifier of C/C++ in given Input pattern.
Source Code


%{
int c=0;
%}
%%
[a-zA-Z_][a-zA-Z0-9_]* {c++; printf("\tvalid Identifier=%s",yytext);}
. ;
%%
int yywrap()
{
return 1 ;
int main()
{
yylex();
printf("\nTotal number of valid Identifier = %d \n",c);
} 
