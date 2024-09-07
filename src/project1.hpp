#ifndef PROJECT1_HPP
#define PROJECT1_HPP

using namespace std;

struct MergeSort {
	MergeSort(vector<int>& IN) :
		n{ IN.size() },
		key_cmp{},
	   	key_cmp_insertionSort{},
	   	k{ 2 } {
		for (const auto& i : IN) {
			A.push_back(i);
			U.push_back(i);
		}			
	}
			
	void sort_default(int p, int r) {
		if ( p < r ) {
			int q  = (p+r) / 2;
			sort_default(p, q);
			sort_default(q+1, r);
			merge(p, q, r);
		}
	}	

	void sort_modified(int p, int r) {
		if (r <= k-1) { 
			insertionSort();
			return;
		}
		
		if (p < r) {
				int q  = (p+r) / 2;
				sort_modified(p, q);
				sort_modified(q+1, r);
				merge(p, q, r);
			}
	}

	void setK(short int k) { this->k = k; } 

	void insertionSort() {
		for (int i = 1; i < n; i++) {
			for (int j = i ; j > 0; j--) {
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
		while (idx_L < L.size() && idx_R < R.size() && idx_A < n) {
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
		
		if (idx_A < n) {
			if (idx_L < L.size()) {
				while (idx_L < L.size()) {
					A[idx_A] = L[idx_L];
					idx_L++;
					idx_A++;
				}	
			}
			else{
				while (idx_R < R.size()) {
					A[idx_A] = R[idx_R];
					idx_R++;
					idx_A++;
				}
			}
		}

	}

	void info() {
		cout << "Number of key comparisons made: " << key_cmp << endl;
		cout << "|--> Number of key comparisons made by insertion sort: " << key_cmp_insertionSort << endl;
	}

	unsigned long long getKeyCmp() { return key_cmp; }
	unsigned long getKeyCmp_insertionSort() { return key_cmp_insertionSort; }
	vector<int>& getArray() { return A; }
	void unsort() { key_cmp = 0; key_cmp_insertionSort = 0; A = U; }		

	private:
		vector<int> A, U;
		unsigned n;
		unsigned long long key_cmp;
		unsigned long key_cmp_insertionSort;
		short int k;
};

#endif // PROJECT1_HPP
