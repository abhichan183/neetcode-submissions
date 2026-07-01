class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int n=nums.size();
        return rec(nums,dp,0);
    }
    int rec(vector<int> &nums,vector<int>& dp,int i){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+rec(nums,dp,i+2),rec(nums,dp,i+1));
    }
};
