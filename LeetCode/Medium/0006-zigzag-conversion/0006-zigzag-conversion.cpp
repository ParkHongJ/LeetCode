class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            v[i].reserve(s.length());
        }
        
        if (numRows == 1)
            return s;

        int cursor = 0;
        while (cursor < s.length())
        {
            // 0 1 2 3 4 5 | 6 7 8 9 10 11
            // 0 1 2 3 2 1 | 0 1 2 3  2  1

            //0 1 2 1
            int width = numRows * 2 - 2;
            int row = 0;
            for (int i = 0; i < width; ++i)
            {
                if (i >= numRows)
                {
                    row = width - i;
                }
                else
                {
                    row = i;
                }
                if (cursor >= s.length())
                    break;

                v[row].push_back(s[cursor++]);
            }
        }

        string answer;
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < v[i].size(); ++j)
            {
                answer += v[i][j];
            }
        }
        return answer;
    }
};