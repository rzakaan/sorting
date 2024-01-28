#include <cstdlib> 
#include <iostream>
#include <vector>
#include <chrono>
#include <functional>

#if __APPLE__
#include <thread>
#elif __LINUX__
#include <pthread>
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#ifdef _WIN64
// x86_64
#else
// x86
#endif
#endif

/*
 * Merge Sorting
 *
 * It requires extra space to store the sorted subarrays.
 *
 * Best  Case : O(n log n)
 * Worst Case : O(n log n)
*/

using namespace std;

class Settings
{
public:
    int max_thread;
    int current_thread;
    int array_size;
};

Settings set;
#define SIZE 1000000

// ---------------------------------------------------------------------------------------------------- //

void display(const int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ---------------------------------------------------------------------------------------------------- //

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;

    // size of subarrays
    int lsize = mid - left + 1;
    int rsize = right - mid;
    int* L = new int[lsize];
    int* R = new int[rsize];

    // fill subarrays
    for (i = 0; i < lsize; i++) {
        L[i] = arr[left + i];
    }

    for (i = 0; i < rsize; i++) {
        R[i] = arr[mid + 1 + i];
    }

    // sort
    // k initalize with left index
    i = 0, j = 0, k = left;
    while (i < lsize && j < rsize) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    // sort extra elements
    while (i < lsize) {
        arr[k++] = L[i++];
    }

    while (j < rsize) {
        arr[k++] = R[j++];
    }
}

/**
 * @brief Merge Sort
 *
 * @param arr
 * @param l left / begin index
 * @param r right / end index
 */
void merge_sort(int arr[], int left, int right) {
    if (left >= right) return;

    // calculate mid and left shifting
    int m = left + (right - left) / 2;

    merge_sort(arr, left, m);
    merge_sort(arr, m + 1, right);
    merge(arr, left, m, right);
}

void merge_sort(int arr[], int size) {
    merge_sort(arr, 0, size - 1);
}

void merge_sort(vector<int> vec) {
    merge_sort(vec.data(), vec.size() - 1);
}

// ---------------------------------------------------------------------------------------------------- //

void merge_sort_parallel(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    if (set.current_thread < set.max_thread) {
        set.current_thread += 2;
        std::thread lthread(merge_sort_parallel, arr, left, mid);
        std::thread rthread(merge_sort_parallel, arr, mid + 1, right);
        lthread.join();
        rthread.join();
    }
    else {
        merge_sort_parallel(arr, left, mid);
        merge_sort_parallel(arr, mid + 1, right);
    }

    merge(arr, left, mid, right);
}

// ---------------------------------------------------------------------------------------------------- //

void rand_vector(vector<int>& vec, const int size) {
    srand(time(NULL));

    for (size_t i = 0; i < size; i++) {
        vec.push_back(rand() % size);
    }
}

int* rand_array(int size) {
    srand(time(NULL));
    int* arr = new int[size];
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }
    return arr;
}

void test_01() {
    int* arr = rand_array(SIZE);

    auto start = std::chrono::high_resolution_clock::now();
    merge_sort(arr, SIZE);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout.precision(6);
    cout << "microsecond: " << duration.count() << endl;
}

void test_02() {
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    int* arr = rand_array(SIZE);
    clock_t start, stop;

    start = clock();
    merge_sort(arr, SIZE);
    stop = clock();

    double execution = double(stop - start) / double(CLOCKS_PER_SEC);
    cout.precision(6);
    cout << "merge sort single thread execution time : " << fixed << execution << " sec" << endl;
}

void test_03() {
    // unsync the I/O of C and C++. 
    ios_base::sync_with_stdio(false);

    clock_t start, stop;
    int* arr = rand_array(SIZE);

    start = clock();
    merge_sort_parallel(arr, 0, SIZE - 1);
    stop = clock();

    double execution = double(stop - start) / double(CLOCKS_PER_SEC);
    cout.precision(6);
    cout << "merge sort parallel execution time \t: " << fixed << execution << " sec" << endl;
}

// ---------------------------------------------------------------------------------------------------- //


void print_debug() {
    cout << "thread count : " << set.max_thread << endl;
    cout << "array size   : " << set.array_size << endl;
}

int main(int argc, char* argv[]) {
    set.array_size = SIZE;
    set.current_thread = 0;
    set.max_thread = std::thread::hardware_concurrency();

    print_debug();

    test_02();
    test_03();

    return 0;
}
