
    vector<string> table = {
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
    };
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // 1 abc
        // 2 def
        // 3 ghi
        dfs(0, digits);
        
        return answer;
    }
    string s;
    vector<string> answer;
    void dfs(int d/*현재 선택한 digitsd*/, const string& digits)
    {
        if (s.length() == digits.length())
        {
            answer.push_back(s);
            return;
        }
        for (int i = d; i < digits.length(); ++i)
        {
            int cur = ((digits[i] - '0') - 2); // 2면 0로

            int cnt = 3;
            if (cur == 7 || cur == 5)
                cnt = 4;
            
            

            for (int j = 0; j < cnt; ++j)
            {
                char select = table[cur][j]; 
                s += select;
                dfs(i + 1, digits);
                s.pop_back();
                // 0 = 0 1 2
                // 1 = 3 4 5
                // 2 = 6 7 8
                // 3 = 9 10 11
                // 4 = 12 13 14
                // 5 = 15 16 17 18
                // 6 = 19 20 21
                // 7 = 22 23 24 25

                //cur = d를 숫자로 0~7사이로 변환한 수
            }    
        }
    }
};