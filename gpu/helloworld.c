#include <iostream>

/*
 * the global parameter tell the compiler to build code for GPU device
 */
__global__ void kernel(void)
{}

int main(void)
{
    kernel<<<1,1>>>();
    printf("Hello,World.\n");
    return 0;
}
