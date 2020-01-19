#include<iostream>
using namespace std;

struct ListNode {
	int value;
	ListNode* p_next;
};

// ������β����ӽڵ�
void AddToTail(ListNode** pHead, int value) {
	// 0. �����½ڵ�
	ListNode* p_New = new ListNode;
	p_New->value = value;
	p_New->p_next = NULL;
	// 1. ͷ�ڵ���NULL
	if (*pHead == NULL) {
		*pHead = p_New;
		return;
	}
	else {
		ListNode* p = *pHead;
		while (p->p_next != NULL) {
			p = p->p_next;
		}
		p->p_next = p_New;
	}
}

// ɾ��ָ��ֵ�Ľڵ�
void RemoveNode(ListNode** pHead, int value) {
	if (pHead == NULL || *pHead == NULL) {
		return;
	}
	// 1. ͷ�ڵ��Ǵ�ɾ���ڵ�
	if ((*pHead)->value == value) {
		ListNode* p_tmp = (*pHead)->p_next;
		delete *pHead;
		pHead = &p_tmp;
		return;
	}
	// 2. ��ɾ���ڵ��ͷ�ڵ�
	ListNode* p_Current = *pHead;
	while (p_Current->p_next != NULL && p_Current->p_next->value != value) {
		p_Current = p_Current->p_next;
	}
	if (p_Current->p_next != NULL && p_Current->p_next->value == value) {
		ListNode* p_tmp = p_Current->p_next;
		p_Current->p_next = p_Current->p_next->p_next;
		delete p_tmp;
		p_tmp = NULL;
	}
}

// ��β��ͷ��ӡ�ڵ�
void PrintListReversingly_Recursively(ListNode* pHead) {
	if (pHead == NULL) return;
	// 1. ����β�ڵ�
	if (pHead->p_next == NULL) {
		std::cout << pHead->value;
	} else {
		PrintListReversingly_Recursively(pHead->p_next);
		std::cout << pHead->value;
	}
}

// TODO
int main() {}