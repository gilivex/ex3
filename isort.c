#include <stdio.h>

#define SIZE 50

void Shift_Elements(int *arr, int i) {
    size_t index;
    for (index = i; index > 0; index--){
        *(arr + (index + 1)) = *(arr + index); // arr[index+1] = arr[index]
    }
}

void Insertion_Sort(int *arr, int len) {
    int i, j, key;
    for (i = 1; i < len; i++) {
        key = *(arr + i);
        j = i - 1;

        while ((j + 1) && key < *(arr + j)) {
            j--;
        }
        Shift_Elements((arr + j), i - j - 1);
        *(arr + j + 1) = key;
    }
}

int main() {
    int arr[SIZE];
    int i, j;
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    Insertion_Sort(arr, SIZE);
    for (j = 0; j < SIZE; j++) {
        printf("%d,", arr[j]);
    }
}
