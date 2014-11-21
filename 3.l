%{
  #include<stdio.h>
  int count=0;
%}
%s ID
%%
"int " |
"float " |
"char " |
"double " {BEGIN ID;}
<ID>[0-9] {printf("wrong identifiers");exit(0);}
<ID>[_a-zA-z][a-zA-z0-9]* {count++;}
<ID>";" { BEGIN 0;}
<ID>\n ;
. ;
%%
main(int argc,char *argv[])
{
 yyin=fopen(argv[1],"r"); //returns null if error
 if(yyin)
 { yylex();
   printf("No. of identifier are:%d\n",count);
 }
 else printf("ERROR");
}
