%{
#include<stdio.h>
%}
%token NUMBER ALPHA
%left '+''-'
%left '*''/'
%left '='
%left '('')'
%%
expr:'+'expr
	|'-'expr
	|expr'+'expr
	|expr'-'expr
	|expr'*'expr
	|expr'/'expr
        |expr'='expr
	|'('expr')'
	|NUMBER
	|ALPHA
	;
%%
int main()
{
printf("Enter an arithmetic expression\n");
yyparse();
printf("Arithmetic expression is valid\n");
return 0;
}
int yyerror(char *msg)
{
printf("\n%s",msg);
printf("\n Arithmetic expression is invalid\n");
exit(0);
}
