#include<iostream>
using namespace std;

template <typename E>
void inssort(E A[], int n) {
	int i, j;
	E v;
    for (i = 1; i < n; i++) {
        v = A[i];
        j = i - 1;
        while ((j >= 0) && (A[j] > v)) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = v;
    }
}

int main() {
	int A[5] = {8, 31, 3, 49, 98};
	inssort(A, 5);
	
	for (int i = 0; i < 5; i++)
		cout << A[i] << " ";
	
	return 0;
}
