/*
* File name: 94 ���������������
* Author: ycli
* Version:1.0
* Date: 2022/8/13
* Description:����һ���������ĸ��ڵ� root ������ ���� ���� ���� ��
* 
* ʾ��
* ���룺root = [1,null,2,3]
* �����[1,3,2]
* 
* ���룺root = []
* �����[]
* 
* ���룺root = [1]
* �����[1]
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

// ʹ��ѭ������
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> s; // �������ڵ��ջ
        vector<int> v; // �������
        while (root != NULL || !s.empty()) {
            // ���������������Ľڵ�ѹ��ջ
            for (; root != NULL; root = root->left)
                s.push_back(root);
            // ��ջ��Ԫ����ӵ������������
            v.push_back(s.back()->val);
            // ָ��ǰ�ڵ��������,�������������������
            root = s.back()->right;
            // ����ջ��Ԫ��
            s.pop_back();
        }
        return v;
    }
};

// ʹ�õݹ鷽��
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
