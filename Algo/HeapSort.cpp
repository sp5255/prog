#include<iostream>

class HeapSort {
private:
    int* arr, heap_size, size;
public:
    void getdata();
    int right(int i);
    int left(int i);
    void max_heapify(int i);
    void swap(int*, int*);
    void BuildHeap();
    void show(void);
    void heapSort();
};

void HeapSort::getdata() {
    std::cout << "Enter the number of elemnts you want to enter\n";
    int n;
    std::cin >> n;
    size = n;
    arr = new int[n];

    std::cout << "Enter the elements\n";
    
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    
    //size = sizeof(arr) / sizeof(int);

}
inline int HeapSort::right(int i) {
    return 2 * (i + 1);
}

inline int HeapSort::left(int i) {
    return 2 * i + 1;
}

inline void HeapSort::swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void HeapSort::max_heapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest;
    if (l < heap_size && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if (r < heap_size && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(largest);
    }
    return;
}

void HeapSort::BuildHeap() {
    heap_size = size;
    for (int i = (size / 2) - 1; i >= 0; i--)
        max_heapify(i);
}

void HeapSort::heapSort() {
    BuildHeap();
    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heap_size -= 1;
        max_heapify(0);
    }
}

void HeapSort::show(void) {
    std::cout << "Sorted" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << "\t";
    }
}

int main() {
    HeapSort h1;
    h1.getdata();
    //h1.BuildHeap();
    h1.heapSort();
    h1.show();

    return 0;
}