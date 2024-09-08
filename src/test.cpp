#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

#include "project1.hpp"
#include "myutils.hpp"

void TEST_SORT(MergeSort*, long long);

int main() {
	vector<int> TEST = { 14, 40, 31, 28, 3, 15, 17, 51 };

	MergeSort test{ TEST };
	cout << "unsorted test array: " << endl;
	printArray(test.getArray());
	cout << "number of key comparisons: " << test.getKeyCmp() << endl;
	cout << endl;

	test.setK(0);
	test.sort(0, TEST.size()-1);
	cout << "sorted test array: " << endl;
	printArray(test.getArray());
	test.info();
	cout << endl;

	cout << "the orginal array should be unmodified: " << endl;
	printArray(TEST);
	cout << endl;

	cout << "test unsort()" << endl;
	test.unsort();
	printArray(test.getArray());
	cout << "number of key comparisons: " << test.getKeyCmp() << endl;
	cout << endl;

	TEST_SORT(&test, TEST.size()-1);
	TEST_SORT(&test, 10);
	TEST_SORT(&test, 5);
	TEST_SORT(&test, 8);
	TEST_SORT(&test, 10);

	try {
		ifstream file;
		file.open("../data/input_1.txt");
		istream_iterator<int> start(file), end;
		vector<int> input(start, end);
		cout << "Read " << input.size() << " numbers" << endl;
		MergeSort* test_thousand = new MergeSort{ input };
		for (int i = 0; i <= 1000; i++) TEST_SORT(test_thousand, i);
		delete test_thousand;
		file.close();
	} catch(bad_alloc& e) {
		cout << e.what() << endl;
		exit(1);
	}

	return 0;
}


void TEST_SORT(MergeSort* ms, long long k) {
	ms->unsort();
	ms->setK(k);
	const auto t1 = chrono::high_resolution_clock::now();
	ms->sort(0, ms->getSize()-1); 
	const auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double, std::milli> ms_double = t2 - t1;
	ms->info();
	cout << "time taken: " << ms_double.count() << "ms\n";
	cout << endl;
}
