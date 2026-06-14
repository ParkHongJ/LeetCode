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
    int pairSum(ListNode* head) {
        //짝수인 연결리스트에서 
        vector<int> v;
        v.reserve(100005);
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        int maxPair = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            int last = v.size() - 1 - i;
            maxPair = max(v[i] + v[last], maxPair);
        }
        return maxPair;
    }
};