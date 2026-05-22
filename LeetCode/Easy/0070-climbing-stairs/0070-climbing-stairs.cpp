class Solution {
public:
    int climbStairs(int n) {
        //2까지 오르는 방법
        //1까지 오르는 방법 + 1, 1까지 오르는 방법 + 2
        //[i - 1] + 1, [i - 1] + 2
        int dp[100005];
        //dp[n]은 n까지 오르는 방법
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};