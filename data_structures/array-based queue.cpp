#include <iostream>
using namespace std;

template <typename E> class AQueue {
private:
	int maxSize;
	int front;
	int rear;
	E *listArray;
public:
	AQueue(int size) {
		maxSize = size + 1;
		rear = 0; front = 1;
		listArray = new E[maxSize];
	}
	~AQueue() { delete [] listArray; }
	
	void clear() { rear = 0; front = 1; }
	
	void enqueue(E it) {
		if ((rear + 2) % maxSize != front) {
			rear = (rear + 1) % maxSize;
			listArray[rear] = it;
		}
		else cout << "Queue is full." << endl;
	}
	
	E dequeue() {
		if (lenght() != 0) {
			E it = listArray[front];
			front = (front + 1) % maxSize;
			return it;
		}
		else cout << "Queue is empty." << endl;
	}
	
	E frontValue() {
		if (lenght() != 0) return listArray[front];
		else cout << "Queue is empty." << endl;
	}
	
	int lenght() { return ((rear + maxSize) - front + 1) % maxSize; }
	
	void print() {
		for (int i = 1; i <= lenght(); i++) cout << listArray[i] << " ";
		cout << endl;
	}
};


int main() {
	AQueue<int> myQueue(2);
	myQueue.enqueue(3);
	myQueue.enqueue(4);
	myQueue.enqueue(5);
	myQueue.print();
	
	
	return 0;
}
