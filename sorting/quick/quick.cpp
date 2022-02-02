#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum PivotType {
    LAST
};

class QuickSort {
private:
    int swap_temp;
    int* arr;
    int size;
    PivotType pivotType;
    void swap(int arr[], int x, int y);
    int partition(int arr[], int low, int high);
    void quick(int arr[], int low, int high);
public:
    QuickSort(int* arr, int size);
    void sort(int low, int high);
    void sort();
};

QuickSort::QuickSort(int* arr, int size) {
    this->arr = arr;
    this->size = size;
    this->pivotType = PivotType::LAST;
}

void QuickSort::swap(int arr[], int x, int y) {
    swap_temp  = arr[x];
    arr[x] = arr[y];
    arr[y] = swap_temp;
}

void QuickSort::sort() {
    quick(arr, 0, size - 1);
}

void QuickSort::sort(int low, int high) {
    quick(arr, low, high);
}

void QuickSort::quick(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick(arr, low, pivot - 1);
        quick(arr, pivot + 1, high);
    }
}

int QuickSort::partition(int arr[], int low, int high) {
    int i = (low - 1);
    int pivot = 0;
    if (pivotType == PivotType::LAST) {
        pivot = arr[high];
    }

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

// Common Functions
enum VIEW {
    ONELINE,
    MULTILINE
};

void generate_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
}

void show_array(int* arr, int size) {
    std::cout << "ARR\n";
    VIEW present = VIEW::ONELINE;
    for (int i = 0; i < size; i++) {
        if (present == VIEW::ONELINE)
            std::cout << arr[i] << ", " ;
        else
            std::cout << "arr[" << i <<  "] = " << arr[i] << std::endl;
    }

    std::cout << std::endl;
}

#define ARR_SIZE 100
int main() {
    srand( (unsigned)time(NULL) );
    
    // array init
    int arr[ARR_SIZE];
    generate_array(arr, ARR_SIZE);
    show_array(arr, ARR_SIZE);

    QuickSort quick(arr, ARR_SIZE);
    quick.sort();

    show_array(arr, ARR_SIZE);
}


