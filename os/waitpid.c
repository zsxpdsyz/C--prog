#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

// wait回收子进程111
int main(int argc, char *argv[]) {
    int rc = fork();
    if(rc < 0) {
        // fork 失败
        fprintf(stderr, "Fork failed\n");
    }
    else if(rc == 0) {
        // 子进程
        printf("Child process exit\n");
    }
    else {
        // 父进程
        int status = 0;
        if(waitpid(rc, &status, 0) < 0) {
            // wait 失败
            fprintf(stderr, "Parent process: waitpid failed\n");
            exit(-1);
        }
        // 确认子进程已经退出
        if(WIFEXITED(status)) {
            printf("Parent process: my child exited\n");
        }
        else {
            fprintf(stderr, "Parent process: waitpid returns for unknown reason\n");
        }
    }
}