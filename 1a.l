%{#include<stdio.h>
 int ch=0,word=0,spc=0,ln=0;
%}
%%
[^ \t\n]+ {word++;ch=ch+yyleng;}
\n    {ln++;}
.     {spc++;}
%%
int main(int argc,char *argv[])
{
 if(argc==2)
 {
  yyin=fopen(argv[1],"r");//null if error
  if(!yyin)
  {
   printf("\n error opening a file %s\n",argv[1]);
   exit(0);  
  }
 }
 else
 {
  printf("argument count not correct\n");
  return 0;
 }
 yylex();
 printf("\n \n the no of:\n");
 printf("characters=%d\n words=%d\n lines=%d\n spaces=%d\n",ch,word,ln,spc);
 return 0;
}
