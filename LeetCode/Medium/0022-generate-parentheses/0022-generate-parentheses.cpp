class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // n = 3
        // ((( )))

        vector<vector<string>> dp;
        dp.resize(n + 1);
        dp[0] = {""};

        for (int i = 1; i <= n; ++i)
        {
            for (int inside = 0; inside < i; ++inside)
            {
                int outside = i - 1 - inside;

                for (string& in : dp[inside])
                {
                    for (string& out : dp[outside])
                    {
                        dp[i].push_back("(" + in + ")" + out);
                    }
                }
            }
        }
        return dp[n];
    }
};