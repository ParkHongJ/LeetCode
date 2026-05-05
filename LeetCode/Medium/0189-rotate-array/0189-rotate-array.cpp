class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        list<int> l;
        for (int i = 0; i < nums.size() - k; ++i)
        {
            l.push_back(nums[i]);
        }
        for (int i = 1; i <= k; ++i)
        {
            l.push_front(nums[nums.size() - i]);
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i] = l.front();
            l.pop_front();
        }
    }
};