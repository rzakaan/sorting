#!/usr/bin/python
import random, time

class MergeSort:
    def __init__(self, arr):
        self.arr = arr

    def swap(self, arr, i, j):
        (arr[i], arr[j]) = (arr[j], arr[i])
        
    def run(self):
        print("MergeSort()")
        self.mergesort(arr)

    def mergesort(self, arr):
        if len(arr) < 2:
            return
        
        # floor division //
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]

        self.mergesort(L)
        self.mergesort(R)

        lidx = ridx = mainIdx = 0

        while lidx < len(L) and ridx < len(R):
            if L[lidx] < R[ridx]:
                arr[mainIdx] = L[lidx]
                lidx += 1
            else:
                arr[mainIdx] = R[ridx]
                ridx += 1
            mainIdx += 1
        
        # check left
        while lidx < len(L):
            arr[mainIdx] = L[lidx]
            lidx += 1
            mainIdx += 1

        # check left
        while ridx < len(R):
            arr[mainIdx] = R[ridx]
            ridx += 1
            mainIdx += 1

def rand_array(size):
    arr = []
    for i in range(size):
        arr.append(random.randint(0, size))
    return arr

if __name__ == "__main__":
    arr = rand_array(10000)
    print(arr)
    start = time.time()
    MergeSort(arr).run()
    end = time.time()
    t = (end - start) * 1000
    print("%f ms" % t)