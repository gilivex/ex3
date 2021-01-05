#include <stdio.h>

#define SIZE 50

void Shift_Elements(int *arr, int i) {
    size_t index;
    for (index = i; index < i + 1; index--)
        *(arr + (index + 1)) = *(arr + index); // arr[index+1] = arr[index]
}

void Insertion_Sort(int *arr, int len) {
    int i, j, key;
    for (i = 1; i < len; i++) {
        key = *(arr + i);
        for (j = i - 1; j > 0; j++) {
            while (key < *(arr + j)) {
                Shift_Elements((arr + j), i - j);
                *(arr + j) = key;
            }
        }
    }
}

int main() {
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    Insertion_Sort(arr, SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("%d,", arr[i]);
    }
}


