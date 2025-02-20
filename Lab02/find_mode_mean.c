#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Dizideki en çok tekrar eden sayıyı (mode) bulan fonksiyon
int find_mode(int array[], int size) {
    int maxCount = 0;    // En çok tekrar sayısını tutacak değişken
    int mode = array[0]; // Mode değerini tutacak değişken
    
    // Her sayı için tekrar sayısını kontrol et
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (array[j] == array[i])
                count++;
        }
        // Eğer mevcut sayının tekrar sayısı daha fazlaysa mode'u güncelle
        if (count > maxCount) {
            maxCount = count;
            mode = array[i];
        }
    }
    return mode;
}

// Aritmetik ortalamayı hesaplayan fonksiyon
void calculate_arithmetic_mean(int array[], int size, float *a_mean) {
    float sum = 0;
    // Tüm sayıları topla
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    // Toplamı eleman sayısına böl
    *a_mean = sum / size;
}

// Harmonik ortalamayı hesaplayan fonksiyon
void calculate_harmonic_mean(int array[], int size, float *h_mean) {
    float sum = 0;
    // Her sayının tersinin toplamını hesapla
    for (int i = 0; i < size; i++) {
        sum += 1.0 / array[i];
    }
    // Harmonik ortalama formülü: n / (1/x1 + 1/x2 + ... + 1/xn)
    *h_mean = size / sum;
}

// Diziyi ekrana yazdıran fonksiyon
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    // Tek boyutlu dizi örneği
    printf("***One-dimensional array***\n");
    int array1[] = {32, 32, 32, 32, 32, 34, 32, 26, 28, 28, 29, 31, 24, 27, 25, 27, 28, 30, 29, 29, 29, 31, 32, 31, 29, 31, 31, 31, 35, 33};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    
    printArray(array1, size1);
    
    int mode = find_mode(array1, size1);
    float arithmetic_mean, harmonic_mean;
    
    calculate_arithmetic_mean(array1, size1, &arithmetic_mean);
    calculate_harmonic_mean(array1, size1, &harmonic_mean);
    
    printf("The mode of array is %d\n", mode);
    printf("The arithmetic mean of array is %.6f\n", arithmetic_mean);
    printf("The harmonic mean of array is %.6f\n\n", harmonic_mean);
    
    // Çok boyutlu dizi örneği
    printf("***Multidimensional array***\n");
    int array2[][5] = {
        {4, 4, 82, 34, 56},
        {5, 34, 76, 90, 76},
        {2, 6, 1, 2, 45}
    };
    
    // İlk satır için hesaplamalar
    int row_size = 5;
    printArray(array2[0], row_size);
    
    mode = find_mode(array2[0], row_size);
    calculate_arithmetic_mean(array2[0], row_size, &arithmetic_mean);
    calculate_harmonic_mean(array2[0], row_size, &harmonic_mean);
    
    printf("The mode of the first row of the 2D array is %d\n", mode);
    printf("The arithmetic mean of the first row of the 2D array is %.6f\n", arithmetic_mean);
    printf("The harmonic mean of the first row of the 2D array is %.6f\n", harmonic_mean);
    
    return 0;
}
