#include "book.h"
#include <stdio.h>
#include "cuda.h"

int main(void)
{
    cudaDeviceProp prop;

    int count;

    HANDLE_ERROR( cudaGetDeviceCount (&count));

    for (int i = 0;i<count; i++)
    {
        HANDLE_ERROR(cudaGetDeviceProperties(&prop,i));
        /*
         * Do other operation on the properties of GPU
         */
        printf("   --- General Information for device %d ---",i);
        printf("Name: %s\n",prop.name);
        printf("Computer capability: %d.%d\n",prop.major,prop.minor);
        printf("Clock rate : %d\n",prop.clockRate);
        printf("Device copy overlap: ");
        if (prop.deviceOverlap)
            printf("Enabled\n");
        else
            printf("Disabled\n");
    }
}
