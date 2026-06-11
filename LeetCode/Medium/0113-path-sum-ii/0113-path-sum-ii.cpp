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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return answer;
    }
    vector<vector<int>> answer;
    vector<int> path;
    void dfs(TreeNode* root, int cur, const int targetSum)
    {
        if (root == nullptr)
            return;

        path.push_back(root->val);

        if (cur + root->val == targetSum && root->left == nullptr && root->right == nullptr)
        {
            answer.push_back(path);
            path.pop_back();
            return;
        }
        if (root->left)
        {
            dfs(root->left, cur + root->val, targetSum);
        }
        if (root->right)
        {
            dfs(root->right, cur + root->val, targetSum);
        }
        path.pop_back();
    }
};