#ifndef PROJECT1_HPP
#define PROJECT1_HPP

using namespace std;

struct MergeSort {
	MergeSort(vector<int>& IN) :
		n{ IN.size() },
		key_cmp{},
	   	key_cmp_insertionSort{},
	   	k{ 20 } {
		for (const auto& i : IN) {
			A.push_back(i);
			U.push_back(i);
		}			
	}
			
	void sort(int p, int r) {
		if (r - p + 1 <= k) { 
			insertionSort(p, r);
			return;
		}
		
		if (p < r) {
				int q  = (p+r) / 2;
				sort(p, q);
				sort(q+1, r);
				merge(p, q, r);
			}
	}

	void insertionSort(int p, int r) {
		for (int i = p+1; i <= r; i++) {
			for (int j = i ; j > p; j--) {
				key_cmp_insertionSort++;
				key_cmp++;
				if (A[j] < A[j-1]) {
					int t = A[j];
					A[j] = A[j-1];
					A[j-1] = t;
				}
				else break;
			}
		}
	}

	void merge(int p, int q, int r) {
		vector<int> L, R;
		for (int i = p; i <= q; i++) L.push_back(A[i]);
		for (int i = q+1; i <= r; i++) R.push_back(A[i]);
		
		int idx_L{}, idx_R{}, idx_A{ p };
		while (idx_L < L.size() && idx_R < R.size()) {
			if (L[idx_L] < R[idx_R]) {
				A[idx_A] = L[idx_L];
				idx_L++;		
			}
			else {
				A[idx_A] = R[idx_R];
				idx_R++;
			}	
			idx_A++;
			key_cmp++;
		}	
		
		while (idx_L < L.size()) {
			A[idx_A] = L[idx_L];
			idx_L++;
			idx_A++;
		}
				
		while (idx_R < R.size()) {
			A[idx_A] = R[idx_R];
			idx_R++;
			idx_A++;
		}
	}

	void info() {
		cout << "k chosen: " << k << endl;
		cout << "Number of key comparisons made: " << key_cmp << endl;
		cout << "|--> Number of key comparisons made by insertion sort: " << key_cmp_insertionSort << endl;
	}
	
	void setK(short int k) { this->k = k; } 
	const auto getKeyCmp() const { return key_cmp; }
	const auto getKeyCmp_insertionSort() const { return key_cmp_insertionSort; }
	vector<int>& getArray() { return A; }
	const auto getSize() const { return U.size(); }	
	void unsort() { key_cmp = 0; key_cmp_insertionSort = 0; A = U; }		

	private:
		vector<int> A, U;
		unsigned n;
		unsigned long long key_cmp;
		unsigned long key_cmp_insertionSort;
		short int k;
};

void logger(string path_input, string path_output, short k) {
	ifstream input; 
	ofstream output;
	input.open(path_input);
	output.open(path_output, ios::app);

	if (!input || !output) {throw std::runtime_error{"[-] In logger(): Error in opening files"}; }

	istream_iterator<int> start(input), end;
	vector<int> data(start, end);
	MergeSort* ms = new MergeSort{ data };	
	if (k < 0) {
	   	if (k == -1) ms->setK(data.size());
		else throw std::runtime_error{"[-] In logger(): Invalid assignment of k"};	
	} 
	else ms->setK(k);
	
	const auto t1 = chrono::high_resolution_clock::now();
	ms->sort(0, ms->getSize()-1);
	const auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double, std::milli> ms_double = t2 - t1;

	output 	<< ms->getKeyCmp() << ", " 
			<< ms->getKeyCmp_insertionSort() << ", " 
			<< ms_double.count() << "\n";	

	input.close();
	output.close();
	delete ms;
}

#endif // PROJECT1_HPP
