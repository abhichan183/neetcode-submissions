class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> used(nums.size(),false);
        dfs(nums,used,curr);
        return res;
    }
    void dfs(vector<int>& nums, vector<bool>& used,vector<int> &curr){
        if(curr.size()>=nums.size()){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            curr.push_back(nums[i]);
            used[i]=true;
            dfs(nums,used,curr);
            curr.pop_back();
            used[i]=false;
        }
    }
};
