class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        answer.reserve(nums1.size());

        unordered_map<int,int> m;

        stack<int> mono;
        mono.push(nums2[0]);
        for (int i = 1; i < nums2.size(); ++i)
        {
            while (!mono.empty() && mono.top() < nums2[i])
            {
                m[mono.top()] = nums2[i];
                mono.pop();
            }
            mono.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); ++i)
        {
            if (m.find(nums1[i]) != m.end())
            {
                answer.push_back(m[nums1[i]]);
            }
            else
            {
                answer.push_back(-1);
            }
        }

        return answer;
    }
};