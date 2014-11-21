%{
#include<stdio.h>
%}
%token NUM
%left '+' '-'
%left '*' '/'
%left '(' ')'
%%
expr:e {printf("Result=%d\n",$$);return 0;}
e:e'+'e {$$=$1+$3;}
 |e'-'e {$$=$1-$3;}
 |e'*'e {$$=$1*$3;}
 |e'/'e {$$=$1/$3;}
 |'('e')' {$$=$2;}
 |NUM {$$=$1;}
 ;
%%
main()
{
printf("\nEnter the arithmetic expression");
yyparse();
printf("\nValid expresssion\n");
}
yyerror()
{
printf("\nInvalid expression\n");
exit(0);
}
