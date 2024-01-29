Algorithm: QuickSort

Input: Array A[], leftmost index low, rightmost index high

Procedure:
1. If low < high, then
   a. Select a pivot element from the array, typically A[high].
   b. Partition the array into two sub-arrays:
      - Elements smaller than the pivot on the left side.
      - Elements greater than the pivot on the right side.
   c. Recursively apply QuickSort on the left and right sub-arrays.

QuickSort(A[], low, high)
1. if low < high
    a. partitionIndex = Partition(A, low, high)
    b. Recursively call QuickSort on the left sub-array: QuickSort(A, low, partitionIndex - 1)
    c. Recursively call QuickSort on the right sub-array: QuickSort(A, partitionIndex + 1, high)

Partition(A[], low, high)
1. pivot = A[high]
2. i = low - 1
3. for j from low to high - 1
    a. if A[j] <= pivot
        i++
        swap A[i] and A[j]
4. swap A[i + 1] and A[high] // place the pivot in its correct position
5. return i + 1 // index of the pivot in the sorted array
