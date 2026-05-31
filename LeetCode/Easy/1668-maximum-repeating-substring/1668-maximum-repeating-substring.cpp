class Solution {
public:
    int maxRepeating(string sequence, string word) {
        //word가 sequence내에서 "최대" 몇번 반복되냐?
        //sequence에서 i까지 봤을때 word의 반복 개수
        // i = 4까지 봤을 때 sequence의 word 반복개수 = 2
        // i = 2까지 봤을 대 sqeuence의 word 반복개수 = 1
        // sequence = ababc, word = ab
        // 부분 문제로 쪼갤수 있을까?

        vector<int> dp(sequence.length() + 1);

        int answer = 0;
        for (int i = 0; i + word.length() <= sequence.length(); ++i)
        {
            string str = sequence.substr(i, word.length());
            if (str == word)
            {
                int end = i + word.length() - 1;

                if (i - 1 >= 0)
                    dp[end] = dp[i - 1] + 1;
                else
                    dp[end] = 1;

                answer = max(answer, dp[end]);
            }
        }
        return answer;
    }
};