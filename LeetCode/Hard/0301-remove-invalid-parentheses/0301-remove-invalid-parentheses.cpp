class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        dfs(0, s);
        vector<string> ans;
        for (auto& iter : answer)
        {
            ans.push_back(iter);
        }
        return ans;
    }
    set<string> answer;
    set<string> visited;
    int temp = INT_MAX;
    void dfs(int depth, const string& s)
    {
        if (depth > temp)
            return;
        if (visited.count(s))
            return;
        visited.insert(s);
        stack<char> st;
        bool isValid = true;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
                st.push(s[i]);
            if (s[i] == ')')
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else
                {
                    isValid = false;
                    break;
                }
            }
                
        }
        if (!st.empty())
            isValid = false;

        if (isValid) //문자열 s가 유효한 문자열이라면
        {
            if (depth < temp)
            {
                temp = depth;
                answer.clear();
            }
            answer.insert(s);
            return;
        }
        //i번째 글자를 빼겠다
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != '(' && s[i] != ')')
                continue;
            string left = s.substr(0, i);
            string right = s.substr(i + 1, s.length() - (i + 1));
            dfs(depth + 1, left + right);
        }
    }
};