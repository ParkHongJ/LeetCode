class Solution {
public:
    bool divisorGame(int n) {
        //플레이어는 n의 약수 임의의 x를 선택한다 (n은 안됨)      

        bool dp[1005]; // i로 시작했을 때 승리여부
        dp[2] = true; // 2는 무조건이김
        //현재 i의 약수중에서 true가 있다면 그걸 넣음
        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j) 
            {
                //i의 약수 j
                if (i % j == 0 && i / j >= 1)
                {
                    if (!dp[i - j]) //
                        dp[i] = true; 
                }
            }
        }
        return dp[n];
    }
};