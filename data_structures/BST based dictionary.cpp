#include <iostream>
using namespace std;

template <typename Key, typename E> 
class BSTNode {
private:
	Key k;
	E it;
	BSTNode *lc;
	BSTNode *rc;
public:
	BSTNode() { lc = rc = NULL; }
	BSTNode(Key K, E e, BSTNode *l= NULL, BSTNode *r= NULL) { k = K; it = e; lc = l; rc = r; }
	~BSTNode() {}
	
	E& element() { return it; }
	void setElement(const E& e) { it = e; }
	Key& key() { return k; }
	void setKey(const Key& K) { k = K; }
	
	inline BSTNode *left() const { return lc; }
	void setLeft(BSTNode<Key, E> *b) { lc = (BSTNode*)b; }
	inline BSTNode *right() const { return rc; }
	void setRight(BSTNode<Key, E> *b) { rc = (BSTNode*)b; }
	
	bool isLeaf() { return (lc == NULL) && (rc == NULL); }
};

template <typename Key, typename E>
class BST {
private:
	BSTNode<Key, E> *root;
	int nodecount;
	
	void clearhelp(BSTNode<Key, E>*);
	BSTNode<Key,E> *inserthelp(BSTNode<Key, E>*, const Key&, const E&);
	BSTNode<Key,E> *deletemin(BSTNode<Key, E>*);
	BSTNode<Key,E>* getmin(BSTNode<Key, E>*);
	BSTNode<Key,E>* removehelp(BSTNode<Key, E>*, const Key&);
	E findhelp(BSTNode<Key, E>*, const Key&) const;
	void printhelp(BSTNode<Key, E>*, int) const;
public:
	BST() { root = NULL; nodecount = 0; }
	~BST() { clearhelp(root); }
	void clear() { clearhelp(root); root = NULL; nodecount = 0; }
	
	void insert(Key k, E e) {
		root = inserthelp(root, k, e);
		nodecount++;
	}
	
	E remove(Key k) {
		E temp = findhelp(root, k);
		if (temp != NULL) {
			root = removehelp(root, k);
			nodecount--;
		}
		return temp;
	}
	
	E removeAny() {
		if (root != NULL) {
			E temp = root->element();
			root = removehelp(root, root->key());
			nodecount--;
			return temp;
		}
	}

	E find(const Key& k) const { return findhelp(root, k); }
	int size() { return nodecount; }
	
	void print() const {
		if (root == NULL) cout << "The BST is empty." << endl;
		else printhelp(root, 0);
	}
};

template <typename Key, typename E>
E BST<Key, E>::findhelp(BSTNode<Key, E> *root, const Key& k) const {
	if (root == NULL) return NULL;
	if (k < root->key())
		return findhelp(root->left(), k);
	else if (k > root->key())
		return findhelp(root->right(), k);
	else return root->element();
}

template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::inserthelp(BSTNode<Key, E> *root, const Key& k, const E& it) {
	if (root == NULL)
		return new BSTNode<Key, E>(k, it, NULL, NULL);
	if (k < root->key())
		root->setLeft(inserthelp(root->left(), k, it));
	else root->setRight(inserthelp(root->right(), k, it));
	return root;
}

template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::deletemin(BSTNode<Key, E> *rt) {
	if (rt->left() == NULL)
		return rt->right();
	else {
		rt->setLeft(deletemin(rt->left()));
		return rt;
	}
}

template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::getmin(BSTNode<Key, E> *rt) {
	if (rt->left() == NULL)
		return rt;
	else return getmin(rt->left());
}

template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::removehelp(BSTNode<Key, E>* rt, const Key& k) {
	if (rt == NULL) return NULL;
	else if (k < rt->key())
		rt->setLeft(removehelp(rt->left(), k));
	else if (k > rt->key())
		rt->setRight(removehelp(rt->right(), k));
	else {
		BSTNode<Key, E>* temp = rt;
		if (rt->left() == NULL) {
			rt = rt->right();
			delete temp;
		}
		else if (rt->right() == NULL) {
			rt = rt->left();
			delete temp;
		}
		else {
			BSTNode<Key, E>* temp = getmin(rt->right());
			rt->setElement(temp->element());
			rt->setKey(temp->key());
			rt->setRight(deletemin(rt->right()));
			delete temp;
		}
	}
	return rt;
}

template <typename Key, typename E>
void BST<Key, E>::clearhelp(BSTNode<Key, E> *root) {
	if (root == NULL) return;
	clearhelp(root->left());
	clearhelp(root->right());
	delete root;
}

template <typename Key, typename E>
void BST<Key, E>::printhelp(BSTNode<Key, E>* root, int level) const {
	if (root == NULL) return; 
	printhelp(root->left(), level + 1);
	for (int i = 0; i < level; i++)
		cout << " ";
	cout << root->key() << endl;
	printhelp(root->right(), level + 1);
}


int main() {
	BST<int, int> myBS;
	
	myBS.print();
	cout << "Let me add some nodes..." << endl;
	
	myBS.insert(0, 5);
	myBS.insert(1, 6);
	myBS.insert(2, 7);
	
	myBS.print();
	
	myBS.removeAny();
	myBS.removeAny();
	
	cout << "And now I'll remove some nodes.." << endl;
	myBS.print();
	
	return 0;
}
