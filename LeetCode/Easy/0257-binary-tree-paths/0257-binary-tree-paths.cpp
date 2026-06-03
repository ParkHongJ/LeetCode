/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        path += to_string(root->val);
        dfs(root, answer);
        return answer;
    }
    string path;
    void dfs(TreeNode* node, vector<string>& answer)
    {
        if (node == nullptr)
            return;
        
        if (node->left == nullptr && node->right == nullptr)
            answer.push_back(path);

        if (node->left)
        {
            int pathLen = path.length();
            path += "->" + to_string(node->left->val);
            dfs(node->left, answer);
            int cnt = path.length() - pathLen;
            for (int i = 0; i < cnt; ++i)
                path.pop_back();
        }
        if (node->right)
        {
            int pathLen = path.length();
            path += "->" + to_string(node->right->val);
            dfs(node->right, answer);
            int cnt = path.length() - pathLen;
            for (int i = 0; i < cnt; ++i)
                path.pop_back();
        }
        
    }
};