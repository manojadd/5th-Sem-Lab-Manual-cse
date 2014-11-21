#include<stdio.h>
#include<stdlib.h>
main()
{ 
 int pid,chpid;
 if((pid=fork())<0)// neagative failed.
  printf(" \n Creating a child process failed \n");
 if(pid == 0)
 {
  printf("child process: \n");
  printf("pid=%d \n",getpid());
  printf("ppid=%d \n",getppid());
  printf("child process with pid = %d is terminated \n",getpid());
  exit(0);
 }
 chpid=pid;
 wait(&pid);
 printf("parent process \n");
 printf("pid = %d \n",getpid());
 printf("child pid = %d",chpid);
}
