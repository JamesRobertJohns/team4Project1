#include <chrono>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <iterator>

#include "project1.hpp"
#include "myutils.hpp"

int main() {

	//
	// ==[ (c) i. We will fix the value of S (k) to 20 ]==
	//
	// output_1: k is set to 20
	// format:
	// total number of key cmp, key cmp by insertion sort, run time

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

	return 0;
}
