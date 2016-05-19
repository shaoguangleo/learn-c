/*
 * @filename : add.c
 */

#include <iostream>
#include "book.h"

__global__ void add(int a, int b, int *c)
{
    *c = a + b;
}

int main(void)
{
    int c;
    int *dev_c;
    /*
     * Will do malloc when has operation
     */
    HANDEL_ERROR(cudaMalloc((void**)&dev_c, sizeof(int)));

    add<<<1,1>>>(2,7,dev_c);

    HANDEL_ERROR(cudaMemcpy(&c,dev_c, sizeof(int),cudaMemcpyDevideToHost));

    printf("2 + 7 = %d\n",c);

    cudaFree(dev_c);

    return 0;
}
