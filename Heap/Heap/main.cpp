//============================================================================
// Name        : preparation.cpp
// Author      : s.shynkaruk
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include <ios>

#include "ConvexHull.h"
#include "Heap.h"

int main() {
	PointI arr[] = { PointI(13, 6)
			, PointI(7, 5)
			, PointI(11, 6)
			, PointI(16, 9)
			, PointI(8, 15)
			, PointI(14, 13)
			, PointI(16, 11)
			, PointI(13, 10)
			, PointI(9, 11)
			, PointI(4, 12)
			, PointI(6, 7)
			, PointI(2, 8)};

	get_convex_hull(arr);

	//build max_heap data
	int _arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	MaxHeap<int> res = build_max_heap<MaxHeap<int>>(_arr);
	res.print();

	int _expected_heap[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

	bool are_equal = res.equal_to(MaxHeap<int>(_expected_heap));

	return 0;
}
