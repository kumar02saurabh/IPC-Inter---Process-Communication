// How to use Named Pipe Process:1
#include<stdio.h>
#include<fcntl.h>
int main()
{
    int fd;
    mkfifo("File",0644);
    perror("mkfifo");
    printf("Hello Bangalore\n");
    fd = open("File",O_RDONLY);
    if(fd<0)
    {
        perror("open");
        return 0;
    }
    printf("Process P2 is terminated...\n");
}

