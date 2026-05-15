class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;

        unordered_map<int,int> m;
        for (int i = 0; i < nums2.size(); ++i)
        {
            m.insert(make_pair(nums2[i], i));
        }

        for (int i = 0; i < nums1.size(); ++i)
        {
            int num2Idx = m[nums1[i]];

            if (num2Idx + 1 >= nums2.size())
            { 
                answer.push_back(-1);
                continue;
            }
            for (int j = num2Idx + 1; j < nums2.size(); ++j)
            {
                if (nums1[i] < nums2[j])
                {
                    answer.push_back(nums2[j]);
                    break;
                }
                if (j + 1 >= nums2.size())
                {
                    answer.push_back(-1);
                    break;
                }
            }
        }
        return answer;
    }
};