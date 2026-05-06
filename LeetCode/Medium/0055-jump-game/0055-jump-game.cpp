class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool visit[100000] = { false };

        int last = nums.size() - 1;
        visit[last] = true;
        
        int goal = last;
        
        for (int i = last; i >= 0; --i)
        {
            if (i + nums[i] >= goal)
            {
                visit[i] = true;
                goal = i;
            }
        }   

        return visit[0];
    }
};