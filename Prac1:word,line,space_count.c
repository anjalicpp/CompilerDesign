
Program 1: Lex code for counting the number of lines, spaces, tabs, the and rest of the characters. 
Source Code 
%{ int 
n,m,t,c; 
%} 
%% 
\n n++; 
\t m++; 
[ ] t++; 
. c++; 
%% 
int yywrap() 
{ 
return 1; 
} 
int main() 
{ yylex(); 
printf("Total number of\nlines=%d \ntabs=%d\nspaces=%d\nchars=%d \n",n,m,t,c); }
