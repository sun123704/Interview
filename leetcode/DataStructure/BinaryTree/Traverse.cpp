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

/* �ǵݹ�ǰ�������
*  1. ������ջ��ͷ�ڵ�ѹ��stack��;
*  2. ����ջ���ڵ㣬��Ϊcur����ӡcur��ֵ���ٽ�cur���ҽڵ�(�ǿ�)ѹ��stack�������ڵ�(�ǿ�)ѹ��stack��
*  3. �ظ�2���裬ֱ��stackΪ��
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

/* �ǵݹ����������
*  1. ������ջ����cur = head;
*  2. ��curѹ��stack����cur = cur.left���ظ�����2��ֱ��cur == NULL��
*  3. ����stackջ������Ϊnode�����nodeֵ����cur=node.right���ظ�����2
*  4. ֱ��stackΪ����curΪ�գ���ֹ
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

/* �ǵݹ���������������ջ��ʵ�֡�
*  1. ����ջs1��s2����headѹ��s1��
*  2. ��s1����ջ��Ԫ�أ���Ϊcur����cur����ڵ㡢�ҽڵ�ѹ��s1��s1ÿ������Ԫ�ض�ѹ��s2�У�
*  3. �ظ�����2��ֱ��s1Ϊ�գ�
*  4. ����s2����ӡ��
*/
void PostOrder(Node* head) {
	if (head != NULL) {
		stack<Node*> s1, s2;
		s1.push(head);
		while (!s1.empty()) {
			Node* cur = s1.top();
			s1.pop();
			if (cur->right != NULL) s1.push(cur->left);  // �����Ҹ���ע������ѹ����ڵ㣬��Ϊ��Ҫ��ջs2�������ȴ�ӡ�����ѹ��ڵ�
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