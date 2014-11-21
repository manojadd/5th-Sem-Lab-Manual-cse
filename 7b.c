#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
 int pid,n,i;
 char cmd[14];
 system("clear");
 pid=fork();
 if(!pid)
 { printf("\nEnter command:\n");
   scanf("%s",cmd);
   system(cmd);
 }
 wait();
 return 0;
}
