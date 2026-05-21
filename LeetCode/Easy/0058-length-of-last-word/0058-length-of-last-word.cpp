class Solution {
public:
    int lengthOfLastWord(string s) {
        int answer = 0;
        bool bFound = false;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] == ' ')
            {
                if (!bFound)
                    continue;
                break;
            }
            else
            {
                if (!bFound)
                {
                    bFound = true;
                }
                ++answer;
            }
        }
        return answer;
    }
};