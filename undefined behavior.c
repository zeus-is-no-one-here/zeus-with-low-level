#include <stdio.h>
#include <stdlib.h>


void trash_heap(int *p){
     p = malloc(sizeof(int)*3);
     printf("%p",p[1000000000000000]);
      // undefined behavior
     free(p);
    // Note: Accessing p[1000000000000000] is undefined behavior and may crash the program.
    // Always ensure array bounds are respected when accessing memory.
     //....
}
int main(){
    int *p = NULL;
    trash_heap(p);
 
}
