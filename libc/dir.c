/*directory functions*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <syscall.h>
#include <string.h>
#define VADDR 0xFFFFFFFF80000000


/*struct dirent
{
	long d_ino;
	off_t d_off;
	unsigned short d_reclen;
	char d_name [NAME_MAX+1];
};
*/



/*typedef struct DIR
{
	struct file* fp;
	uint64_t addr;
		//struct dirent curr;
}DIR;*/
//volatile int tan=1;
void* opendir (const char *dirname)
{
	uint64_t ret;
	//while(1);
	//printf("DIR NAME%s\n",dirname);
	//printf("SYS NUM%s\n",SYS_opendir);
	//while(1);
	//char st[5]="bin\\";
	//dirname=st;
	ret =(uint64_t)syscall_1(((uint64_t)(15)),((uint64_t)(dirname)));
     //  printf("%sinsidedir",ret);
	//while(1);
	//struct files_list* fl=(struct files_list*)ret;
	//printf("A ADDRopen:%x\n",fl->addr);
	//printf("A ADDR:%s\n",dir->name);		
	
	//ret=(uint64_t)a;
	return (void*)ret;
	//DIR* dp;
	//while(tan);
	//printf("hi\n");
	//while(1);
	 //dp = (DIR*)syscall_2(SYS_opendir, (uint64_t)dirname, (uint64_t)(1));
	//return (void*)dp;

	//ret =syscall_3(((long)(SYS_write)),((long)(fd)),((long)(buf)),((long)(count)));
	/*if(dp->fp != NULL) {
		return dp;
	} 
	else {
		free(dp);
		return NULL;
		}*/
	

}

struct dirent* readdir(void *dirp)
{
	uint64_t ret;
	ret=(uint64_t)syscall_1(((uint64_t)(16)), (uint64_t)dirp);
		
	
	return (struct dirent*)ret;
	
}

/*int getdents(unsigned int fd, struct dirent *dirp, unsigned int count)
{
	uint64_t ret;
	ret=(uint64_t)syscall_3(((uint64_t)(78)), ((uint64_t)fd),((uint64_t)dirp),((uint64_t)count));
		
	
	return (struct dirent*)ret;
	
}*/



int closedir(void *dirp)
{	
	
	int v=(int)syscall_1((uint64_t)(17), (uint64_t)(dirp));
	//printf("closedir done %d\n",v);
	if(v==1)
	{
		
		//free(dirp);		
		return 1;
	}
	else
		return 0;

}

int open(const char *pathname, int flags)
{
	
	//if(/*(strlen(pathname)<1)||*/(flags==1))
	//	return -1;
	//else
		//printf("in uopen");
		 return (int)syscall_2((uint64_t)(7), (uint64_t)pathname, (uint64_t)flags);

}

ssize_t uread(int fd, void *buf, size_t count)
{
	 ssize_t rt;
	//printf("in uread");
        rt =(ssize_t)syscall_3(((uint64_t)(0)),((uint64_t)(fd)),((uint64_t)(buf)),((uint64_t)(count)));
		//printf("%s",(char*)buf);
        return rt;
	

}

int close(int fd)
{
        int ret;
        ret =syscall_1(((uint64_t)(3)),((uint64_t)(fd)));
	if(ret==0)
		return 0;
	else 
		return -1;
        //return ret;
}

off_t lseek(int fildes, off_t offset, int whence)
{
	uint64_t ret= (uint64_t)syscall_3(((uint64_t)(8)),((uint64_t)(fildes)),((uint64_t)(offset)),((uint64_t)(whence)));
	return (off_t)ret;

}

/*void close(int file_d)
{
   syscall_1(SYS_close, (uint64_t)file_d);
}*/
/*int uread(uint64_t fd, void *buf, uint64_t nbytes)
{
    return syscall_3(SYS_read, fd, (uint64_t)buf, nbytes);
}*/










