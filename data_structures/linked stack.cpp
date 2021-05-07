#include<iostream>
using namespace std;

template <typename E> class Link {
public:
	E element;
	Link<E>* next;
	
	Link(E elemval, Link<E> *nextval = NULL) { element = elemval; next = nextval; }
	Link(Link<E> *nextval = NULL) { next = nextval; }
}; 


template <typename E> class LStack {
private:
	Link<E> *top;
	int size;
public:
	LStack() { top = NULL; size = 0; }
	~LStack() { clear(); }
	
	void clear() {
		while (top != NULL) {
			Link<E> *temp = top;
			top = top->next;
			delete temp;
		}
		size = 0;
	}
	
	void push(E it) {
		top = new Link<E>(it, top);
		size++;
	}
	
	E pop() {
		if (top != NULL) {
			E it = top->element;
			Link<E> *ltemp = top->next;
			delete top;
			top = ltemp;
			size--;
			
			return it;
		}
		else cout << "Stack is empty." << endl;
	}
	
	E topValue() {
		if (top != 0) return top->element;
		else cout << "Stack is empty." << endl;
	}
	
	void print() {
		Link<E> *temp = top;
		
		while (temp != NULL) {
			cout << temp->element << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	
	int length() { return size; }
};


int main() {
	LStack<int> myStack;
	
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);
	cout << myStack.topValue() << endl;
	myStack.print();
	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.topValue();
	
	return 0;
}
