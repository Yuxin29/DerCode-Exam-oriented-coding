#include <stdlib.h> //malloc, free, exit,
#include <unistd.h> //write, close, fork, chdir, execve, dup, dup2, pipe
#include <sys/wait.h> //waitpid,
#include <string.h> //strcmp. strncmp
// not use // signal, kill

void ft_putstr_fd2(char *str, char *arg) //print error msg and arg with std error
{
    while (*str)
        write(2, str++, 1);
    if (arg)
    {
        while (*arg)
            write(2, arg++, 1);
    }
    write(2, "\n", 1);
}

void ft_execute(char *argv[], int i, int tmp_fd, char *env[])
{
    argv[i] = NULL; //change ; / | to null so argv is one cmd, chaged in child proc
    close(tmp_fd);
    execve(argv[0], argv, env); // exec in child process
    ft_putstr_fd2("error: cannot execute", argv[0]);
    exit(1);
}

int main(int argc, char *argv[], char *env[])
{
    int i = 0;
    int fd[2];
    int fd_tmp = dup(STDIN_FILENO);
    (void)argc;
    while (argv[i] && argv[i + 1])
    {
        argv = &argv[i + 1];    //?
        i = 0;                  //?
        while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
            i++;
        // build in cd    
        if (strcmp(argv[0], "cd") == 0)
        {
            if (i != 2)
                ft_putstr_fd2("error: cd: bad argument after cd", NULL);
            else if (chdir(argv[1]) != 0)
                ft_putstr_fd2("error: cd: cannot change directory to ", argv[1]);
        }
        // one cmd end with ; exec by order, n      o other relationship,       $? only the last exit stat
        else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
        {
            if (fork() == 0)
                ft_execute(argv, i, fd_tmp, env);
            else
            {
                close(fd_tmp);
                while (waitpid(-1, NULL, WUNTRACED) != -1)
                    ;
                fd_tmp = dup(STDIN_FILENO);
            }
        }
        //one cmd end with |    exec at the same time, first output as 2nd input  $? the last exit stat
        else if (i != 0 && strcmp(argv[i], "|") == 0)
        {  
            pipe(fd);
            if (fork() == 0)
            {
                dup2(fd[1], STDOUT_FILENO);
                close(fd[0]);
                close(fd[1]);
                ft_execute(argv, i, fd_tmp, env);
            }
            else
            {
                close(fd[1]);
                close(fd_tmp);
                fd_tmp = fd[0];
            }
        }
    }
    close(fd_tmp);
    return 0;
}