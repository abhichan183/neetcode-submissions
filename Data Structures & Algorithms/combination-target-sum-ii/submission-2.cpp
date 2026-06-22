class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        dfs(0,target,candidates,curr);
        return res;
    }
    void dfs(int idx, int target,vector<int> nums, vector<int>& curr){
        if(target==0){
            res.push_back(curr);
            return;
        }
        if(idx>=nums.size()||target<0) return;
        for(int i=idx;i<nums.size();i++){
        if(i>idx&&nums[i]==nums[i-1]) continue;
        curr.push_back(nums[i]);
        dfs(i+1,target-nums[i],nums,curr);
        curr.pop_back();
        }
    }
};
