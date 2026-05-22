class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> base;
        base.resize('z' - 'a' + 1);

        for (int i = 0; i < magazine.length(); ++i)
        {
            int idx = magazine[i] - 'a';
            ++base[idx];
        }

        for (int i = 0; i < ransomNote.length(); ++i)
        {
            int idx = ransomNote[i] - 'a';
            if (base[idx] <= 0)
                return false;
            --base[idx];
        }
        return true;
    }
};