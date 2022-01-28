import random, time

class SelectionSort:
    def __init__(self, arr):
        self.arr = arr
    
    def run(self):
        print("SelectionSort()")
        length = len(self.arr)
        for i in range(length - 1):
            minIdx = i
            for j in range(i + 1, length):
                if arr[j] < arr[minIdx]:
                    minIdx = j

            (arr[i], arr[minIdx]) = (arr[minIdx], arr[i])

def rand_array(size):
    arr = []
    for i in range(size):
        arr.append(random.randint(0, size))
    return arr

if __name__ == "__main__":
    arr = rand_array(1000)
    print(arr)
    start = time.time()
    SelectionSort(arr).run()
    end = time.time()
    t = (end - start) * 1000
    print(arr)
    print("%f ms" % t)