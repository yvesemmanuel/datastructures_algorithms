#include <stdio.h>

class AList {
	int maxSize, listSize, curr;
	int *listArray;
public:
	AList(int size) {
		maxSize = size;
		listSize = curr = 0;
		listArray = new int[maxSize];
	}
	
	~AList() { delete [] listArray; }
	
	void clear() {
		delete [] listArray;
		listSize = curr = 0;
		listArray = new int[maxSize];
	}
	
	void insert(int it) {
		if (listSize < maxSize) {
			for (int i = listSize; i > curr; i--)
				listArray[i] = listArray[i - 1];
			listArray[curr] = it;
			listSize++;
		}
		else printf("List capacity exceeded.\n");
	}

	void append(int it) {
		if (listSize < maxSize) {
			listArray[listSize++] = it;
		}
		else printf("List capacity exceeded.\n");
	}
	
	int remove() {
		if ((curr >= 0) && (curr < listSize)) {
			int it = listArray[curr];
			for (int i = curr; i < listSize - 1; i++)
				listArray[i] = listArray[i + 1];
			listSize--;
			return it;
		}
		else printf("No element.\n");
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
		else printf("Pos out of range.\n");		
	}
	
	int getValue() {
		if ((curr >= 0) && (curr < listSize))
			return listArray[curr];
		else printf("No current element.");
	}
	
	void print() {
		for (int i = 0; i < listSize; i++)
			printf("%d ", listArray[i]);
		printf("\n");
	}
};

int main() {
	AList myList(2);
	
	myList.insert(2);
	myList.insert(3);
	myList.insert(3);
	myList.remove();
	myList.insert(4);
	myList.insert(3);
	
	myList.print();
	
	return 0;
}
