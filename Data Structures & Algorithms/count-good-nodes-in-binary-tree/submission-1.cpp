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
    int count =0;
    int goodNodes(TreeNode* root) {
       if(!root) return 0;
       int max=root->val;
       number(root,max);
       return count;
    }
    void number(TreeNode* root,int max){
        if(!root) return;
        if(max<=root->val){
            max=root->val;
            count+=1;
        }
        number(root->left,max);
        number(root->right,max);
    }
};
