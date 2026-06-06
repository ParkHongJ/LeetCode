class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    // 2 5 5 2 5 5 1 1 1 3 5
    // 0 1 2 3 4 5 6 7 8 9 10
    // k번째 점찍기는 k - 1번의 숫자 앞에 찍는거다. 
        string ip = "";
        dfs(0, 0, ip, s);
        return answer;  
    };
    void dfs(int k, int d, string& currentIP, const string& s)
    {
         if (d == 4)
        {
            if (k == s.length())
                answer.push_back(currentIP);
            return;
        }

        for (int i = 1; i <= 3; ++i)
        {
            if (k + i > s.length())
                break;
            string strNum = s.substr(k, i); 
            if (strNum[0] == '0' && strNum.length() > 1)
                break;
            if (stoi(strNum) > 255)
                break;
            int beforeSize = currentIP.size();
            //점을 찍은 아이피
            if (!currentIP.empty())
                currentIP += '.';

            currentIP += strNum;
            
            dfs(k + i, d + 1, currentIP, s);

            //아이피 복구
            currentIP.resize(beforeSize);
        }
    };
    
    vector<string> answer;
};