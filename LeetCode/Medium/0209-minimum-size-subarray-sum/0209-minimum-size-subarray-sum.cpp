class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;

        queue<int> window;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            window.push(nums[i]);

            if (sum >= target)
            {
                while (sum >= target && !window.empty())
                {
                    minLength = min(minLength, (int)window.size());
                    sum -= window.front();
                    window.pop();
                }
            }
        }
        if (minLength == INT_MAX)
            return 0;
        return minLength;
    }
};