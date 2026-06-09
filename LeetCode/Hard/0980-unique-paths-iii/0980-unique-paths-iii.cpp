class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        //모든 경로를 한번씩 지나면서 목적지에 도착하는 경우의 수
        int x = 0, y = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    x = j; y = i;
                }
                if (grid[i][j] != -1)
                    ++maxCnt;
            }
        }

        visit.resize(grid.size(), vector<bool>(grid[0].size()));

        dfs(x, y, 1, grid);
        return answer;
    }
    vector<vector<bool>> visit;
    int answer = 0;
    int maxCnt = 0;
    void dfs(int x, int y, int cnt, const vector<vector<int>>& grid)
    {
        if (grid[y][x] == 2 && cnt == maxCnt)
        {
            //goal
            ++answer;
            return;
        }
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!InGrid(nx,ny,grid))
                continue;
            if (visit[ny][nx] || grid[ny][nx] == -1)
                continue;
            
            visit[y][x] = true;
            dfs(nx,ny, cnt + 1, grid);
            visit[y][x] = false;
        }
    }

    bool InGrid(int x, int y, const vector<vector<int>>& grid)
    {
        if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size())
            return false;
        return true;
    }
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
};