class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        dfs(0, turnedOn);
        return answer;
    }
    
    bool visit[10] = { false };
    vector<string> answer;
    void dfs(int d, int turnedOn)
    {
        if (turnedOn <= 0)
        {
            int hour = 0, min = 0;
            for (int i = 0; i < 4; ++i)
            {
                if (!visit[i])
                    continue;
                hour += 1 << (3 - i);
            }
            for (int i = 0; i < 6; ++i)
            {
                if (!visit[i + 4])
                    continue;

                min += 1 << (5 - i);
            }
            
            if (hour > 11 || min > 59)
                return;
            string time;
            
            if (min < 10)
                time = to_string(hour) + ":0" + to_string(min);
            else 
                time = to_string(hour) + ":" + to_string(min);

            answer.push_back(time);
            return;
        }

        for (int i = d; i < 10; ++i)
        {
            if (visit[i])
                continue;
            visit[i] = true;
            dfs(i, turnedOn - 1); // 현재 i를 켰고 남은 led의 수
            visit[i] = false;
        }        
    }
};