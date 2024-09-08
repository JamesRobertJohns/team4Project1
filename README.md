# Investigating Integration of Merge Sort and Insertion Sort

Although merge sort runs in $\Theta(n\lg{n})$ in worst-case time and insertion sort runs $\Theta(n^2)$ worst-case time, the overhead in merge sort meant that there exists a small number of sublists $k$ in which insertion sort outperforms merge sort, such that

$c_1n^2 \leq c_2n\lg{n}$, where $c_1 < c_2$

This short project is to investigate and design a modified merge sort that makes use of the above property

## Input Data Generation

We set the largest integer value to be the largest signed integer, that is, $2^{31}-1$. The inputs are linebreak separated, with element sizes growing by a factor of 10 each iteration. The script `generateInput.py` is used to handle this. 
