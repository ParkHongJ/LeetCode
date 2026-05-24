class Solution {
public:
    int jump(vector<int>& nums) {

        int dp[1000005];
        fill(dp, dp + 1000005, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (j + nums[j] >= i)
                {
                    dp[i] = min(dp[j] + 1, dp[i]);
                }
            }
        }
        return dp[nums.size() - 1];
    }
};