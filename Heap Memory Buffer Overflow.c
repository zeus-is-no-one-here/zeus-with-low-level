#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc , char *argv[]){
    char *input = malloc(77);
    char *output = malloc(77);
    strcpy(output , "normal out pot 77");
    strcpy(input,argv[1]);
    printf ("input at %p: %s\n", input, input);
    printf ("output at %p: %s\n", output, output);
    printf("\n\n%s\n", output);

}
