# Investigating Integration of Merge Sort and Insertion Sort

Although merge sort runs in $\Theta(n\lg{n})$ in worst-case time and insertion sort runs $\Theta(n^2)$ worst-case time, the overhead in merge sort meant that there exists a small number of sublists $k$ in which insertion sort outperforms merge sort, such that

$c_1n^2 \leq c_2n\lg{n}$, where $0 < c_1 < c_2$

This short project is to investigate and design a modified merge sort that makes use of the above property

## Input Data Generation

We set the largest integer value to be the largest signed integer, that is, $2^{31}-1$. The inputs are linebreak separated, with element sizes growing by a factor of 10 each iteration. The script `generateInput.py` is used to handle this. 

## Integration of Insertion Sort into Merge Sort

The implementation is simple, as we only need to set a boundary condition for insertion sort to be called within the recursive merge sort call. That is, we set the value $k$ to be bounding array size for the sublists to be sorted by insertion sort, and it is checked by a simple control flow.

```
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
```

The individual sorting algorithms are well studied and defined. Refer to the source code for the exact implementation details.

## Logging Results

The logging methods called are rather simple. We set a member `int` type to hold the key comparisons and defined a getter. The runtime are logged by calling `high_resolution_clock` in the `<chrono>` header

Note that the run time results are dependent on the hardware used and are influenced by many factors. Our OS used is `Windows 11 (Home) x86_64`, and CPU used is `Intel(R) Core(TM) i7-10750H (12) @ 2.59 GHz`
