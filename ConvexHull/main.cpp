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

class Date{
public:
	Date(){}
	Date(const std::string& date_str){}

	const Date& operator=(const std::string& date_str)
	{
		return *this;
	}
};

Date TodaysDate()
{
	return Date();
}

//void foo()
//{
//	std::vector<Date> e;
//	std::copy(std::istream_iterator<Date>(std::cin)
//			, std::istream_iterator<Date>()
//			, std::back_inserter(e));
//
//	std::vector<Date>::iterator first = std::find(e.begin(), e.end(), "01/01/95");
//	std::vector<Date>::iterator last =  std::find(e.begin(), e.end(), "12/31/95");
//
//	*last = "12/20/98";//<-last could be end() iterator (possible incorrect assignment)
//
//	std::copy(first, last, std::ostream_iterator<Date>(std::cout, "\n"));//could be an incorrect range [end(), end());
//	e.insert(--e.end(), TodaysDate());//<-end iterator is changed here, can't change build-in temp variables
//
//	std::copy(first, last, std::ostream_iterator<Date>(std::cout, "\n"));
//
//}

class A
{
	static int count;

public:
	A()
	{
		std::cout<<"A()"<<std::endl;
		if(count ++ == 5)
			throw 1;
	}

	~A()
	{
		std::cout<<"~A()"<<std::endl;
	}
};

int A::count = 0;

int main() {

//	std::vector<signed char> v = {11, 22, 33, -1, 55};
//
//	const signed char* first = v.data();
//	const signed char* last = v.data() + v.size();
//
//	std::cout << std::find(first, last, 255) - first << std::endl;


//	signed char sc = -1;
//	int i = 255;
//
//	std::cout<<std::boolalpha << (sc == i)<< std::endl;
//
//	unsigned char x = 250;
//	unsigned char y = 200;
//
//	//result is 450 - not as unsigned char
//	std::cout<<x+y<<std::endl;
//
//	unsigned long a = 4000000000UL;
//	unsigned long b = 3000000000UL;
//
//	std::cout<<a+b<<std::endl;
//
//	signed char _sc = -1;
//	unsigned long ul = 0xFFFFFFFFUL;
//	std::cout<<std::boolalpha << (_sc == ul)<< std::endl;
//
//
//	try{
//		A* pa = new A[10];
//	}
//	catch(...)
//	{}

//	delete[] pa;

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
