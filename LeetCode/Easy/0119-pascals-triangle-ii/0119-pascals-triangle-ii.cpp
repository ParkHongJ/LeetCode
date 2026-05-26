class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> answer;

        answer.resize(rowIndex + 1);

        vector<vector<int>> v;
        v.resize(34);
        v[0].push_back(1);
        v[1].push_back(1);
        v[1].push_back(1);

        for (int i = 2; i <= rowIndex; ++i)
        {
            v[i].resize(i + 1);
            v[i][0] = 1;
            v[i][i] = 1;
            for (int j = 1; j <= i - 1; ++j)
            {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }

        for (int i = 0; i < rowIndex + 1; ++i)
        {
            answer[i] = v[rowIndex][i];
        }
        return answer;
    }
};