#include <stdio.h>
#include <stddef.h>

#define HEAP_SIZE 1024
static char heap[HEAP_SIZE];
static size_t __aloc__ = 0;

void* malloc1(size_t size) {
    if (__aloc__ + size > HEAP_SIZE)
        return NULL;
    void* ptr = heap + __aloc__;
    __aloc__ += size;
    return ptr;
}
void* calloc1(size_t n , size_t size){
    if(__aloc__+n*size > HEAP_SIZE ) return NULL;
    void* ptr = malloc(n * size);
    if(ptr != NULL){
        memset(ptr,0,size*n);

    }
    return ptr;
}
#define free1(z) (__aloc__ -= (z))  // Works like stack only

int main() {
    int *ptr1 = (int*)malloc1(10 * sizeof(int));
    if (ptr1 == NULL) {
        printf("Out of memory\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        ptr1[i] = i * 10;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr1[i]);
    }
    printf("\n");

    free1(10 * sizeof(int));

    return 0;
}
