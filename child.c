//
// Created by protaxy on 10/19/20.
//
#include <stdio.h>
#include <unistd.h>

int main(){
    float result = 0;
    float currentTerm;
    while (read(fileno(stdin), &currentTerm, sizeof(float)) > 0){
        result += currentTerm;
    }
    printf("%f", result);
    return 0;
}
