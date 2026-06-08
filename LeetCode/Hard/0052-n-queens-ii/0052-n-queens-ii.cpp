class Solution {
public:
    int totalNQueens(int n) {
        Up.resize(n);
        Lt.resize(n * 2 - 1);
        Rb.resize(n * 2 - 1);
        dfs(0, n);
        return answer;
    }
    
    int answer = 0;
    vector<bool> Up;
    
    vector<bool> Lt;
    vector<bool> Rb;
    void dfs(int depth, int n)
    {
        if (depth == n)
        {
            ++answer;
            return;
        }
        // 3, 2 = 2, 3
        // x + y

        // 3,2 = 2,1
        
        // 3,0 = 0

        // 3,2 = 1
        // 2,1 = 1
        // 1,0 = 1

        // 0, 1 = 2
        // 1, 2 = 2
        // 2, 3 = 2

        // 0, 3 = 3
        //현재 좌표 x를 index로 변환 가능한가?
        // 0, 3 = 0
        
        // 0, 2 = 1
        // 1, 3 = 1

        // 0, 1 = 2
        // 1, 2 = 2
        // 2, 3 = 2
        
        // 0, 0 = 3
        // 1, 1 = 3
        // 2, 2 = 3

        for (int i = 0; i < n; ++i)
        {
            //현재 depth부터 둘 수있는 경우의 수
            //같은 열에 퀸이 있는지
            //좌상단에 퀸이 있는지
            //우상단에 퀸이 있는지
            if (Up[i])
                continue;
            if (Lt[depth + i])
                continue;
            if (Rb[depth - i + n - 1])
                continue;
            Up[i] = true;
            Lt[depth + i] = true;
            Rb[depth - i + n - 1] = true;
            dfs(depth + 1, n);
            Rb[depth - i + n - 1] = false;
            Lt[depth + i] = false;
            Up[i] = false;
        }
    }
};