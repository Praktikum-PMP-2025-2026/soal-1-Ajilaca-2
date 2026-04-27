/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3 
 *   Hari dan Tanggal    : 27 April 2026
 *   Nama (NIM)          : M Faza Dzil Ikram (13224017)
 *   Nama File           : soal3.c
 *   Deskripsi           : Program mebaca input sebnayak n dan realloc array dinamis, lalu mengurutkan dan menghitung median. berdasarkan banyak input ganjil atau genap.
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { // fungsi untuk mengurutkan angka
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
} 

int main(void) { 
    int *data = NULL; // pointer untuk array 
    int capacity = 0;
    int count = 0;
    int value;

    while (scanf("%d", &value) == 1 && value != -1) { // membaca input samapai pengguna memasukkan input -1 yang menandakan akhir input
        if (count >= capacity) {
            int new_capacity = (capacity == 0) ? 4 : capacity * 2; // jika statement capacity nya true maka capasitas di set menjadi 4 dan jika false dikalikan 2 
            int *new_data = realloc(data, new_capacity * sizeof(int));
            if (new_data == NULL) {
                free(data); // menghapus data jika realloc nya ggal
                return 1;
            }
            data = new_data;
            capacity = new_capacity; 
        }
        data[count++] = value;
    }

    if (count <= 0) {
        free(data);
        return 0;
    }

    qsort(data, count, sizeof(int), compare);

    printf("COUNT %d", count);
    printf(" SORTED");
    for (int i = 0; i < count; i++) {
        printf(" %d",  data[i]);
        
    }
    printf(" "); // menyesuaikan dengan expected ouput
    if (count % 2 == 1) { // ganjil
        int middle = data[count / 2];
        printf("MEDIAN %d", middle);
    } else {
        int left = data[count / 2 - 1];
        int right = data[count / 2];
        int sum = left + right;
        if (sum % 2 == 0) { // genap
            printf("MEDIAN %d.00", sum / 2);
        } else {
            printf("MEDIAN %d.50", sum / 2);
        }
    }

    free(data);
    return 0;
}
