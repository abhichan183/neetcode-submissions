class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(),nums.end());
        dfs(0,curr,nums);
        return res;
    }
    void dfs(int idx,vector<int> &curr, vector<int> nums){
        res.push_back(curr);
        for(int i=idx;i<nums.size();i++){
            if(i>idx&&nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            dfs(i+1,curr,nums);
            curr.pop_back();
        }
    }
};
