struct MergeSort {
	MergeSort(vector<int>& IN) :
		n{ IN.size() },
		key_cmp{} {
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

	void sort_modified() {
		 // TODO 
	}

	void insertion_sort() {
		// TODO
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

	unsigned long long getKeyCmp() {
		return key_cmp;
	}

	vector<int>& getArray() {
		return A;
	}

	void unsort() {
		key_cmp = 0;
		A = U;	
	}		

	private:
		vector<int> A, U;
		unsigned n;
		unsigned long long key_cmp;
};


void printArray(vector<int>& A) {
	for (const auto& i : A)
		cout << i << ' ';
	cout << endl;
}
