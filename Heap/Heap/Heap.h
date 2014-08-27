#pragma once

#include <algorithm>
#include <functional>

template <typename T, typename HeapProperty>
class Heap
{
public:
	int parent(int i) const
	{
		return i/2;
	}

	int left(int i) const
	{
		return 2*i;
	}

	int right(int i) const
	{
		return 2*i + 1;
	}

	bool validate() const
	{
		HeapProperty func;

		bool respect_property = false;
		for(int i = 0; i != m_data.size(); ++i)
		{
			respect_property &= func(m_data.at(parent(i)), m_data.at(i));
		}

		return respect_property;
	}

	//maintain max/min heap property
	void max_heapify(int index) const
	{
		int l = left(index);
		int r = right(index);

		int largest = index;

		if(l < m_data.size() && m_data[l] > m_data[index])
			largest = l;

		if(r < m_data.size() && m_data[r] > largest)
			largest = r;

		if(largest != index)
		{
			std::swap(m_data.at(index), m_data(largest));
			max_heapify(largest);
		}
		else
			return;
	}

private:
	std::vector<T> m_data;
};

template <typename T>
class MinHeap
		: public Heap<T, std::less_equal<T>>
{};

template <typename T>
class MaxHeap
		: public Heap<T, std::greater_equal<T>>
{};

//works in O(N) - produces a max_heap from an unordered imput arr
template <typename T, int N>
MaxHeap<T> build_max_heap(T(&arr)[N])
{
	return MaxHeap<T>();
}

//runs in O(n*lg(n))
template <typename T, typename InputIterator>
void heap_sort()
{

}
