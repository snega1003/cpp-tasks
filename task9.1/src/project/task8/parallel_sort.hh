#ifndef PARALLEL_SORT
#define PARALLEL_SORT
#include <thread>
#include <vector>

namespace my
{

	template <class Iterator>
	void merge(Iterator start, Iterator midl, Iterator end) {
		typedef typename std::iterator_traits<Iterator>::value_type T;
		std::vector<T> res;
		Iterator it1 = start;
		Iterator it2 = midl;
		while (it1 < midl && it2 < end) {
			if (*it1 < *it2) {
				res.push_back(*it1);
				it1++;
			}
			else {
				res.push_back(*it2);
				it2++;
			}
		}
		while (it1 < midl) {
			res.push_back(*it1);
			it1++;
		}
		while (it2 < end) {
			res.push_back(*it2);
			it2++;
		}
		std::copy(res.begin(), res.end(), start);
	}

	template <class Iterator>
	void mergeSortRecursive(Iterator start, Iterator end, int num) {
		if (start + 1 >= end) return;

		size_t size = end - start;
		Iterator middle = start + size / 2;
		if (num > 1){
			std::thread th1(mergeSortRecursive<Iterator>, start, middle, num - 2);
			mergeSortRecursive<Iterator>(middle, end, num - 2);
			th1.join();
		}
		else {
			mergeSortRecursive(start, middle, 0);
			mergeSortRecursive(middle, end, 0);
		}
		merge(start, middle, end);
	}
	template <class Iterator>
	void mergeSort(Iterator start, Iterator end)
	{
		mergeSortRecursive(start, end, std::thread::hardware_concurrency());
	}
	template <class Iterator>
	void mergeSortSeq(Iterator start, Iterator end)
	{
		mergeSortRecursive(start, end, 1);
	}
};

#endif
