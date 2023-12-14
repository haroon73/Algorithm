/*Reference: For the implementing binary tree I use some ideas from the class i
 took in Udemy with instructor Abdul Bari special how use queue to implment
 append node to the tree. To traverse levelOrder I got that idea from Dr Byun
 and through that idea I implement find firstChild
 node.https://www.udemy.com/course/datastructurescncpp/learn/lecture/13168246#overview



 * INSTRUCTION:
 *     This is a C++ starting code for hw8_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw8_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw8_2.cpp
 * Abstract: This program prompts the user to input the first node, and then
 *allows them to append nodes to create a binary tree using queue. The
 *program supports
 *traversals including inOrder, postOrder, preOrder, and levelOrder.
 *Additionally, the program provides functionality for determining whether
 *the tree is a binary search tree (BST), finding the first child node, and
 *determining the height of the tree
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 04/05/2023
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// Global vectors that use to pring inOrder , postOrder , preorder ,
// is tree BST , findFirst node
vector<int> vpostOrder, vpreOrder, vinOrder, isBstV, isBstV2, findFnode;
// creating class Node which contain left child and right child of tree.
class Node {
public:
	Node *lchild;
	int data;
	Node *rchild;
	Node(int data) {
		this->data = data;
		rchild = nullptr;
		lchild = nullptr;
	}
};

// creating BST class where we will be inserting data using loop and printing
// ing inorder and search specfic value

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
	void insert(int data);
	void postOrder(Node *p);
	void preOrder(Node *p);
	void findFirstNode(Node *p);
	int height(Node *p);
	void inOrder(Node *p);
	bool isBST();
	void isBSTInOrder(Node *p);
};

//
// function that append node to tree using queue
void BST::insert(int val) {
	Node *node = new Node(val);
	if (root == NULL) { // if root or head is null add node there
		root = node;
	} else {
		queue<Node *> q; // queue
		q.push(root);	// pusing root node to the queue
		while (!q.empty()) {
			Node *temp = q.front(); //
			q.pop();
			if (temp->lchild == NULL) { // going to left child
				temp->lchild = node;
				break;
			} else {
				q.push(temp->lchild);
			}
			if (temp->rchild == NULL) { // going to right child
				temp->rchild = node;
				break;
			} else {
				q.push(temp->rchild);
			}
		}
	}
}

// Function that print BST in postOrder
void BST::postOrder(Node *P) {
	int num;
	if (P) {
		postOrder(P->lchild);
		postOrder(P->rchild);
		num = P->data;
		vpostOrder.push_back(num);
	}
}

//
// Function that print BST in preOrder
void BST::preOrder(Node *p) {
	int num;
	if (p) {
		num = p->data;
		vpreOrder.push_back(num);
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

// function that print tree in inOrder
void BST::inOrder(Node *p) {
	int num;
	if (p) {
		inOrder(p->lchild);
		num = p->data;
		vinOrder.push_back(num);
		inOrder(p->rchild);
	}
}

// function that pushing all nodes to vector then find if tree is BST or not
void BST::isBSTInOrder(Node *p) {
	int num;
	if (p) {
		isBSTInOrder(p->lchild);
		num = p->data;
		isBstV2.push_back(num);

		isBSTInOrder(p->rchild);
	}
}

// boolean function that return true if is BST or return false if not
bool BST::isBST() {
	bool isTrue;
	for (int i = 0; i < isBstV2.size() - 1; i++) {
		if (isBstV2[i] < isBstV2[i + 1]) {
			isTrue = true;
		} else {
			isTrue = false;
			break;
		}
	}
	return isTrue;
}

// function that push nodes to vector in postorder to find first node
void BST::findFirstNode(Node *p) {
	int num;
	if (p) {
		findFirstNode(p->lchild);
		findFirstNode(p->rchild);
		num = p->data;
		findFnode.push_back(num);
	}
}

// function that find height of tree
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
	// vector that will keep nodes in levelOrder
	vector<int> levelOrder;

	BST bst; // BST object

	int userNum, node, rootNode;

	cin >> rootNode; // user input

	levelOrder.push_back(rootNode); // pushing root node to vector

	bst.insert(rootNode); // append first node

	cin >> userNum;

	while (userNum > 0) {
		string input;

		cin >> input;

		if (input == "append") {
			cin >> node;
			bst.insert(node); // appending childs node to tree

			levelOrder.push_back(node); // pushing all nodes to keep levelOrder

		} else {
			if (input == "postOrder") {
				bst.postOrder(
					bst.getRoot()); // function call to prind postOrder

				for (int i = 0; i < vpostOrder.size(); i++) {
					if (i == vpostOrder.size() - 1) {
						cout << vpostOrder[i];
					} else {
						cout << vpostOrder[i] << " ";
					}
				}
				cout << endl;
			} else if (input == "preOrder") {
				bst.preOrder(
					bst.getRoot()); // function that print tree in preOrder

				for (int i = 0; i < vpreOrder.size(); i++) {
					if (i == vpreOrder.size() - 1) {
						cout << vpreOrder[i];
					} else {
						cout << vpreOrder[i] << " ";
					}
				}
				cout << endl;

			} else if (input == "isBST") {
				bst.isBSTInOrder(bst.getRoot()); // function call to find if
												 // tree is BST or not

				if (bst.isBST()) {
					cout << "true" << endl;
				} else {
					cout << "false" << endl;
				}

			} else if (input == "findFirstNode") {
				bst.findFirstNode(
					bst.getRoot()); // function call to find first node

				cout << findFnode[0]
					 << endl; // printing the first index of the tree that keep
							  // tree as postOdre traverse order
				findFnode.clear();			// clearing vector for next use
			} else if (input == "height") { // find tree height
				cout << bst.height(bst.getRoot()) << endl;
			} else if (input == "inOrder") { // function call for inOrder
				bst.inOrder(bst.getRoot());

				for (int i = 0; i < vinOrder.size(); i++) {
					if (i == vinOrder.size() - 1) {
						cout << vinOrder[i];

					} else {
						cout << vinOrder[i] << " ";
					}
				}
				cout << endl;

			} else if (input == "levelOrder") { // print levelorder use vecto r
				for (int i = 0; i < levelOrder.size(); i++) {
					if (i == levelOrder.size() - 1) {
						cout << levelOrder[i];
					} else {
						cout << levelOrder[i] << " ";
					}
				}
				cout << endl;
			}
		}
		userNum--;
	}

	return 0;
}
