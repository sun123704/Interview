#include<iostream>
#include<stack>
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

void PreOrder_Resur(Node* head) {
	if (head == NULL) return;
	std::cout << head->value << " ";
	PreOrder_Resur(head->left);
	PreOrder_Resur(head->right);
}

void InOrder_Resur(Node* head) {
	if (head == NULL) return;
	InOrder_Resur(head->left);
	std::cout << head->value << " ";
	InOrder_Resur(head->right);
}

void PostOrder_Resur(Node* head) {
	if (head == NULL) return;
	PostOrder_Resur(head->left);	
	PostOrder_Resur(head->right);
	std::cout << head->value << " ";
}

/* 非递归前序遍历：
*  1. 申请新栈，头节点压入stack中;
*  2. 弹出栈顶节点，记为cur，打印cur的值，再将cur的右节点(非空)压入stack，最后将左节点(非空)压入stack；
*  3. 重复2步骤，直到stack为空
*/
void PreOrder(Node* head) {
	if (head != NULL) {
		stack<Node*> stk;
		stk.push(head);
		while (!stk.empty()) {
			Node* cur = stk.top();
			stk.pop();
			std::cout << cur->value << " ";
			if (cur->right != NULL) stk.push(cur->right);
			if (cur->left != NULL) stk.push(cur->left);
		}
	}
}

/* 非递归中序遍历：
*  1. 申请新栈，记cur = head;
*  2. 将cur压入stack，记cur = cur.left，重复步骤2，直到cur == NULL；
*  3. 弹出stack栈顶，记为node，输出node值，令cur=node.right，重复步骤2
*  4. 直到stack为空且cur为空，终止
*/
void InOrder(Node* head) {
	if (head != NULL) {
		stack<Node*> stk;
		Node* cur = head;
		while (cur != NULL || !stk.empty()) {
			while (cur != NULL) {
				stk.push(cur);
				cur = cur->left;
			}
			if (!stk.empty()) {
				Node* node = stk.top();
				std::cout << node->value << " ";
				stk.pop();
				cur = node->right;
			}
		}
	}
}

/* 非递归后序遍历：【两个栈的实现】
*  1. 申请栈s1、s2；将head压入s1；
*  2. 从s1弹出栈顶元素，记为cur，将cur的左节点、右节点压入s1；s1每弹出的元素都压入s2中；
*  3. 重复步骤2，直到s1为空；
*  4. 弹出s2，打印；
*/
void PostOrder(Node* head) {
	if (head != NULL) {
		stack<Node*> s1, s2;
		s1.push(head);
		while (!s1.empty()) {
			Node* cur = s1.top();
			s1.pop();
			if (cur->right != NULL) s1.push(cur->left);  // 【左右根】注意是先压入左节点，因为还要进栈s2，所以先打印左就先压左节点
			if (cur->left != NULL) s1.push(cur->right);
			s2.push(cur);
		}
		while (!s2.empty()) {
			Node* node = s2.top();
			s2.pop();
			std::cout << node->value << " ";
		}
	}
}

// for test
/*    0
*    / \
*   1   2
*      / \
*     3   4
*/
Node** NewBinaryTree() {
	Node** root = new Node*[5];
	for (int i = 0; i < 5; i++) {
		Node* node = new Node(i);
		root[i] = node;
	}
	root[0]->left = root[1];
	root[0]->right = root[2];
	root[2]->left = root[3];
	root[2]->right = root[4];
	return root;
}
//int main() {
//	Node** root = NewBinaryTree();
//	PostOrder(*root);
//}