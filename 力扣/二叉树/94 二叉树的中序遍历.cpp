/*
* File name: 94 二叉树的中序遍历
* Author: ycli
* Version:1.0
* Date: 2022/8/13
* Description:给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
* 
* 示例
* 输入：root = [1,null,2,3]
* 输出：[1,3,2]
* 
* 输入：root = []
* 输出：[]
* 
* 输入：root = [1]
* 输出：[1]
* 
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

// 使用循环方法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> s; // 保存树节点的栈
        vector<int> v; // 中序遍历
        while (root != NULL || !s.empty()) {
            // 将所有有左子树的节点压入栈
            for (; root != NULL; root = root->left)
                s.push_back(root);
            // 将栈顶元素添加到中序遍历序列
            v.push_back(s.back()->val);
            // 指向当前节点的右子树,对右子树进行中序遍历
            root = s.back()->right;
            // 弹出栈顶元素
            s.pop_back();
        }
        return v;
    }
};

// 使用递归方法
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
