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

	cout << "test insertion_sort()" << endl;
	test.unsort();
	test.insertionSort(0, TEST.size()-1);
	printArray(test.getArray());
	test.info();
	cout << endl;

	cout << "test modified_sort()" << endl;
	test.unsort();
	test.setK(10);
	test.sort(0, TEST.size()-1);
	test.info();
	cout << endl;

	cout << "modified_sort(), k = 5" << endl;	
	test.unsort();
	test.setK(5);
	test.sort(0, TEST.size()-1);
	test.info();
	cout << endl;

	cout << "modified_sort(), k = 8" << endl;	
	test.unsort();
	test.setK(TEST.size());
	test.sort(0, TEST.size()-1);
	test.info();
	cout << endl;

	cout << "sort(), k = 10" << endl;
	test.unsort();
	test.setK(10);
	test.sort(0, TEST.size()-1);
	test.info();
	cout << endl;

	try {
		ifstream file;
		file.open("../data/input_1.txt");
		istream_iterator<int> start(file), end;
		vector<int> input(start, end);
		cout << "Read " << input.size() << " numbers" << endl;
		MergeSort* test_thousand = new MergeSort{ input };
		
		
		TEST_SORT(test_thousand, 0);
		TEST_SORT(test_thousand, input.size());
		TEST_SORT(test_thousand, 100);	

		for (int i = 1; i <= 500; i++) TEST_SORT(test_thousand, i);

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
	ms->sort(0, ms->getSize()-1); 
	ms->info();
	cout << endl;
}
