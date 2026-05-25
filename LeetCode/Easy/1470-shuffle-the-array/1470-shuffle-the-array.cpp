class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0, j = 1;
        vector<int> answer;
        answer.resize(2*n);
        while(i < n && j < 2*n)
        {
            answer[i * 2] = nums[i];
            answer[j] = nums[n + i];
            ++i;
            j += 2;
        }
        return answer;
    }
};