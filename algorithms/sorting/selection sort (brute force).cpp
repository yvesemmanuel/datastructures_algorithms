#include<iostream>
using namespace std;

template <typename E>
void selsort(E A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int lowindex = i;
		for (int j = n - 1; j > i; j--)
			if (A[j] < A[lowindex])
				lowindex = j;
		swap(A[i], A[lowindex]);
	}
}

int main() {
	int A[5] = {8, 31, 3, 49, 98};
	selsort(A, 5);
	
	for (int i = 0; i < 5; i++)
		cout << A[i] << " ";
	
	return 0;
}
