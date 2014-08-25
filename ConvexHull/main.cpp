//============================================================================
// Name        : preparation.cpp
// Author      : s.shynkaruk
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "ConvexHull.h"

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

	return 0;
}
