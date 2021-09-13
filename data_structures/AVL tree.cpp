#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};

int height(Node *N) {
	if (N == NULL)
		return 0;
	return N->height;
}

Node* new_node(int key) {
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

Node *right_rotate(Node *y) {
	Node *x = y->left;
	Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	return x;
}

Node *left_rotate(Node *x) {
	Node *y = x->right;
	Node *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	return y;
}

int get_balance(Node *N) {
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key) {
	if (node == NULL)
		return(new_node(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	node->height = 1 + max(height(node->left),
						height(node->right));

	int balance = get_balance(node);

	if (balance > 1 && key < node->left->key)
		return right_rotate(node);

	if (balance < -1 && key > node->right->key)
		return left_rotate(node);

	if (balance > 1 && key > node->left->key) {
		node->left = left_rotate(node->left);
		return right_rotate(node);
	}

	if (balance < -1 && key < node->right->key) {
		node->right = right_rotate(node->right);
		return left_rotate(node);
	}

	return node;
}

void pre_order(Node *root) {
	if(root != NULL) {
		cout << root->key << " ";
		pre_order(root->left);
		pre_order(root->right);
	}
}

int main() {
	Node *root = NULL;
	
	root = insert(root, 4);
	root = insert(root, 6);
	root = insert(root, 8);
	root = insert(root, 3);
	root = insert(root, 2);
	root = insert(root, 5);
	
	cout << "Tree preorder traversal - ";
	pre_order(root);
	
	return 0;
}
