#pragma once

//max-priority queue: based on max heaps

template <typename T>
class PriorityQueue
{
public:
	void insert(const T& element);

	//returns the element with the largest key
	const T& max() const;

	//removes and returns the element with the largest key
	T extract_max();

	//increases the value of element's key to the new value,
	//which is assumed to be at least as large as element's current key value
	void increase_key(const T& element, const T& new_val);//max priority queue

	//increases the value of element's key to the new value,
	//which is assumed to be at least as large as element's current key value
	//void decrease_key(const T& element, const T& new_val); - min priority queue
};


//min priority queue

