class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string answer;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        reverse(alpha.begin(), alpha.end());
        for (int i = 0; i < words.size(); ++i)
        {
            string& word = words[i];
            int weightSum = 0;
            for (int j = 0; j < word.length(); ++j)
            {
                int weightIdx = word[j] - 'a';
                weightSum += weights[weightIdx];
            }
            weightSum %= 26;
            answer += alpha[weightSum];
        }
        return answer;
    }
};