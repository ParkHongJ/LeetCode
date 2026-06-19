class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int answer = 0;
        int height = 0;
        for (int i = 0; i < gain.size(); ++i)
        {
            height += gain[i];
            answer = max(answer, height);
        }
        return answer;
    }
};