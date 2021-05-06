#include<iostream>
using namespace std;
 
template <typename E> class Link {
public:
	E element;
	Link<E>* next;
	
	Link(E elemval, Link<E> *nextval = NULL) { element = elemval; next = nextval; }
	Link(Link<E> *nextval = NULL) { next = nextval; }
};

template <typename E> class LList {
private:
	Link<E> *head;
	Link<E> *tail;
	Link<E> *curr;
	int listSize;
	
	void init() {
		head = tail = curr = new Link<E>();
		listSize = 0;
	}
	
	void removeall() {
		while (head != NULL) {
			curr = head;
			head = head->next;
			delete curr;
			curr = NULL;
		}
	}
public:
	LList() { init(); }
	~LList() { removeall(); }
	
	void clear() { removeall(); init(); }
	void insert(E it) {
		curr->next = new Link<E>(it, curr->next);
		if (tail == curr) tail = curr->next;
		listSize++;
	}
	
	void append(E it) {
		tail->next = new Link<E>(it);
		tail = tail->next;
		listSize++;
	}
	
	E remove() {
		if (listSize) {
			E it = curr->next->element;
			Link<E> *ltemp = curr->next;
			
			if (tail == curr->next) tail = curr;
			curr->next = curr->next->next;
			
			delete ltemp;
			listSize--;
			
			return it;
		}
		else cout << "No element." << endl;
	}
	
	void moveToStart() { curr = head; }
	void moveToEnd() { curr = tail; }
	
	void prev() {
		if (curr == head) return;
		
		Link<E> *temp = head;
		while (temp->next != curr) temp = temp->next;
		curr = temp;
	}
	
	void next() { if (curr != tail) curr = curr->next; }
	int length() { return listSize; }
	
	int currPos() {
		Link<E> *temp = head;
		int i;
		for (i = 0; curr != temp; i++)
			temp = temp->next;
			
		return i;
	}
	
	void moveToPos(int pos) {
		if ((pos >= 0) && (pos <= listSize)) {
			curr = head;
			for (int i = 0; i < pos; i++) curr = curr->next;
		}
		else cout << "Position out of range." << endl;
	}
	
	E getValue() {
		if (curr->next != NULL) {
			return curr->next->element;
		}
		else cout << "No value." << endl;
	}
	
	void print() {
		Link<E> *temp = head->next;
		
		while (temp != NULL) {
			cout << temp->element << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	LList<int> myList;
	
	myList.insert(2);
	myList.insert(3);
	myList.insert(3);
	myList.remove();
	myList.insert(4);
	myList.insert(3);
	
	myList.print();
	
	return 0;
}
