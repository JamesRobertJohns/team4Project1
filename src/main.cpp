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
	// size of input array,
	// value of k chosen,
	// total number of key cmp, 
	// key cmp by insertion sort, 
	// run time

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


	// c iii)
	// in order to find optimal value, we iterate over k = 1 to k = 1000
	// for every input set. by doing this, we also do c ii) implicitly
	// this is because the solution can also be found in c ii)
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
				string foname = oname + to_string(i) + ".csv";	
				logger(finame, foname, j);
				j++;
			}
		 i++;
		}
	} catch(std::exception& e) {
		cout << e.what() << endl;
		exit(1);
	} 


	return 0;
}
