class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        vector<long long> lens;
        lens.resize(s.length());

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '#')
            {
                len *= 2;
            }
            else if (s[i] == '*')
            {
                if (len > 0)
                    --len;
            }
            else if (s[i] != '%')
                ++len;
                
            lens[i] = len;
        }
        
        if (k >= len)
            return '.';

        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] == '#')
            {
                len /= 2;
                k = k % len;
            }
            else if (s[i] == '%')
            {
                k = len - 1 - k;
            }
            else if (s[i] == '*')
            {
                if (i > 0)
                {
                    len = lens[i - 1];
                }
                else        
                {
                    len = 0;
                }
            }
            else 
            {
                if (k == len - 1)
                    return s[i];
                --len;
            }
        }

        return '.';
    }
};