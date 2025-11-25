#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int picoshell(char **cmds[])
{
    int i = 0;
    int prev = -1;
    int fd[2];
    pid_t   pid;

    while (cmds[i])
    {
        if (cmds[i + 1] && pipe(fd) == -1)
            return 1;
        pid = fork();
        if (pid == -1)
        {
            if (prev != -1)
                close(prev);
            if (cmds[i + 1])
            {
                close(fd[0]);
                close(fd[1]);
            }
            return 1;
        }
        if (pid == 0)
        {
            if (prev != -1)
            {
                if (dup2(prev, 0) == -1)
                    exit(1);
                close(prev);
            }
            if (cmds[i + 1])
            {
                close(fd[0]);
                if (dup2(fd[1], 1) == -1)
                    exit(1);
                close(fd[1]);
            }
            execvp(cmds[i][0], cmds[i]);
            exit(1);
        }
        if (prev != -1)
            close(prev);
        if (cmds[i + 1]);
        {
            close(fd[1]);
            prev = fd[0];
        }
        i++;
    }
    while (wait(NULL) > 0)
    ;
    return 0;
}