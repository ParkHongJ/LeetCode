class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        dfs(0, nums);
        return answer;
    }

    bool visit[12] = {};
    int answer = 0;
    list<int> v;
    void dfs(int d, vector<int>& nums)
    {
        for (int i = d; i < nums.size(); ++i)
        {
            if (visit[i] == false)
            {
                visit[i] = true;
                v.push_back(nums[i]);
                
                int x = 0;

                for (int n : v)
                    x ^= n;

                answer += x;

                dfs(i, nums);

                v.pop_back();
                visit[i] = false;
            }
        }
    }
};