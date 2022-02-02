#include <iostream>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <array>

using namespace std;

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

void show_array(int* arr, int size) {
    std::cout << "ARR\n";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ", " ;
    }

    std::cout << std::endl;
}

int main() {
    std::array<int, 8> arr { -2, 99, 0, -743, INT_MAX, 2, INT_MIN, 4};
    show_array(arr.data(), 8);
    
    std::qsort(arr.data(), 
    arr.size(),
    sizeof(decltype(arr)::value_type),
    compare
    /* Alternative inline method
    [](const void* x, const void* y) {
        const int arg1 = *static_cast<const int*>(x);
        const int arg2 = *static_cast<const int*>(y);
        const auto cmp = arg1 <=> arg2;
        if (cmp < 0 ) return -1;
        if (cmp > 0) return 1;
        return 0;
    }
    */
    );

    show_array(arr.data(), 8);
}