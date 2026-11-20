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
    pair<int,int> dfs(TreeNode* root, bool& isValid){
        if(!root){
            return {INT_MIN,INT_MAX};
        }
        pair<int,int> left = dfs(root->left, isValid);
        if(!isValid){
            return {0,0};
        }
        pair<int,int> right = dfs(root->right, isValid);
        if(!isValid){
            return {0,0};
        }

        if(root->val <= left.first || root->val >= right.second){
            isValid = false;
            return {0,0};
        }
        int minVal = min(root->val,left.second);
        int maxVal = max(root->val, right.first);
        return{maxVal,minVal};
    }
    
    bool isValidBST(TreeNode* root) {
        bool isValid = true;
        dfs(root,isValid);
        return isValid;
    }
};
