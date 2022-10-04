# 原题链接

https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/

# 方法1:深度遍历

```c++
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
    vector<vector<int>> ret;
    vector<int> path;
public:
    void dfs(TreeNode* root, int target)
    {
        if(!root)
            return;
        
        path.push_back(root->val);
        if(target == root->val && root->left == nullptr && root->right == nullptr)
        {
            ret.push_back(path);
        }
        dfs(root->left,target - root->val);
        dfs(root->right,target - root->val);
        path.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root,target);

        return ret;
    }
};
```

