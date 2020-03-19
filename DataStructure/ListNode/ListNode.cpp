#include<iostream>
using namespace std;

struct ListNode {
	int value;
	ListNode* p_next;
};

// 在链表尾部添加节点
void AddToTail(ListNode** pHead, int value) {
	// 0. 生成新节点
	ListNode* p_New = new ListNode;
	p_New->value = value;
	p_New->p_next = NULL;
	// 1. 头节点是NULL
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

// 删除指定值的节点
void RemoveNode(ListNode** pHead, int value) {
	if (pHead == NULL || *pHead == NULL) {
		return;
	}
	// 1. 头节点是待删除节点
	if ((*pHead)->value == value) {
		ListNode* p_tmp = (*pHead)->p_next;
		delete *pHead;
		pHead = &p_tmp;
		return;
	}
	// 2. 待删除节点非头节点
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

// 从尾到头打印节点
void PrintListReversingly_Recursively(ListNode* pHead) {
	if (pHead == NULL) return;
	// 1. 到达尾节点
	if (pHead->p_next == NULL) {
		std::cout << pHead->value;
	} else {
		PrintListReversingly_Recursively(pHead->p_next);
		std::cout << pHead->value;
	}
}

// TODO
int main() {}