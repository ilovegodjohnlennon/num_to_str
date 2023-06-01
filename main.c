#include "numbers.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    if(argc != 2){
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int num;
    if(sscanf(argv[1], "%d", &num) != 1){
        printf("Error parsing number!\n");
        return 2;
    }

    char* res = num_to_str(num);
    if(!res){
        printf("Some error in the function!\n");
        return 3;
    }

    printf("Result: %s\n", res);
    free(res);


    return 0;
}