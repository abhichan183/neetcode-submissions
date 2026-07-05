class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        if(sum%2==1) return false;
        vector<vector<int>> dp(nums.size(),vector<int>((sum/2)+1,-1)); 
        return solve(nums,0,sum/2,dp);
    }
    bool solve(vector<int>& nums,int i,int target,vector<vector<int>>& dp){
        if(target==0) return true;
        if(target<0) return false;
        if(i==nums.size()) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        return dp[i][target]=solve(nums,i+1,target-nums[i],dp)||solve(nums,i+1,target,dp);
    }
};