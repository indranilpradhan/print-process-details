#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argcount, char** arg,char* envariables[])
{
	int pid = 0;
	DIR* directory = opendir("/proc");
	struct dirent *dir;
	int fileopen;
	int runningprocess;
if(argcount == 1)
{
	while((dir= readdir(directory)) != NULL )
	{
		if((atoi(dir->d_name)) != 0)
		{	
			char procdetails[100][100]; 
    			int i,m,n;
			int length;
			char buffer[100000];
			char fdbuf[1000];
			char proc[100] = "/proc/";
			strcat(proc,dir->d_name);
			strcat(proc,"/stat");
			fileopen = open(proc,O_RDONLY);
			while((length=read(fileopen,&buffer,100000))>0)
			{
 				m=0,n=0;
				
				for(i=0;i<=(strlen(buffer));i++)
    				{
				//printf("%s\t %s\t %s\t %s\n",buffer[1],buffer[2],buffer[3],buffer[5]);
        			if(buffer[i]==' '||buffer[i]=='\0')
        			{
					//printf("\n");
            				procdetails[m][n]='\0';
           				m++;
            				n=0;    
        			}
        			else
       				{
					//printf("%c\t", buffer[i]);
            				procdetails[m][n]=buffer[i];
            				n++;
        			}
    				}
				printf("%s\t %s\t %s\t %s\n",procdetails[1],procdetails[2],procdetails[3],procdetails[5]);
				
			}

		/*	char filedes[10] = "/proc/";
			strcat(filedes,dir->d_name);
			strcat(filedes,"/fd");
			struct dirent *fdir;
			DIR* fddirectory = opendir(filedes);
			while((fdir= readdir(fddirectory)) != NULL )
	                {
				strcat(filedes,"/");
				strcat(filedes,fdir->d_name);
				int fd = 0;
				fd = readlink(filedes,fdbuf,sizeof(fdbuf));
				if(fd >= 0)
				{
					fdbuf[fd] = '\0';
					printf("%s",fdbuf);
				}
			}
			closedir(fddirectory);
			*/
		}
	}
	closedir(directory);
}
if(argcount == 2)
{
	pid = atoi(arg[1]);
	while((dir= readdir(directory)) != NULL )
	{
		if((atoi(dir->d_name)) != 0)
		{
		   if((atoi(dir->d_name)) == pid)
		     {
			char procdetails[100][100]; 
    			int i,m,n;
			int length;
			char buffer[100000];
			char fdbuf[1000];
			char proc[10] = "/proc/";
			strcat(proc,dir->d_name);
			strcat(proc,"/stat");
			fileopen = open(proc,O_RDONLY);
			while((length=read(fileopen,&buffer,100000))>0)
			{
 				m=0,n=0;
				
				for(i=0;i<=(strlen(buffer));i++)
    				{
				//printf("%s\t %s\t %s\t %s\n",buffer[1],buffer[2],buffer[3],buffer[5]);
        			if(buffer[i]==' '||buffer[i]=='\0')
        			{
					//printf("\n");
            				procdetails[m][n]='\0';
           				m++;
            				n=0;    
        			}
        			else
       				{
					//printf("%c\t", buffer[i]);
            				procdetails[m][n]=buffer[i];
            				n++;
        			}
    				}
				printf("%s\t %s\t %s\t %s\n",procdetails[1],procdetails[2],procdetails[3],procdetails[5]);
			}
 
		/*	char filedes[10] = "/proc/";
			strcat(filedes,dir->d_name);
			strcat(filedes,"/fd");
			struct dirent *fdir;
			DIR* fddirectory = opendir(filedes);
			while((fdir= readdir(fddirectory)) != NULL )
	                {
				strcat(filedes,"/");
				strcat(filedes,fdir->d_name);
				int fd = 0;
				fd = readlink(filedes,fdbuf,sizeof(fdbuf));
				if(fd >= 0)
				{
					fdbuf[fd] = '\0';
					printf("%s\n",fdbuf);
				}
			}
			closedir(fddirectory);
	    */
		     }
			
		}
	}
	closedir(directory);
}

	 /*	char fdbuf[1000];
		int fd = 0;
		fd = readlink("/proc/root",fdbuf,sizeof(fdbuf));
		if(fd >= 0)
		{
			fdbuf[fd] = '\0';
			printf("%s",fdbuf);
		} */

	for(int i=0;envariables[i] != NULL;i++)
		printf("%s\n",envariables[i]);

	char fileprocess[100000];
	sprintf(fileprocess,"/proc/stat");
	FILE *file = fopen(fileprocess,"r");
	char linesize[10000]; 
	int count = 1;
	while(fgets(linesize, sizeof(linesize), file))
	{
		if(count == 11)
		{ 
			printf("%s",linesize);
		}
		if(count == 14)
		{ 
			printf("%s",linesize);
		}
		if(count == 15)
		{ 
			printf("%s",linesize);
		}
		count++;
	}
	fclose(file);

} 
