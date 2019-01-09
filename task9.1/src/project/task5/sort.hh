#ifndef SORT_MERGE
#define SORT_MERGE

#include <vector>

template <class Iterator>
void merge(Iterator start, Iterator mid, Iterator end) {
    typedef typename std::iterator_traits<Iterator>::value_type T;
    std::vector<T> result;
    Iterator it1 = start;
    Iterator it2 = mid;
    while (it1 < mid && it2 < end) {
        if (*it1 < *it2) {
            result.push_back(*it1);
            it1++;
        } 
		else {
            result.push_back(*it2);
            it2++;
        }
    }
    while (it1 < mid) {
        result.push_back(*it1);
        it1++;
    }
    while (it2 < end) {
        result.push_back(*it2);
        it2++;
    }
    std::copy(result.begin(), result.end(), start);
}

template <class Iterator>
void mergeSortRecursive(Iterator start, Iterator end) {
    if (start + 1 >= end) return;
    size_t size = end - start;
    Iterator middle = start + size/2;
    mergeSortRecursive(start, middle);
    mergeSortRecursive(middle, end);
    merge(start, middle, end);
}

#endif 
