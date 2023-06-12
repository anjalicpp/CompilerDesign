Program 5: Design a LEX Code to count the number of total characters, words, white spaces in 
a given “Input.txt” file. 
Source Code 
%{ 
int n,w,c; 
%} 
%% 
[ \n\t] {n++;} 
[^ \n\t]+ {w++;c=c+yyleng;} 
%% 
int yywrap() 
{ return 1 
; 
} int 
main() { 
extern FILE *yyin; 
yyin=fopen("Input.txt","r"); yylex(); 
printf("whitespace=%d word=%d total char=%d \n",n,w,n+c); 
}
