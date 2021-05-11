#include<iostream>
using namespace std;

template <typename E>
void inssort(E A[], int n) {
	for (int i = 1; i < n; i++)
		for (int j = i; (j > 0) && (A[j] < A[j - 1]); j--)
			swap(A[j], A[j - 1]);
}

int main() {
	int A[5] = {8, 31, 3, 49, 98};
	inssort(A, 5);
	
	for (int i = 0; i < 5; i++)
		cout << A[i] << " ";
	
	return 0;
}
