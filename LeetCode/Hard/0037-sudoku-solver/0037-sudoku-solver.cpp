class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == '.')
                    ++maxCnt;
            }
        }
        dfs(0, board);
    }
    int maxCnt = 0;
    bool IsValid(int i, int j, int k, const vector<vector<char>>& board)
    {
        //가로 세로 셀 안쪽검사
        for (int r = 0; r < 9; ++r)
        {
            int iCell = (i / 3) * 3;
            int iPos = (iCell + r / 3);

            int jCell = (j / 3) * 3;
            int jPos = (jCell + r % 3);

            if (k == (board[iPos][jPos] - '0'))
                return false;
            if (k == (board[i][r] - '0'))
                return false;
            if (k == (board[r][j] - '0'))
                return false;
        }
        return true;
    }
    bool dfs(int cnt, vector<vector<char>>& board)
    {
        if (cnt == maxCnt)
            return true;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                //빈칸
                if (board[i][j] != '.') 
                    continue;
                for (int k = 1; k <= 9; ++k)
                {
                    if (!IsValid(i,j,k, board))
                        continue;
                        
                    board[i][j] = '0' + k;

                    if (dfs(cnt + 1, board))
                        return true;

                    board[i][j] = '.';
                    //빈칸탐색 81 
                    //유효성 27 * 81
                    //81 * 81
                }
                return false;
                
            }
        }
        return false;        
    }
};