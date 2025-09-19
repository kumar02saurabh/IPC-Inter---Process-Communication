// How to use Named Pipe Process:1
#include<stdio.h>
#include<fcntl.h>
int main()
{
    int fd;
    mkfifo("File",0644);
    perror("mkfifo");
    printf("Hello \n");
    fd = open("File",O_WRONLY);
    if(fd<0)
    {
        perror("open"); 
        return 0;
    }
    printf("Process P1 is terminated...\n");
}


