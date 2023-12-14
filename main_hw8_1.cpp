/* Reference: I took course in Udemy with Abdul Bari and I learned most of my
 * data structure from his teaching so I implment BST base on that course.
 * Specially insert function , countLeaves , and countOneChildNode.
 * https://www.udemy.com/course/datastructurescncpp/learn/lecture/13168870#overview
 * INSTRUCTION:
 *     This is a C++ starting code for hw8_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw8_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw8_1.cpp
 * Abstract: his program utilizes a Binary Search Tree (BST) to perform various
 *traversals. It prompts the user to input values to build the BST, and then
 *allows the user to select the type of traversal they would like to perform,
 *such as postOrder or preOrder. Additionally, the program provides
 *functionality for determining the height of the BST, the number of leaf nodes,
 *and the count of nodes with only one child 
 *ID: 7263 
 *Name: Mohammad Haroon
 * Date: 04/04/2023
 */

#include <iostream>
#include <vector>

using namespace std;
// vector that use to print BST postOrder and preOrder
vector<int> v, v2;
// creating class Node which contain left child and right child of tree.
class Node {
public:
	Node *lchild;
	int data;
	Node *rchild;
};

// creating BST class where we will be inserting data using loop and printing
// preOrder , postOrder, height , leaf childs , count leaf one cild. and search
// specfic value

class BST {
private:
	Node *root;

public:
	BST() {
		root = nullptr;
	}
	Node *getRoot() {
		return root;
	}
	void insert(int key);
	void postOrder(Node *p);
	void preOrder(Node *p);
	int countLeaves(Node *p);
	int countOneChildNodes(Node *p);
	int height(Node *p);
};

// Function that build and add nodes to BST
void BST::insert(int key) {
	Node *t = root;
	Node *p;
	Node *r;

	// check if root is empty
	if (root == nullptr) {
		p = new Node;  // intilizing the Node
		p->data = key; // assigning the value of key to p
		p->lchild = nullptr;
		p->rchild = nullptr;
		root = p;
		return; // when  root is null assgin the value and return
	}

	while (t != nullptr) {
		r = t;
		if (key < t->data) {
			t = t->lchild;
		} else if (key > t->data) {
			t = t->rchild;
		} else {
			return;
		}
	}

	// Now t points at nullptr and r points at insert loaction
	p = new Node;
	p->data = key;
	p->lchild = nullptr;
	p->rchild = nullptr;
	if (key < r->data) {
		r->lchild = p;
	} else {
		r->rchild = p;
	}
}

// Function that print BST in postOrder
void BST::postOrder(Node *P) {
	int num;
	if (P) {
		postOrder(P->lchild);
		postOrder(P->rchild);
		num = P->data;
		v.push_back(num);
	}
}

//
// Function that print BST in preOrder
void BST::preOrder(Node *p) {
	int num;
	if (p) {
		num = p->data;
		v2.push_back(num);
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

// Function that count the number of leaves in BST
int BST::countLeaves(Node *p) {
	if (p == nullptr) {
		return 0;
	}
	if (p->lchild == nullptr && p->rchild == nullptr) {
		return 1;
	} else {
		return countLeaves(p->lchild) + countLeaves(p->rchild);
	}
}

// Function tha count node with one child in BST
int BST::countOneChildNodes(Node *p) {
	int x;
	int y;
	if (p != nullptr) {
		x = countOneChildNodes(p->lchild);
		y = countOneChildNodes(p->rchild);
		if (p->lchild != nullptr ^ p->rchild != nullptr) {
			return x + y + 1;
		} else {
			return x + y;
		}
	}
	return 0;
}

// Function that return the height of BST
int BST::height(Node *t) {
	if (t == nullptr) {
		return -1;
	} else {
		int left = height(t->lchild);
		int right = height(t->rchild);
		return max(left, right) + 1;
	}
}

int main() {
	BST bst; // BST class object

	int userNum, node;

	cin >> userNum;		  // user input
	while (userNum > 0) { // start of loop
		string input;
		cin >> input; // user input
		if (input == "add") {
			cin >> node;
			bst.insert(node); // adding node to BST
		} else {
			if (input == "postOrder") {
				bst.postOrder(
					bst.getRoot()); // Function call to print postOrder
				for (int i = 0; i < v.size(); i++) {
					if (i == v.size() - 1) {
						cout << v[i];
					} else {
						cout << v[i] << " ";
					}
				}
				cout << endl;
			} else if (input == "preOrder") {
				bst.preOrder(bst.getRoot()); // function call to print preOrder
				for (int i = 0; i < v2.size(); i++) {
					if (i == v2.size() - 1) {
						cout << v2[i];
					} else {
						cout << v2[i] << " ";
					}
				}
				cout << endl;
			} else if (input == "countLeaves") { // print number of leaves
				cout << bst.countLeaves(bst.getRoot()) << endl;
                
			} else if (input == "countOneChildNodes") { // print number of child
														// nodes
				cout << bst.countOneChildNodes(bst.getRoot()) << endl;
			} else if (input == "height") { // print height of BST
				cout << bst.height(bst.getRoot()) << endl;
			}
		}
		userNum--; // decrement
	}

	return 0;
}
