#include <hip/hip_runtime.h>
#include <iostream>

__global__ void hello_kernel() {
    printf("Hola desde la RX 9060 XT! \n");
}

int main() {
    // Lanzamos 1 hilo en la GPU
    hello_kernel<<<1, 1>>>();
    
    // Esperamos a que la GPU termine
    (void)hipDeviceSynchronize();
    return 0;
}