/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0, num = 0;
		ListNode *res = nullptr, *cur = nullptr;
		while (l1 != nullptr || l2 != nullptr || carry != 0) {
			carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
			num = carry % 10;     // 求和
			carry = carry / 10;   // 进位
			ListNode *node = new ListNode(num);
			if (res == nullptr) {   //第一个节点
				res = node;
				cur = res;
			} else {
				cur->next = node;
				cur = cur->next;
			}
			l1 = l1 ? l1->next:nullptr;
			l2 = l2 ? l2->next : nullptr;
		}
		return res;
	}
};