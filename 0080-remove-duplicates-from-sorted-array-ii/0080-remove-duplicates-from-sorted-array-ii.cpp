class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pivot = nums[0];
        int cnt = 1;
        int removelength = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (pivot != nums[i])
            {
                pivot = nums[i];
                cnt = 1;
                continue;
            }

            ++cnt;
            if (cnt > 2)
            {
                nums[i] = INT_MAX;
                ++removelength;
            }
        }
        sort(nums.begin(), nums.end());
        return nums.size() - removelength;
    }
};