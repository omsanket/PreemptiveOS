#include<stdio.h>
//#include<sys/utilities.h>
//#include<sys/defs.h>
#include<stdlib.h>
#include <string.h>


int main(int argc, char* argv[], char* envp[]) 
{

  char buf[100];//file_name[25];
   //FILE *fp;
 	int fp;int ch;
   printf("Enter the name of file you wish to see\n");
   
 
   fp = open("rootfs/mnt/amit.txt",O_RDONLY); // read mode
 
   if( fp == 0 )
   {
      printf("Error while opening the file.\n");
      
   }
 
   printf("The contents of file are :\n");
 
 read(fp,buf,10);
     printf("%s\n",buf);
ch=(int)lseek(fp,50,SEEK_SET);

ch= (int)read(fp,buf,10);
     printf("%s\n",buf);
ch--;
ch=close(fp);

 
// while(1);
  //getchar();
  exit(0);
}
