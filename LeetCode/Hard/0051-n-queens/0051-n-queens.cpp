class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        row.resize(n);
        col.resize(n);
        vector<string> s;
        s.resize(n);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                s[i] += '.';
            }
        }
        dfs(0, 0, n, s);

        return answer;
    }
    void dfs(int cur, int depth, int n, vector<string>& s)
    {
        //cur = 현재까지 놓은 queen의 개수
        //n = 놓아야 하는 queen의 개수
        if (cur == n)
        {
            answer.push_back(s);
            return;
        }
        
        if (row[depth])
            return;

        // 1, 2
        // 0, 3
        // 3, 0 -> 2, 1, -> 1, 2
        // 현재 좌표에서 -1, +1 , +1 -1, -1 -1, +1 +1 을 반복 했을때 상대 좌표와 같아진다면 대각선이다.
        
        // 0, 1 Q
        // 1, 0 Q

        // 2, 0 Q
        // 0, 2 Q

        // 0, 2
        // 1, 3
        
        // 1, 0
        // 3, 2

        //y축 x축에 queen을 놓을수있냐?
        for (int j = 0; j < n; ++j)
        {
            if (col[j])
                continue;

            bool canPlace = true;
            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = j + dx[dir];
                int ny = depth + dy[dir];
                
                while (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    if (s[ny][nx] == 'Q')
                    {
                        canPlace = false;
                        break;
                    }
                    nx += dx[dir];
                    ny += dy[dir];
                }
                if (!canPlace)
                    break;
            }
            if (!canPlace)
                continue;
            row[depth] = col[j] = true;
                
            s[depth][j] = 'Q';
            dfs(cur + 1, depth + 1, n, s);
            s[depth][j] = '.';

            row[depth] = col[j] = false;
        }

    }
    vector<bool> row;
    vector<bool> col;
    int dx[4] = {-1,-1,1,1};//좌상 좌하 우상 우하
    int dy[4] = {-1,1,-1,1};//좌상 좌하 우상 우하 
    vector<vector<string>> answer;
};