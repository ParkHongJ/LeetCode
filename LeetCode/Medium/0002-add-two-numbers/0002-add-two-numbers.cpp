/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode;
ListNode* current = answer;

ListNode* prev = nullptr;
while (true)
{
	int sum = 0;

	if (l1)
		sum += l1->val;

	if (l2)
		sum += l2->val;

	if (l1 == nullptr && l2 == nullptr)
		break;

	if (current == nullptr)
	{
		current = prev->next = new ListNode;
	}
	
	sum += current->val;

	if (sum > 9)
	{
		if (current->next == nullptr)
		{
			current->next = new ListNode;
		}
		++(current->next->val);
		current->val = sum % 10;
	}
	else
	{
		current->val = sum;
	}

	if (l1)
		l1 = l1->next;
	if (l2)
		l2 = l2->next;

	cout << current->val << ", ";
	prev = current;
	current = current->next;
}
return answer;
    }
};