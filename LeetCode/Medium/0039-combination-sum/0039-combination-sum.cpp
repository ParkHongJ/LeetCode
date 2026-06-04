class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        dfs(0,0, candidates);
        return answer;
    }
    int target = 0;
    list<int> l;
    vector<vector<int>> answer;
    void dfs(int sum, int d, vector<int>& candidates)
    {
        //d는 현재 숫자의 합
        if (sum == target)
        {
            vector<int> v;
            for (auto& iter : l)
            {
                v.push_back(iter);
            }
            
            answer.push_back(move(v));
            return;
        }

        for (int i = d; i < candidates.size(); ++i)
        {
            if (sum + candidates[i] > target)
                continue;

            l.push_back(candidates[i]);
            dfs(sum + candidates[i], i, candidates);
            l.pop_back();
        }
    }
};