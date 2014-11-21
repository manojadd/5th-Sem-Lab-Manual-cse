#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
//#include<sys/stat.h>
//#include<sys/types.h>
int main()
{
 char buff1[] = "abcdefghijklmnop";
 char buff2[] = "ABCDEFGHIJKLMNOP";
 int fd;
 fd =open("new.txt",O_WRONLY|O_CREAT,777); //unsuccessful -1,wr if exist,creat if not exist then 777.
 write(fd,buff1,16);
 lseek(fd,48,SEEK_SET);//seekset is absolute.
 write(fd,buff2,16);
 close(fd);
 printf("contents of file are \n");
 system("gedit new.txt");
 exit (0);
}
