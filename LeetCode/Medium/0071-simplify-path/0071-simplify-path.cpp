class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> s;
        for (int i = 0; i < path.length(); ++i)
        {
            string temp;
            if (path[i] == '/')
                continue;

            while (i < path.length() && path[i] != '/')
            {
                temp += path[i];
                ++i;
            }
            
            if (temp == "..")
            {
                if (!s.empty())
                    s.pop();
                continue;
            }

            if (temp != ".")
            {
                s.push(temp);
            }
        }

        string result;
        if (s.empty())
            return "/";

        while(!s.empty())
        {
            // /foo + / + home + /foo
            result = "/" + s.top() + result;
            s.pop();
            // result += s.top(); s.pop();
            // if(!s.empty())
            //     result += "/";
        }
        return result;
    }

};