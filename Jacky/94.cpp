// 解題思路：
// 偷懶用遞迴的方式

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        this->_traverse(root, ans);
        return ans;
    }
    
    private: void _traverse(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        this->_traverse(root->left, ans);
        ans.push_back(root->val);
        this->_traverse(root->right, ans);
        return;
    }
};