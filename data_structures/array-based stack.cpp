#include<iostream>
using namespace std;

template <typename E> class AStack {
private:
	int maxSize;
	int top;
	E *listArray;
public:
	AStack(int size) { maxSize = size; top = 0; listArray = new E[size]; }
	~AStack() { delete [] listArray; }
	
	void clear() { top = 0; }
	void push(E it) {
		if (top != maxSize)
			listArray[top++] = it;
		else cout << "Stack is full." << endl;
	}
	
	E pop() {
		if (top != 0) return listArray[--top];
		else cout << "Stack is empty." << endl;
	}
	
	E topValue() {
		if (top != 0) return listArray[top - 1];
		else cout << "Stack is empty." << endl;
	}
	
	void print() {
		for (int i = 0; i < top; i++)
			cout << listArray[i] << " ";
		cout << endl;
	}
	
	bool check(int it) {
		for (int i = 0; i < top; i++)
			if (listArray[i] == it) return true;
		
		return false;
	}
};

int main() {
	AStack<int> myStack(2);
	
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);
	myStack.print();
	cout << myStack.topValue() << endl;
	cout << myStack.check(8);
	
	return 0;
}
