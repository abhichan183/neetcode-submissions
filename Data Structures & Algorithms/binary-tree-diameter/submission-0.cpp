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
    int result=0;
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return result-1;
    }

    int helper(TreeNode* node){
        if(node==NULL) return 0;
        int lh=helper(node->left);
        int rh=helper(node->right);
        if(lh+rh+1>result) result=lh+rh+1;
        return 1+max(lh,rh);
    }
};