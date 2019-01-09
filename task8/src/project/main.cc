#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <cassert>
#include "parallel_sort.hh"

using namespace std;

int main()
{
	cout << "sequential      parallel      standart sort" << endl;
	for (unsigned length = 10; length < 100000000; length *= 10)
	{
		vector<int> seq(length);
		generate(seq.begin(), seq.end(), []() {return rand(); });

		vector<int> parallel = seq;
		vector<int> stdseq = seq;

		using chrono::system_clock;

		typedef chrono::duration<int, milli> milli;
		auto start_solo = system_clock::now();
		my::mergeSortSeq(seq.begin(), seq.end());
		auto end_solo = system_clock::now();

		auto start_parallel = system_clock::now();
		my::mergeSort(parallel.begin(), parallel.end());
		auto end_parallel = system_clock::now();

		auto start_stdseq = system_clock::now();
		my::mergeSort(stdseq.begin(), stdseq.end());
		auto end_stdseq = system_clock::now();

		cout << setw(10) << chrono::duration_cast<milli>(end_solo - start_solo).count()
			<< "    " << setw(10) <<
			chrono::duration_cast<milli>(end_parallel - start_parallel).count() <<
			"      " << setw(10) << chrono::duration_cast<milli>(end_stdseq - start_stdseq).count()
			<< endl;

		assert(seq == parallel);
	}
	return 0;
}

