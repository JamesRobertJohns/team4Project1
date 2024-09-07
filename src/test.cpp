#include<iostream>
#include<vector>

using namespace std;

#include "project1.h"
#include "myutils.h"

int main() {
	vector<int> TEST = { 14, 40, 31, 28, 3, 15, 17, 51 };

	MergeSort test{ TEST };
	cout << "unsorted test array: " << endl;
	printArray(test.getArray());
	cout << "number of key comparisons: " << test.getKeyCmp() << endl;
	cout << endl;

	test.sort_default(0, TEST.size()-1);
	cout << "sorted test array: " << endl;
	printArray(test.getArray());
	cout << "number of key comparisons: " << test.getKeyCmp() << endl;
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
	test.insertionSort();
	printArray(test.getArray());
	cout << "number of key comparisons: " << test.getKeyCmp_insertionSort() << endl;
	cout << endl;

	cout << "test modified_sort(), k is default" << endl;
	test.unsort();
	test.sort_modified(0, TEST.size()-1);
	printArray(test.getArray());
	cout << "number of key comparisons: " << test.getKeyCmp() << endl;
	cout << endl;
	
	cout << "modified_sort(), k = 8" << endl;	
	test.unsort();
	test.setK(TEST.size());
	test.sort_modified(0, TEST.size()-1);
	test.info();
	cout << endl;

	cout << "sort_modified(), k = 10" << endl;
	test.unsort();
	test.setK(10);
	test.sort_modified(0, TEST.size()-1);
	test.info();
	cout << endl;

	return 0;
}
