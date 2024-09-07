#include<iostream>
#include<vector>

using namespace std;

#include "helperFunc.h"

int main() {
	vector<int> TEST = { 14, 40, 31, 28, 3, 15, 17, 51 };

	MergeSort test{ TEST };
	cout << "unsorted test array: " << endl;
	printArray(TEST);
	cout << "number of key comparisons: " << test.getKeyCmp() << endl;
	cout << endl;

	test.sort_default(TEST, 0, TEST.size()-1);
	cout << "sorted test array: " << endl;
	printArray(TEST);
	cout << "number of key comparisons: " << test.getKeyCmp() << endl;
	
	return 0;
}
