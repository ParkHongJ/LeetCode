class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //인덱스 0이나 1에서 시작해서 [현재 단계의 cost를 지불하고] 1이나 2로 이동한다.

        //dp[i]는 i번째 계단까지 오는 최소비용
        //dp[i] = dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]
        int dp[1005] = {};
        dp[0] = 0;

        dp[1] = 0;
        for (int i = 2; i <= cost.size(); ++i)
        {
            //현재 최상층이면
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        } 
        return dp[cost.size()];
    }
};