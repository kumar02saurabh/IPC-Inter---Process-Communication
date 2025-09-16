// WAP to share a data b/w related process using pipe

#include <stdio.h>
#include <unistd.h>
#include<string.h>
int main()
{
    int fd[2], ret;

    if ((ret = pipe(fd)) < 0)
    {
        perror("pipe");
        return 0;
    }

    printf("FD[0] : %d\n",fd[0]);
    printf("FD[1] : %d\n",fd[1]);

    if(fork() == 0)
    {
        char buf[50];
        read(fd[0],buf,sizeof(buf));
        printf("In Child Process : The data is %s\n",buf);

    }
    else
    {
        char buf[50];
        printf("Enter the data:");
        scanf("%s",buf);

        write(fd[1],buf,strlen(buf)+1);

    }
}
