#include <iostream>
using namespace std;

template <typename E> class AList {
private:
	int maxSize, listSize, curr;
	E *listArray;
public:
	AList(int size) {
		maxSize = size;
		listSize = curr = 0;
		listArray = new E[maxSize];
	}
	
	~AList() { delete [] listArray; }
	
	void clear() {
		delete [] listArray;
		listSize = curr = 0;
		listArray = new E[maxSize];
	}
	
	void insert(E it) {
		if (listSize < maxSize) {
			for (int i = listSize; i > curr; i--)
				listArray[i] = listArray[i - 1];
			listArray[curr] = it;
			listSize++;
		}
		else cout << "List capacity exceeded." << endl;
	}

	void append(E it) {
		if (listSize < maxSize) {
			listArray[listSize++] = it;
		}
		else cout << "List capacity exceeded." << endl;
	}
	
	E remove() {
		if ((curr >= 0) && (curr < listSize)) {
			E it = listArray[curr];
			for (int i = curr; i < listSize - 1; i++)
				listArray[i] = listArray[i + 1];
			listSize--;
			return it;
		}
		else cout << "No element." << endl;
	}
	
	void moveToStart() { curr = 0; }
	void moveToEnd() { curr = listSize; }
	void prev() { if (curr != 0) curr--; }
	void next() { if (curr < listSize) curr++; }
	
	int length() { return listSize; }
	int currPost() { return curr; }
	
	void moveToPos(int pos) {
		if ((pos >= 0) && (pos <= listSize))
			curr = pos;
		else cout << "Pos out of range." << endl;
	}
	
	E getValue() {
		if ((curr >= 0) && (curr < listSize))
			return listArray[curr];
		else cout << "No current element." << endl;
	}
	
	void print() {
		for (int i = 0; i < listSize; i++)
			cout << listArray[i] << " ";
		cout << endl;
	}
};

int main() {
	AList<int> myList(2);
	
	myList.insert(2);
	myList.insert(3);
	myList.insert(3);
	myList.remove();
	myList.insert(4);
	myList.insert(3);
	
	myList.print();
	
	return 0;
}
