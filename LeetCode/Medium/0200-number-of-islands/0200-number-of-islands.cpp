class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        bool visit[305][305] = {};
        int answer = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (visit[i][j])
                    continue;
                if (grid[i][j] == '1')
                {
                    //bfs 시작
                    bfs(grid, visit, i, j);
                    ++answer;
                }
            }
        }
        return answer;
    }
    int bfs(vector<vector<char>>& grid, bool visit[][305], int y, int x)
    {
        int answer = 0;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};

        queue<pair<int,int>> q;
        q.push({x,y});

        while(!q.empty())
        {
            pair<int,int> cur = q.front(); q.pop();

            if (visit[cur.second][cur.first])
                continue;
            
            visit[cur.second][cur.first] = true;

            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= grid[0].size() || ny < 0 || ny >= grid.size())
                    continue;
                if (visit[ny][nx])
                    continue;
                if (grid[ny][nx] == '1')
                {
                    answer = 1;
                    q.push({nx,ny});
                }
            }
        }
        return answer;
    }
};