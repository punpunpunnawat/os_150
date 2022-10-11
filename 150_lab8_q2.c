#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("child created\n");
        while (1);
        printf("this line should not be show\n");
        exit(0);
    }
    else
    {
        sleep(0);
        kill(pid, SIGINT);
    }
    printf("child has been killed\n");
    return 0;
}