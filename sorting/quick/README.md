# Quick Sort

## Introduction
Quicksort is an **in-place** sorting algorithm. When implemented well, it can be somewhat faster than merge sort and about two or three times faster than heapsort.

> An in-place sorting algorithm uses constant space for producing the output (modifies the given array only). It sorts the list only by modifying the order of the elements within the list.

## How it works
It works by selecting a middle point (**pivot**) element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the middle point. 

The sub-arrays are then sorted recursively. This can be done in-place, requiring small additional amounts of memory to perform the sorting. 

> In addition, this selected middle point is also called a pivot, 
because all other numbers will be sorted on the axis of this number.

## Algorithm
- It is a type of **Divide and Conquer** algorithm
- Stability No
- Method Segmentation

There are many different versions of quickSort that pick pivot in different ways. 
1. Always pick first element as pivot
2. Always pick last element as pivot
3. Pick a random element as pivot
4. Pick median as pivot

## Complexity
Lean applications use as much space as O(n)

If a pivot is used in the middle, it can be O(n log n) in the worst case

|Type|Big(O)
|:-|:-
|Worst   | O(n2)
|Average | O(n log n)
|Memory  | O(log n)

## Advantages
- It sorts in-place, no additional storage is required as well, it uses only a small auxiliary stack.
- It requires only n (log n) time to sort n items
- It has an extremely short inner loop.

## Disadvantages
- It is recursive. Especially, if recursion is not available, the implementation is extremely complicated.
- It requires quadratic (i.e., n2) time in the worst-case.
- It is worst-case performance is similar to average performances of the bubble, insertion or selections sorts

## Where is it used
- It is used everywhere where a stable sort is not needed
- The sorting algorithm is used for information searching and as Quicksort is the fastest algorithm so it is widely used as a better way of searching
- It is an in-place sort that does not require any extra storage memory
- Quicksort is a cache-friendly algorithm as it has a good locality of reference when used for arrays