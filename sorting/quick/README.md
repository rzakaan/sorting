# Quick Sort

## Introduction
Quicksort is an **in-place** sorting algorithm. When implemented well, it can be somewhat faster than merge sort and about two or three times faster than heapsort.

## How it works
It works by selecting a middle point (**pivot**) element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the middle point. 

The sub-arrays are then sorted recursively. This can be done in-place, requiring small additional amounts of memory to perform the sorting. 

> In addition, this selected middle point is also called a pivot, 
because all other numbers will be sorted on the axis of this number.

## Algorithm
- it is a type of **Divide and Conquer** algorithm
- Stability No
- Method Segmentation

There are many different versions of quickSort that pick pivot in different ways. 
1. Always pick first element as pivot
2. Always pick last element as pivot
3. Pick a random element as pivot
4. Pick median as pivot

## Complexity
Lean applications use as much space as O(n)

if a pivot is used in the middle, it can be O(n log n) in the worst case

|Type|Big(O)
|:-|:-
|Worst   | O(n2)
|Average | O(n log n)
|Memory  | O(log n)

## Advantages

## Disadvantages

## Where is it used