#include<iostream>
using namespace std;

template <typename E>
void bubsort(E A[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (A[j] < A[j - 1])
				swap(A[j], A[j - 1]);
}

int main() {
	int A[5] = {8, 31, 3, 49, 98};
	bubsort(A, 5);
	
	for (int i = 0; i < 5; i++)
		cout << A[i] << " ";
	
	return 0;
}
