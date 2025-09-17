/*WAP to implement the following task
Parent Process writes the data into the pipe , after writing child process will read
the data , and converts the each letter into opposite case after that again child process writes back
into the pipe , parent  processs will read data from the pipe and display */
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
    if(fork() == 0)
    {
        char buf[100];
        read(fd[0],buf,sizeof(buf));
        printf("In child Process Data Receives : %s\n",buf);
        int i=0;
        while(buf[i] != '\0')
        {
            if(buf[i] >= 'a' && buf[i] <= 'z')
            {
                buf[i] = buf[i] - 32;
            }
            else if(buf[i] >= 'A' && buf[i] <= 'Z' )
            {
                buf[i] = buf[i] + 32;
            }
            i++;
        }
        write (fd[1],buf,strlen(buf)+1);
        

    }
    else
    {
        char buf[100];
        printf("Enter the Data: ");
        scanf("%[^\n]",buf);

        write (fd[1],buf,strlen(buf)+1);
        sleep(1); // delay for context switching 
        read(fd[0],buf,sizeof(buf));
        printf("After Conversion of each letter : %s\n",buf);
    }


}
