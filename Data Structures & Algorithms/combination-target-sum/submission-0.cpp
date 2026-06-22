class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        dfs(curr,nums,target,0);
        return res;
    }
    void dfs(vector<int>& curr,vector<int>& nums,int target,int idx){
        if(target==0){
            res.push_back(curr);
            return;
        }
        if(idx==nums.size()||target<0){
            return;
        }
        curr.push_back(nums[idx]);
        dfs(curr,nums,target-nums[idx],idx);
        curr.pop_back();
        dfs(curr,nums,target,idx+1);
    }
};
