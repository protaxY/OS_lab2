#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    FILE *file = fopen(argv[1], "w");
    printf("%s\n", argv[0]);
    if (file == NULL){
        printf("fopen error\n");
        return -1;
    }
    float result = 0;
    float currentTerm;
    while (read(fileno(stdin), &currentTerm, sizeof(float)) > 0){
        result += currentTerm;
    }
    fprintf(file, "%f", result);
    fclose(file);
    return 0;
}
