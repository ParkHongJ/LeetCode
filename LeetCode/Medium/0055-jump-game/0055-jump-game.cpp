class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        //dp[i] i번째 자리에서 goal에 도착 가능한가
        bool dp[100005] = { false };

        int goal = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (i + nums[i] >= goal)
            {
                dp[i] = true;
                goal = i;
            }
        }
        return dp[0];
    }
};