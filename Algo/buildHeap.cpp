#include<iostream>
inline int parent(int i) {
    return (i - 1) / 2;
}

inline int left(int i) {
    return 2*i + 1;
}

inline int right(int i) {
    return 2*i + 2;
}

inline void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int i, int size) {
    int l = left(i);
    int r = right(i);
    //int size = sizeof(arr) / sizeof(int);
    int largest;
    if (l < size && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, largest,size);
    }
    return;
}

int main() {    
    //int arr[] = { 16,10,8,14,7,9 };
    int arr[] = { 4,1,3,2,16,9,10,14,8,7 };         // example book pg,no. 158
    int size = sizeof(arr) / sizeof(int);
    //std::cout << size;

    for (int i = (size / 2) -1; i >= 0; i--) {
       heapify(arr, i,size);
    }

    std::cout << "sorted"<<std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;

    return 0;
}