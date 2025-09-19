// Share the data from one process to another process 
// sending the data
// This communication is also called Simplex Comm
#include<stdio.h>
#include<fcntl.h>
int main()
{
    int fd;
    mkfifo("File",0644);
    perror("mkfifo");

    printf("Hello..\n");
    fd = open ("File",O_WRONLY);
    if(fd < 0)
    {
        perror("open");
        return 0;
    }

    char buf[100];

    printf("Enter The data to send:");
    scanf("%s",buf);
    write(fd,buf,strlen(buf)+1);

}
