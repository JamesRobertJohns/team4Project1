#include <chrono>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <iterator>

#include "project1.hpp"
#include "myutils.hpp"

void TEST_SORT(MergeSort*, long long);
void logger(string, string, short);

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
		int i = 1;
		string name = "../data/input_";
		while (i <= 5) { 
			string appendedName = name + to_string(i) + ".txt";
			cout << "logging " << appendedName << " now...\n";
			logger(appendedName, "../data/output_1.txt", 20);			
			i++;
		}
	} catch(std::exception& e) {
		cout << e.what() << endl;
		exit(1);
	}

	try {
		int i = 1;
		string iname = "../data/input_";
		string oname = "../data/ciii_";
		while (i <= 5) {  		
			int j = 1;	
			string appendedName = oname + to_string(i) + ".txt";	
			cout << "logging " << appendedName << " now...\n";			
			while (j <= 1000) {
				cout << "logging for k = " << to_string(j) << " now...\n";
				string finame = iname + to_string(i) + ".txt";
				string foname = oname + to_string(i) + ".txt";	
				logger(finame, foname, j);
				j++;
			}
		 i++;
		}
	} catch(std::exception& e) {
		cout << e.what() << endl;
		exit(1);
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
