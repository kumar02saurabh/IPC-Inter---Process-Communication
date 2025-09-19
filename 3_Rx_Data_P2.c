// Share the data from one process to another process 
// Receiving the data 
// This communication is also called Simplex Comm
#include<stdio.h>
#include<fcntl.h>
int main()
{
    int fd;
    mkfifo("File",0644);
    perror("mkfifo");

    printf("Hello Bangalore ..\n");
    fd = open ("File",O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        return 0;
    }

    char buf[100];
    read(fd,buf,sizeof(buf));
    printf("%s\n",buf);

}

