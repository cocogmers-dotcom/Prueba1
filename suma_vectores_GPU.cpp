#include <hip/hip_runtime.h>
#include <iostream>
#include <vector>

// El Kernel: cada hilo de la GPU sumará una posición del vector
__global__ void vector_add_kernel(float* a, float* b, float* c, int n) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n) {
        c[i] = a[i] + b[i];
    }
}

int main() {
    int n = 100000000; // Vamos a sumar 1 millón de números
    size_t size = n * sizeof(float);

    // Datos en la CPU (Host)
    std::vector<float> h_a(n, 1.0f); // Lleno de 1.0
    std::vector<float> h_b(n, 2.0f); // Lleno de 2.0
    std::vector<float> h_c(n, 0.0f);

    // Punteros para la memoria de la GPU (Device)
    float *d_a, *d_b, *d_c;

    // Reservar memoria en los 8GB de tu RX 9060 XT
    hipMalloc(&d_a, size);
    hipMalloc(&d_b, size);
    hipMalloc(&d_c, size);

    // Copiar datos de la PC a la GPU
    hipMemcpy(d_a, h_a.data(), size, hipMemcpyHostToDevice);
    hipMemcpy(d_b, h_b.data(), size, hipMemcpyHostToDevice);

    // Configurar la ejecución (Bloques de 256 hilos)
    int threadsPerBlock = 256;
    int blocksPerGrid = (n + threadsPerBlock - 1) / threadsPerBlock;

    // ¡Lanzar el cálculo!
    for(int j = 0; j < 100; j++) {
    vector_add_kernel<<<blocksPerGrid, threadsPerBlock>>>(d_a, d_b, d_c, n);
    }
    hipDeviceSynchronize();

    // Traer el resultado de vuelta a la CPU
    hipMemcpy(h_c.data(), d_c, size, hipMemcpyDeviceToHost);

    // Verificar el último resultado
    std::cout << "Resultado final [999999]: " << h_c[n-1] << " (Debería ser 3)" << std::endl;

    // Liberar memoria
    hipFree(d_a); hipFree(d_b); hipFree(d_c);
    return 0;
}

//si hago una modificaion que pex