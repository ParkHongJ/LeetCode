class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            bool bFound = false;
            while (cnt < t.length())
            {
                if (s[i] == t[cnt++])
                {
                    bFound = true;
                    break;
                }
            }
            if (!bFound)
                return false;
        }

        return true;
    }
};