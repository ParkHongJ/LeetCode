class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        
        visit.resize(grid.size(), vector<bool>(grid[0].size()));

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 0)
                    continue;
                dfs(j, i, grid, 0);
            }
        }
        return maxGold;
    }
    void dfs(int x, int y, vector<vector<int>>& grid, int gold)
    {
        bool bMove = false;
        int curGold = gold + grid[y][x];
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= grid[0].size() ||
                ny < 0 || ny >= grid.size() ||
                grid[ny][nx] == 0 || visit[ny][nx])
            {
                continue;
            }
            bMove = true;
            visit[y][x] = true;
            dfs(nx,ny,grid, curGold);
            visit[y][x] = false;
        }

        if (!bMove)
        {
            //갈수있는곳이 없다.
            maxGold = max(maxGold, curGold);
        }
    }
    int maxGold = 0;
    vector<vector<bool>> visit;

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
};