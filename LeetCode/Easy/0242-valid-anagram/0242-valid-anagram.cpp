class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v;
        v.resize(('z'));

        for (int i = 0; i < s.length(); ++i)
        {
            ++v[s[i] - '0'];
        }
        for (int i = 0; i < t.length(); ++i)
        {
            --v[t[i] - '0'];
            if (v[t[i] - '0'] < 0)
                return false;
        }
        if (s.length() != t.length())
            return false;
        return true;
    }
};