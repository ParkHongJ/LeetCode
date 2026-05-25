class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int answer = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                int cnt = 0;
                while (i < nums.size() && nums[i] == 1)
                {
                    ++cnt;
                    ++i;
                }
                answer = max(answer, cnt);
            }
        }
        return answer;
    }
};