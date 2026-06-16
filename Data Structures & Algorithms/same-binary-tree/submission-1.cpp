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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while(!(q1.empty())&&!(q2.empty())){
            int size1=q1.size();
            int size2=q2.size();
            if(size1!=size2) return false;
            for(int i=0;i<size1;i++){
                TreeNode* temp1=q1.front(); q1.pop();
                TreeNode* temp2=q2.front(); q2.pop();
                if(!temp1&&!temp2) continue;
                if(!temp1||!temp2) return false;
                if(temp1->val!=temp2->val) return false;
                q1.push(temp1->left);
                q2.push(temp2->left);
                q1.push(temp1->right);
                q2.push(temp2->right);                
            }
        }
        if(!q1.empty()||!q2.empty()) return false;
        return true;
    }
};
