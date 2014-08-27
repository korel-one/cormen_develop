#pragma once


/* 1) BuildMaxHeap to build max heap on the input array A[1..n]
 * 2) Since the max elem of the array is stored at the root A[1]
 *    we can put it into its correct final position by exchanging it
 *    with A[n]
 * 3) To restore the max-heap property should call MaxHeapify(A, 1)
 *
 *
 *
 * runs in O(n*lg(n))
 * */

#include "Heap.h"

template <typename T, int N>
void heap_sort(T(&arr)[N])
{
	//1
	MaxHeap<T> heap = build_max_heap<MaxHeap<T>>(arr);

	//2
	for (int i = N; i < 1; --i) //downto 2
	{
		std::swap(a)
	}

}
