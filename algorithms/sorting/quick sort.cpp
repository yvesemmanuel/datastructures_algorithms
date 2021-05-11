#include<iostream>
using namespace std;

template <typename E>
int hoare_partition(E A[], int l, int r) {
    int pivot = A[l];
    int i = l - 1, j = r + 1;
 
    while (true) {
        do {
            i++;
        } while (A[i] < pivot);
 
        do {
            j--;
        } while (A[j] > pivot);
 
        if (i >= j) return j;
 
        swap(A[i], A[j]);
    }
}
 
template <typename E>
void qsort(E A[], int l, int r) {
    if (l < r) {
        int pivot = hoare_partition(A, l, r);
        qsort(A, l, pivot);
        qsort(A, pivot + 1, r);
    }
}

int main() {
	int A[5] = {8, 31, 3, 49, 98};
	qsort(A, 0, 4);
	
	for (int i = 0; i < 5; i++)
		cout << A[i] << " ";
	
	return 0;
}
