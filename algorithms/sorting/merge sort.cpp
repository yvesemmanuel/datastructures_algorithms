#include<iostream>
using namespace std;

template <typename E>
void merge(E A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    E L[n1], R[n2];
 
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

template <typename E>
void mergesort(E A[], int left, int right){
    if(left < right){
	    int mid = left + (right - left) / 2;
	    mergesort(A, left, mid);
	    mergesort(A, mid + 1, right);
	    merge(A, left, mid, right);
	}
}


int main() {
	int A[5] = {8, 31, 3, 49, 98};
	mergesort(A, 0, 4);
	
	for (int i = 0; i < 5; i++)
		cout << A[i] << " ";
	
	return 0;
}
