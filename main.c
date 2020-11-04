#include <stdio.h>
#include <unistd.h>

int main(){
    printf("enter file name:");
    char filename[256];
    scanf("%s", filename);
    int fd[2];
    if (pipe(fd) == -1){
        printf("pipe error\n");
        return -1;
    }
    int id = fork();
    if (id == -1){
        printf("fork error\n");
        return -1;
    }
    else if (id == 0){
        close(fd[1]);
        if (dup2(fd[0], fileno(stdin)) == -1){
            printf("dup2 error\n");
            return -1;
        }
        char* argv[3] = {"child", filename, (char *)NULL};
        if (execv("child", argv) == -1){
            printf("execl error\n");
        }
    }
    else{
        close(fd[0]);
        printf("insert sum terms:");
        float currentTerm;
        while(scanf("%f", &currentTerm) > 0){
            if (write(fd[1], &currentTerm, sizeof(float)) == 0){
                printf("write error\n");
                return -1;
            }
        }
        close(fd[1]);
    }
    return 0;
}
