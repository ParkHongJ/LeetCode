class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> answer;
        answer.resize(nums.size() * 2);
        for (int i = 0; i < answer.size(); i += nums.size())
        {
            for(int j = 0; j < nums.size(); ++j)
            {
                answer[i + j] = nums[j];
            }
        }
        return answer;
    }
};