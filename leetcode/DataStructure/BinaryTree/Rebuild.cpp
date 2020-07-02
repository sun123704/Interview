#include<iostream>
using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int n) {
		value = n;
		left = NULL;
		right = NULL;
	}
};

Node* RebuildCore(int* startPreorder, int* endPreorder,
	              int* startInorder, int* endInorder) {
	int root_value = *startPreorder;
	Node* root = new Node(root_value);
	if (startPreorder == endPreorder) {
		return root;
	}
	int step = 0, max_step = endInorder - startInorder;
	while (step <= max_step && *(startInorder + step) != root_value) {
		step++;
	}
	root->left = RebuildCore(startPreorder+1, startPreorder +step,
		                     startInorder, startInorder+step);
	root->right = RebuildCore(startPreorder + step +1, endPreorder,
		                      startInorder +1+step, endInorder);
	return root;
}

Node* Rebuild_Recurse(int* preorder, int* inorder, int length) {
	// 判断索引在数组长度范围
	if (length <= 0 || preorder ==NULL || inorder ==NULL) {
		return NULL;
	}
	return  RebuildCore(preorder, preorder + length - 1,
		inorder, inorder + length - 1);
}

// for test
/*    0
*    / \
*   1   2
*      / \
*     3   4
*/
void PreOrder(Node* head);
int main() {
	int preorder[5] = { 0,1,2,3,4 };
	int inorder[5] = { 1, 0, 3, 2, 4 };
	PreOrder(Rebuild_Recurse(preorder, inorder, 5));
	
}