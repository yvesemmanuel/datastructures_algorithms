#include <iostream>
using namespace std;

int coinrow(int C[], int n) {
	int memo[n + 1], i;
	memo[0] = 0; memo[1] = C[0];
	
	for (i = 2; i < n + 1; i++)
		memo[i] = max(C[i] + memo[i - 2], memo[i - 1]);
	
	return memo[n];
}


int main() {
	int arr[] = {5, 1, 2, 10, 6, 2};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	cout << coinrow(arr, size);
	
	return 0;
}
