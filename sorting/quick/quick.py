#!/usr/bin/python
import random, time
from enum import Enum

class QuickSort:
    class PivotType(Enum):
        FIRST = 0,
        LAST = 1,
        RANDOM = 2,
        MEDIAN = 3

    def __init__(self, arr):
        self.arr = arr
        self.pivottype = self.PivotType.LAST

    def swap(self, arr, i, j):
        (arr[i], arr[j]) = (arr[j], arr[i])
        
    def run(self, low, high):
        print("QucikSort()")
        self.quicksort(arr, low, high)

    # This function takes last element as pivot, places 
    # the pivot element at its correct position in sorted
    # array, and places all smaller (smaller than pivot)
    # to left of pivot and all greater elements to right
    # of pivot
    def partition(self, arr, low, high):
        i = (low - 1)
        
        if self.PivotType.LAST == self.pivottype:
            pivot = arr[high]
        elif self.PivotType.FIRST == self.pivottype:
            pivot = arr[low]
        elif self.PivotType.MEDIAN == self.pivottype:
            pass
        else:
            pivot = random.randint(low, high)

        for j in range(low, high):
            if arr[j] < pivot:
                i+=1
                self.swap(arr, i, j)
        self.swap(arr, i + 1, high)
        return (i + 1)

    def quicksort(self, arr, low, high):
        if low < high:         
            pivot = self.partition(arr, low, high)
            self.quicksort(arr, low, pivot - 1)
            self.quicksort(arr, pivot + 1, high)

def rand_array(size):
    arr = []
    for i in range(size):
        arr.append(random.randint(0, size))
    return arr

if __name__ == "__main__":
    arr = rand_array(1000)
    print(arr)
    start = time.time()
    QuickSort(arr).run(0, len(arr) - 1)
    end = time.time()
    t = (end - start) * 1000
    print("%f ms" % t)