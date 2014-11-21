%{#include<stdio.h>
  int top=-1,opn=0,opr=0,i,j;
  char s[20],a[20],b[20];
%}
%%
"(" {top++;}
")" {if(top==-1)
    {printf("invalid \n");exit(0);}
    else top--;
    }
[a-zA-Z0-9]	   {a[opn++]=yytext[0];}
[\+\-\*\/]         {b[opr++]=yytext[0];}
\n {return 0;}
%%
int main()
{
 printf("enter the expression\n");
 yylex();
 if((opn==1+opr)&&(top==-1))
 {
  printf("valid\n");
  printf("number of opn are %d \t there are \n",opn);
  for(j=0;j<opn;j++)
   printf("%c\n",a[j]);
  printf("\n number of opr are %d\t they are\n",opr);
  for(j=0;j<opr;j++)
   printf("%c\n",b[j]);
 }
else
 printf("invalid\n"); 
}
