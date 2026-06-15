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
    ListNode* deleteMiddle(ListNode* head) {
        vector<ListNode*> v;
        ListNode* temp = head;
        while (temp != nullptr)
        {
            v.push_back(temp);
            temp = temp->next;
        }
        int middleIdx = v.size() / 2;
        
        if (middleIdx - 1 < 0)
        {
            //이전 노드가 없다면
            if (v.size() == 1)
                return nullptr;
            head = v[middleIdx + 1];
        }
        else if (middleIdx + 1 >= v.size())
        {
            //다음 노드가 없다면
            v[middleIdx - 1]->next = nullptr;
        }
        else
        {
            v[middleIdx - 1]->next = v[middleIdx + 1];
        }
        return head;
    }
};